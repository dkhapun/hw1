#include "appdata.h"	
	
AppData::AppData(int app, int version, int downloads)
:
appId(app),
versionCode(version), 
downloadCount(downloads)
{
}

AppData& AppData::operator=(const AppData& data)
{
	appId = data.appId;
	versionCode = data.versionCode;
	downloadCount = data.downloadCount;
	return *this;
}
AppData::operator int()
{
	return appId;
}
