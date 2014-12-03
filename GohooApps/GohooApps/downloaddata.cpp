#include "downloaddata.h"	
	
DownloadData::DownloadData(int downloads)
:
downloadCount(downloads),
mAppsTree()
{
}

DownloadData::operator int()
{
	return downloadCount;
}
DownloadData& DownloadData::operator=(const DownloadData& data)
{
	downloadCount = data.downloadCount;
	mAppsTree = data.mAppsTree;
	return *this;
}