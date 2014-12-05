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

bool operator<(const AppData& data1, const AppData& data2)
{
	return (data1.downloadCount < data2.downloadCount || 
		(data1.downloadCount == data2.downloadCount && 
		data1.appId < data2.appId));
}

AppData::operator int()
{
	return appId;
}
