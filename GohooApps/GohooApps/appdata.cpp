#include "appdata.h"	
	
AppData::AppData(int app, int version, int downloads)
:
appId(app),
versionCode(version), 
downloadCount(downloads)
{
}


AppData::operator int()
{
	return appId;
}
