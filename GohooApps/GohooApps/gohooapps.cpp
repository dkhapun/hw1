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
class UpdateAppDownloads
{
public:
	UpdateAppDownloads(int base, int factor) : 
	groupBase(base), multiplyFactor(factor)
	{
	}
	void operator() (AppData& appData)
	{
		/*update if matches groupBase*/
		if(appData.appId % groupBase == 0)
		{
			appData.downloadCount *= multiplyFactor;
		}
	}
private:
	int groupBase;
	int multiplyFactor;
};
class GetOneAppData
{
public:
	GetOneAppData(List<AppData>* p1, List<AppData>* p2, int base) 
	: 
	plist1(p1),
	plist2(p2),
	groupBase(base)
	{
	}
	void operator() (AppData const& appData)
	{
		/*list1 if in groupBase*/
		if(appData.appId % groupBase == 0)
		{
			plist1->insert(plist1->end(), appData);
		}
		else /*list2 other wise*/
		{
			plist2->insert(plist2->end(), appData);
		}
	}
private:
	List<AppData>* plist1;
	List<AppData>* plist2; 
	int groupBase;
};
class GetAppDatas
{
public:
	GetAppDatas(List<AppData>* p1, List<AppData>* p2, int base) 
	: 
	plist1(p1),
	plist2(p2),
	groupBase(base)
	{
	}
	void operator() (DownloadData& downData)
	{
		/*create functor*/
		GetOneAppData getOneApp(plist1, plist2, groupBase);
		/*go over app ids in increasing order*/
		downData.mAppsTree.forEachInorder(getOneApp);
	}
private:
	List<AppData>* plist1;
	List<AppData>* plist2; 
	int groupBase;
};


/***************************************************************************
** GohooApps implementation
****************************************************************************/
GohooApps::GohooApps()
{

}

GohooApps::~GohooApps()
{

}

GohooApps::StatusType GohooApps::AddVersion(int versionCode)
{
	/*check input*/
	if(versionCode <= 0)
	{
		return INVALID_INPUT;
	}

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
	/*check input*/
	if(appID <= 0 || versionCode <= 0)
	{
		return INVALID_INPUT;
	}

	if(mAppsTree.find(appID) != 0)
	{
		return GO_ERR_ALREADY_EXISTS;
	}

	AppData appData(appID, versionCode, downloadCount);
	if(addAppToVersionList(appData) == FAILURE)
	{
		return GO_ERR_ILLIGAL_VERSION;
	}

	if (0 == mAppsTree.insert(appData))
		return GO_ERR_ALREADY_EXISTS;

	addAppToDownloadTree(mDownloadsTree, appData);
	return SUCCESS;
}



GohooApps::StatusType GohooApps::RemoveApplication(int appID)
{
	/*check input*/
	if(appID <= 0)
	{
		return INVALID_INPUT;
	}

	AppData* pmyApp = mAppsTree.find(appID);
	if (pmyApp == 0)
		return GO_ERR_APP_NOT_FOUND;

	//remove the app from the main tree
	mAppsTree.remove(appID);
	AVLTree<DownloadData, int>& downTree = mVersionsList.find(pmyApp->versionCode)->mDownloadsTree;
	removeAppFromDownloadTree(downTree, *pmyApp);
	removeAppFromDownloadTree(mDownloadsTree, *pmyApp);
	return SUCCESS;
}

GohooApps::StatusType GohooApps::IncreaseDownloads(int appID, int downloadIncrease)
{
	/*check input*/
	if(appID <= 0 || downloadIncrease <= 0)
	{
		return INVALID_INPUT;
	}

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
	/*check input*/
	if(appID <= 0)
	{
		return INVALID_INPUT;
	}

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
	/*check input*/
	if(appID == NULL || versionCode == 0)
	{
		return INVALID_INPUT;
	}

	*appID = -1;

	AppData* maxApp = 0;
	if (versionCode < 0)
	{
		if(!mDownloadsTree.empty())
		{
			/*(a node cannot have empty mAppsTree)*/
			*appID = mDownloadsTree.max()->mAppsTree.min()->appId;
		}
	}
	else
	{
		VersionData* verData = mVersionsList.find(versionCode);
		
		if (verData == 0)
			return FAILURE;

		if (!verData->mDownloadsTree.empty())
		{
			maxApp = (*verData).mDownloadsTree.max()->mAppsTree.min();
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

	AVLTree<DownloadData, int>* pdownloadsTree;
	if(versionCode < 0)
	{
		/*all apps*/
		pdownloadsTree = &mDownloadsTree;
	}
	else
	{
		/*apps of specific version*/
		VersionData* pverData = mVersionsList.find(versionCode);
		if(pverData == NULL)
		{
			/*version not found*/
			*numOfApps = 0;
			*apps = NULL;
			return SUCCESS;
		}
		pdownloadsTree = &pverData->mDownloadsTree;
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
GohooApps::StatusType GohooApps::UpdateDownloads(int groupBase, int multiplyFactor)
{
	/*check input*/
	if(groupBase < 1 || multiplyFactor <= 0)
	{
		return INVALID_INPUT;
	}
	
	/*update appsTree*/
	UpdateAppDownloads updateApp(groupBase, multiplyFactor);
	mAppsTree.forEachInorder(updateApp);

	/*for each version update its downloads tree*/
	for(ListIter<VersionData> iter = mVersionsList.begin(); iter != NULL; 
		++iter)
	{
		updateDownloadsTree(groupBase, multiplyFactor, 
			iter->mDownloadsTree);
	}
	
	/*update the main downloads tree*/
	updateDownloadsTree(groupBase, multiplyFactor, mDownloadsTree);

	return SUCCESS;
}

/*private
********************/
#include <iostream>
using namespace std;
GohooApps::StatusType GohooApps::updateDownloadsTree(int groupBase, int multiplyFactor, 
	AVLTree<DownloadData, int>& downloadsTree)
{
	/*create 2 ordered lists of "AppData" (ordered by downloads and secondary by id)
	* list1 - all the apps that match the groupBase
	* list2 - the rest*/
	List<AppData> list1;
	List<AppData> list2;
	GetAppDatas getApps(&list1, &list2, groupBase); /*create functor*/
	downloadsTree.forEachInorder(getApps);

	/*multiply the download counts in list1*/
	for(ListIter<AppData> iter = list1.begin(); iter != NULL; 
			++iter)
	{
		iter->downloadCount *= multiplyFactor;
	}
	
	/*merge the two lists, keeping order like said above 
	(operator < is overloaded for "AppData")*/
	list2.merge(list1);
	
	/*split the list to lists 
	 so that "AppData" with equal download count are in the same list*/
	List<List<AppData> > listOfLists;
	ListIter<List<AppData> > iterOfLists = NULL;
	int prevCount = -1;
	for(ListIter<AppData> iter = list2.begin(); iter != NULL; ++iter)
	{
		if(iter->downloadCount != prevCount)
		{
			/*add an empty list*/
			iterOfLists = listOfLists.insert(listOfLists.end(), List<AppData>());
		}
		/*insert current appData to end of current list*/
		iterOfLists->insert(iterOfLists->end(), *iter);
		prevCount = iter->downloadCount;
	}
	
	/*convert each (ordered) list to "DownloadData"*/
	List<DownloadData> downDataList;
	for(iterOfLists = listOfLists.begin(); iterOfLists != NULL; ++iterOfLists)
	{
		/*get the download count of current list (from first member)*/
		int downloadCount = iterOfLists->begin()->downloadCount;
		/*insert download data, with apps*/
		downDataList.insert(downDataList.end(), 
			DownloadData(downloadCount, *iterOfLists));
	}
	
	/*convert the (ordered) list of "DownloadData" to a tree*/
	downloadsTree = AVLTree<DownloadData, int>(downDataList);
cout << endl << "printing";
//mDownloadsTree.display(1);
//mAppsTree.display(1);
downloadsTree.display(1);
cout << endl;
	return SUCCESS;
}

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
	if (downAppTree.find(myApp.appId) != 0)
	{
		downAppTree.remove(myApp.appId);
		if (downAppTree.empty())
			tree.remove(myApp.downloadCount);
	}
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