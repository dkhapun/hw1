#include "datastruct.h"
using namespace avl_tree;

GohooApps::GohooApps()
{

}

/* Description:   Destructor
*/
GohooApps::~GohooApps()
{

}
StatusType GohooApps::AddVersion(int versionCode)
{
	if (!versionsList.empty() && (*versionsList.end()).versionCode >= versionCode)
		return GO_ERR_ILLIGAL_VERSION;
	
	if (!versionsList.empty() && (*versionsList.end()).versionCode < versionCode)
		versionsList.insert(versionsList.begin(), VersionData(versionCode));

	return SUCCESS;
}

StatusType GohooApps::AddApplication(int appID, int versionCode, int downloadCount)
{
	AppData appData(appID, versionCode, downloadCount);
	if (0 == appsTree.insert(appData))
		return GO_ERR_ALREADY_EXISTS;

	AddApplicationToVersionList(appData);
	return SUCCESS;
}

StatusType GohooApps::AddApplicationToVersionList(const AppData& myApp)
{
	if (0 != AddVersion(myApp.versionCode))
		return INVALID_INPUT;

	VersionData* vdata = versionsList.find(myApp.versionCode);
	DownloadData* ddata = vdata->downloadsTree.insert(DownloadData(myApp.downloadCount));
	ddata->appsTree.insert(myApp);
	return SUCCESS;
}

StatusType GohooApps::RemoveApplication(int appID)
{
	AppData myApp = *(appsTree.find(appID));	//get a copy
	if (myApp == 0)
		return SUCCESS;

	//remove the app from the main tree
	appsTree.remove(appID);
	AVLTree<DownloadData, int>& downTree = versionsList.find(myApp.versionCode)->downloadsTree;
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
	AVLTree<DownloadData, int>& downTree = versionsList.find(myApp->versionCode)->downloadsTree;
	downTree.find(myApp->downloadCount)->appsTree.remove(appID);
	myApp->downloadCount += downloadIncrease;
	AddApplicationToVersionList(*myApp);
}
StatusType GohooApps::UpgradeApplication(int appID)
{
	return SUCCESS;
}
StatusType GohooApps::GetTopApp(int versionCode, int *appID)
{
	return SUCCESS;
}
StatusType GohooApps::GetAllAppsByDownloads(int versionCode, int **apps, int *numOfApps)
{
	return SUCCESS;
}
StatusType GohooApps::UpdateDownloads(int groupBase, int multiplyFactor)
{
	return SUCCESS;
}