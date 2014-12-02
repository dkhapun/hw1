#pragma once
#include "avltree/avltree.h"
#include "appdata.h"

/*
* this datatype holds:
* key value - the download count
* data      - avl tree of app ids
*/

class DownloadData
{
public:
	int const downloadCount; /*this is the key*/
	avl_tree::AVLTree<AppData, int> appsTree;

	/*construct*/
	DownloadData(int downloads);

	/*convert to int = get the key*/
	operator int();
};
