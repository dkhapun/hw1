#include "versiondata.h"
	
VersionData::VersionData(int version)
:
versionCode(version),
downloadsTree()
{
}
VersionData::VersionData() :
versionCode(0),
downloadsTree()
{

}
VersionData::operator int()
{
	return versionCode;
}
VersionData& VersionData::operator=(const VersionData& data)
{
	versionCode = data.versionCode;
	downloadsTree = data.downloadsTree;
	return *this;
}