#include "gohooapps.h"
using namespace avl_tree;

/*functors for internal use
**************************/
class AddAppCount
{
public:
	AddAppCount(int* pcnt) : pcount(pcnt)
	{
	}
	void operator() (DownloadData const& downData)
	{
		/*add size of appTree to the count*/
		*pcount += downData.appsTree.size();
	}
private:
	int* pcount;
};
class GetOneAppId
{
public:
	GetOneAppId(int** pposition) : ppos(pposition)
	{
	}
	void operator() (AppData const& appData)
	{
		/*set member in array to the app id*/
		**ppos = appData.appId;
		/*point to next array slot*/
		++(*ppos);
	}
private:
	int** ppos;
};
class GetAppIds
{
public:
	GetAppIds(int** pposition) : ppos(pposition)
	{
	}
	void operator() (DownloadData& downData)
	{
		/*create functor*/
		GetOneAppId getOneId(ppos);
		/*go over app ids in increasing order*/
		downData.appsTree.forEachInorder(getOneId);
	}
private:
	int** ppos;
};

/*GohooApps implementation
********************************/
GohooApps::GohooApps()
{

}

GohooApps::~GohooApps()
{

}

StatusType GohooApps::AddVersion(int versionCode)
{
	if (!mVersionsList.empty() && (*mVersionsList.end()).versionCode >= versionCode)
		return GO_ERR_ILLIGAL_VERSION;
	
	if (!mVersionsList.empty() && (*mVersionsList.end()).versionCode < versionCode)
		mVersionsList.insert(mVersionsList.begin(), VersionData(versionCode));

	return SUCCESS;
}

StatusType GohooApps::AddApplication(int appID, int versionCode, int downloadCount)
{
	AppData appData(appID, versionCode, downloadCount);
	if (0 == appsTree.insert(appData))
		return GO_ERR_ALREADY_EXISTS;

	addApplicationToVersionList(appData);
	return SUCCESS;
}



StatusType GohooApps::RemoveApplication(int appID)
{
	AppData myApp = *(appsTree.find(appID));
	if (myApp == 0)
		return SUCCESS;

	//remove the app from the main tree
	appsTree.remove(appID);
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp.versionCode)->downloadsTree;
	AVLTree<AppData, int>& downAppTree = downTree.find(myApp.downloadCount)->appsTree;

	//remove the app from the downloads tree and if there are no apps under the download count, remove it too 
	downAppTree.remove(appID);
	if (downAppTree.empty())
		downTree.remove(myApp.downloadCount);
	return SUCCESS;
}

StatusType GohooApps::IncreaseDownloads(int appID, int downloadIncrease)
{
	AppData* myApp = appsTree.find(appID);	//get a copy
	if (myApp == 0)
		return GO_ERR_APP_NOT_FOUND;

	//remove from downloads tree
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp->versionCode)->downloadsTree;
	downTree.find(myApp->downloadCount)->appsTree.remove(appID);
	
	myApp->downloadCount += downloadIncrease;	//will update main tree
	addApplicationToVersionList(*myApp);
	return SUCCESS;
}

StatusType GohooApps::UpgradeApplication(int appID)
{
	AppData* myApp = appsTree.find(appID);	//get a copy
	if (myApp == 0)
		return GO_ERR_APP_NOT_FOUND;

	int newVer = getNextVersion(myApp->versionCode);
	if (newVer == -1)
		return GO_ERR_BAD_VERSION;
	
	//remove from downloads tree
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp->versionCode)->downloadsTree;
	downTree.find(myApp->downloadCount)->appsTree.remove(appID);

	myApp->versionCode = newVer;
	addApplicationToVersionList(*myApp);

	return SUCCESS;
}

StatusType GohooApps::GetTopApp(int versionCode, int *appID)
{
	*appID = -1;
	if (mVersionsList.empty())
		return FAILURE;

	ListIter<VersionData> maxNode = mVersionsList.begin();
	AppData* maxApp = 0;
	AppData* tempApp = 0;
	if (versionCode < 0)
	{
		//find fist non empty downloads tree
		for (maxNode = mVersionsList.begin(); maxNode != mVersionsList.end() && (!(*maxNode).downloadsTree.empty()); ++maxNode);
		if (maxNode == mVersionsList.end())
			return SUCCESS;

		maxApp = (*maxNode).downloadsTree.max()->appsTree.min();
		
		for (; maxNode != mVersionsList.end(); ++maxNode)
		{
			if (!(*maxNode).downloadsTree.empty())
			{
				tempApp = (*maxNode).downloadsTree.max()->appsTree.min();
				if (tempApp != 0 && maxApp->downloadCount < tempApp->downloadCount)
				{
					maxApp = tempApp;
				}
			}
		}
	}
	else
	{
		VersionData* verData = mVersionsList.find(versionCode);
		
		if (verData == 0)
			return FAILURE;

		if (!verData->downloadsTree.empty())
		{
			maxApp = (*maxNode).downloadsTree.max()->appsTree.min();
		}
	}
	if (maxApp != 0)
	{
		*appID = maxApp->appId;
	}
	return SUCCESS;
}

StatusType GohooApps::GetAllAppsByDownloads(int versionCode, int **apps, int *numOfApps)
{
	/*check input*/
	if(versionCode == 0 || apps == NULL || numOfApps == NULL)
	{
		return INVALID_INPUT;
	}

	AVLTree<DownloadData, int>* pdownloadsTree;
	if(versionCode < 0)
	{
		/*all apps*/
		pdownloadsTree = &downloadsTree;
	}
	else
	{
		/*apps of specific version*/
		VersionData* pdata = mVersionsList.find(versionCode);
		if(pdata == NULL)
		{
			/*version not found*/
			*numOfApps = 0;
			*apps = NULL;
			return SUCCESS;
		}
		pdownloadsTree = &pdata->downloadsTree;
	}
	/*count the apps (go over downloads tree)*/
	*numOfApps = 0;
	AddAppCount addCount(numOfApps); /*create functor*/
	pdownloadsTree->forEachInorder(addCount);
	/*malloc array for app ids*/
	if(numOfApps > 0)
	{
		*apps = (int*)malloc(((unsigned)numOfApps)*sizeof(int));
		if(*apps == NULL)
		{
			return ALLOCATION_ERROR;
		}
	}
	else /*numOfApps == 0*/
	{
		*apps = NULL;
		return SUCCESS;
	}
	/*go over downloads tree (in decreasing order) to get the app ids*/
	int* position = *apps; /*init position to start of array*/
	GetAppIds getIds(&position); /*create functor*/
	pdownloadsTree->forEachInorderReverse(getIds);

	return SUCCESS;
}
StatusType GohooApps::UpdateDownloads(int groupBase, int multiplyFactor)
{
	return SUCCESS;
}

/*private
********************/
StatusType GohooApps::addApplicationToVersionList(const AppData& myApp)
{
	if (0 != AddVersion(myApp.versionCode))
		return INVALID_INPUT;

	VersionData* vdata = mVersionsList.find(myApp.versionCode);
	DownloadData* ddata = vdata->downloadsTree.insert(DownloadData(myApp.downloadCount));
	ddata->appsTree.insert(myApp);
	return SUCCESS;
}

int GohooApps::getNextVersion(int curVersion)
{
	int res = -1;
	ListIter<VersionData> i;
	for (i = mVersionsList.begin(); i != mVersionsList.end() && (*i).versionCode != curVersion; ++i);

	if (i != mVersionsList.end())
	{
		++i;
		res = (*i).versionCode;
	}
	return res;
}