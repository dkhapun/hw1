#include "downloaddata.h"	
	
DownloadData::DownloadData(int downloads)
:
downloadCount(downloads),
appsTree()
{
}

DownloadData::operator int()
{
	return downloadCount;
}
DownloadData& DownloadData::operator=(const DownloadData& data)
{
	downloadCount = data.downloadCount;
	appsTree = data.appsTree;
	return *this;
}