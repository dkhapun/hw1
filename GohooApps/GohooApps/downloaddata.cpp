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
