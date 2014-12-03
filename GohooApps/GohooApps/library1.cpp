#include "library1.h"
#include "gohooapps.h"

void* Init()
{
	return new GohooApps();
}

StatusType AddVersion(void *DS, int versionCode)
{
	GohooApps* ds = (GohooApps*)DS;
	//GohooApps::StatusType res = ds->AddVersion(versionCode);
	return SUCCESS;
}


StatusType AddApplication(void *DS, int appID, int versionCode, int downloadCount)
{
	return SUCCESS;
}


StatusType RemoveApplication(void *DS, int appID)
{
	return SUCCESS;
}
StatusType IncreaseDownloads(void *DS, int appID, int downloadIncrease)
{
	return SUCCESS;
}

StatusType UpgradeApplication(void *DS, int appID)
{
	return SUCCESS;
}

StatusType GetTopApp(void *DS, int versionCode, int *appID)
{
	return SUCCESS;
}


StatusType GetAllAppsByDownloads(void *DS, int versionCode, int **apps, int *numOfApps)
{
	return SUCCESS;
}


StatusType UpdateDownloads(void *DS, int groupBase, int multiplyFactor)
{
	return SUCCESS;
}


void Quit(void** DS)
{
	
}


