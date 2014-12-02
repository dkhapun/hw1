#pragma once
#include "avltree/avltree.h"
#include "downloaddata.h"

/*
* this datatype holds:
* key value - the version code
* data      - avl tree of downloaddata
*/

class VersionData
{
public:
	int versionCode; /*this is the key*/
	avl_tree::AVLTree<DownloadData, int> downloadsTree;

	/*construct*/
	VersionData(int version);
	VersionData();
	/*convert to int = get the key*/
	operator int();
	VersionData& operator=(const VersionData& data);
};
