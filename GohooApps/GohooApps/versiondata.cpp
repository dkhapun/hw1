#include "versiondata.h"	
	
VersionData::VersionData(int version)
:
versionCode(version),
downloadsTree()
{
}

VersionData::operator int()
{
	return versionCode;
}
