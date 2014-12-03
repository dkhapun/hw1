#include "library1.h"
#include "gohooapps.h"

void* Init()
{
	return new GohooApps();
}

StatusType AddVersion(void *DS, int versionCode)
{
	GohooApps* ds = (GohooApps*)DS;
	int res = (int)ds->AddVersion(versionCode);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}


StatusType AddApplication(void *DS, int appID, int versionCode, int downloadCount)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->AddApplication(appID, versionCode, downloadCount);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}


StatusType RemoveApplication(void *DS, int appID)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->RemoveApplication(appID);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}
StatusType IncreaseDownloads(void *DS, int appID, int downloadIncrease)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->IncreaseDownloads(appID, downloadIncrease);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}

StatusType UpgradeApplication(void *DS, int appID)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->UpgradeApplication(appID);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}

StatusType GetTopApp(void *DS, int versionCode, int *appID)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->GetTopApp(versionCode, appID);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}


StatusType GetAllAppsByDownloads(void *DS, int versionCode, int **apps, int *numOfApps)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->GetAllAppsByDownloads(versionCode, apps, numOfApps);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}


StatusType UpdateDownloads(void *DS, int groupBase, int multiplyFactor)
{
	GohooApps* ds = (GohooApps*) DS;
	int res = (int) ds->UpdateDownloads(groupBase, multiplyFactor);
	res = res > 3 ? 3 : res;
	return StatusType(res);
}


void Quit(void** DS)
{
	GohooApps* ds = (GohooApps*) DS;
}


