#pragma once

/*
* this datatype holds:
* key value - the app id
* data      - version code, download count
*/

class AppData
{
public:
	int const appId; /*this is the key*/
	int versionCode;
	int downloadCount;

	/*construct*/
	AppData(int app, int version, int downloads);

	/*convert to int = get the key*/
	operator int();
};
