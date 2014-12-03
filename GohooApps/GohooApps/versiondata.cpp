#include "versiondata.h"
	
VersionData::VersionData(int version)
:
versionCode(version),
mDownloadsTree()
{
}
VersionData::VersionData() :
versionCode(0),
mDownloadsTree()
{

}
VersionData::operator int()
{
	return versionCode;
}
VersionData& VersionData::operator=(const VersionData& data)
{
	versionCode = data.versionCode;
	mDownloadsTree = data.mDownloadsTree;
	return *this;
}