#pragma once
#include "avltree.h"
#include "appdata.h"

/*
* this datatype holds:
* key value - the download count
* data      - avl tree of app ids
*/

class DownloadData
{
public:
	int downloadCount; /*this is the key*/
	avl_tree::AVLTree<AppData, int> mAppsTree;

	/*construct*/
	DownloadData(int downloads);

	/*construct using an ordered list of apps*/
	DownloadData(int downloads, List<AppData> appsList);

	/*convert to int = get the key*/
	operator int();
	DownloadData& operator=(const DownloadData& data);
};
