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
		*pcount += downData.mAppsTree.size();
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
		downData.mAppsTree.forEachInorder(getOneId);
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

GohooApps::StatusType GohooApps::AddVersion(int versionCode)
{
	GohooApps::StatusType res = FAILURE;
	if (!mVersionsList.empty() && (*mVersionsList.end()).versionCode >= versionCode)
		res = FAILURE;
	
	if (mVersionsList.empty() || (!mVersionsList.empty() && (*mVersionsList.end()).versionCode < versionCode))
	{
		mVersionsList.insert(mVersionsList.begin(), VersionData(versionCode));
		res = SUCCESS;
	}
	return res;
}

GohooApps::StatusType GohooApps::AddApplication(int appID, int versionCode, int downloadCount)
{
	AppData appData(appID, versionCode, downloadCount);
	if (0 == mAppsTree.insert(appData))
		return GO_ERR_ALREADY_EXISTS;

	addAppToVersionList(appData);
	addAppToDownloadTree(mDownloadsTree, appData);
	return SUCCESS;
}



GohooApps::StatusType GohooApps::RemoveApplication(int appID)
{
	AppData myApp = *(mAppsTree.find(appID));
	if (myApp == 0)
		return SUCCESS;

	//remove the app from the main tree
	mAppsTree.remove(appID);
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp.versionCode)->mDownloadsTree;
	removeAppFromDownloadTree(downTree, myApp);
	removeAppFromDownloadTree(mDownloadsTree, myApp);
	return SUCCESS;
}

GohooApps::StatusType GohooApps::IncreaseDownloads(int appID, int downloadIncrease)
{
	AppData* myApp = mAppsTree.find(appID);	//get a copy
	if (myApp == 0)
		return GO_ERR_APP_NOT_FOUND;

	//remove from downloads tree
	
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp->versionCode)->mDownloadsTree;
	removeAppFromDownloadTree(downTree, *myApp);
	removeAppFromDownloadTree(mDownloadsTree, *myApp);
	
	myApp->downloadCount += downloadIncrease;	//will update main tree

	addAppToVersionList(*myApp);
	addAppToDownloadTree(mDownloadsTree, *myApp);

	return SUCCESS;
}

GohooApps::StatusType GohooApps::UpgradeApplication(int appID)
{
	AppData* myApp = mAppsTree.find(appID);	//get a copy
	if (myApp == 0)
		return GO_ERR_APP_NOT_FOUND;

	int newVer = getNextVersion(myApp->versionCode);
	if (newVer == -1)
		return GO_ERR_BAD_VERSION;
	
	//remove from downloads tree
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(myApp->versionCode)->mDownloadsTree;
	removeAppFromDownloadTree(downTree, *myApp);
	removeAppFromDownloadTree(mDownloadsTree, *myApp);

	myApp->versionCode = newVer;

	addAppToVersionList(*myApp);
	addAppToDownloadTree(mDownloadsTree, *myApp);
	return SUCCESS;
}

GohooApps::StatusType GohooApps::GetTopApp(int versionCode, int *appID)
{
	*appID = -1;
	if (mVersionsList.empty() || mAppsTree.empty())
		return FAILURE;

	ListIter<VersionData> maxNode = mVersionsList.begin();
	AppData* maxApp = 0;
	AppData* tempApp = 0;
	if (versionCode < 0)
	{
		*appID = mDownloadsTree.max()->mAppsTree.min()->appId;
	}
	else
	{
		VersionData* verData = mVersionsList.find(versionCode);
		
		if (verData == 0)
			return FAILURE;

		if (!verData->mDownloadsTree.empty())
		{
			maxApp = (*maxNode).mDownloadsTree.max()->mAppsTree.min();
		}
	}
	if (maxApp != 0)
	{
		*appID = maxApp->appId;
	}
	return SUCCESS;
}

GohooApps::StatusType GohooApps::GetAllAppsByDownloads(int versionCode, int **apps, int *numOfApps)
{
	/*check input*/
	if(versionCode == 0 || apps == NULL || numOfApps == NULL)
	{
		return INVALID_INPUT;
	}

	AVLTree<DownloadData, int>* pmDownloadsTree;
	if(versionCode < 0)
	{
		/*all apps*/
		pmDownloadsTree = &mDownloadsTree;
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
		pmDownloadsTree = &pdata->mDownloadsTree;
	}
	/*count the apps (go over downloads tree)*/
	*numOfApps = 0;
	AddAppCount addCount(numOfApps); /*create functor*/
	pmDownloadsTree->forEachInorder(addCount);
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
	pmDownloadsTree->forEachInorderReverse(getIds);

	return SUCCESS;
}
GohooApps::StatusType GohooApps::UpdateDownloads(int groupBase, int multiplyFactor)
{
	return SUCCESS;
}

/*private
********************/
GohooApps::StatusType GohooApps::addAppToVersionList(const AppData& myApp)
{
	VersionData* vdata = mVersionsList.find(myApp.versionCode);
	if (vdata == 0)
		return FAILURE;
	addAppToDownloadTree(vdata->mDownloadsTree, myApp);
	return SUCCESS;
}

GohooApps::StatusType GohooApps::addAppToDownloadTree(AVLTree<DownloadData, int>& tree, const AppData& myApp)
{
	DownloadData* ddata = tree.insert(DownloadData(myApp.downloadCount));
	//if there already a node with the downloads number
	if (ddata == 0)
	{
		ddata = tree.find(DownloadData(myApp.downloadCount));
	}
	ddata->mAppsTree.insert(myApp);
	return SUCCESS;
}

GohooApps::StatusType GohooApps::removeAppFromDownloadTree(avl_tree::AVLTree<DownloadData, int>& tree, const AppData& myApp)
{
	AVLTree<AppData, int>& downAppTree = tree.find(myApp.downloadCount)->mAppsTree;

	//remove the app from the downloads tree and if there are no apps under the download count, remove it too 
	downAppTree.remove(myApp.appId);
	if (downAppTree.empty())
		tree.remove(myApp.downloadCount);
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