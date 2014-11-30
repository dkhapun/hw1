#pragma once
#include "library1.h"

class DataStruct
{
public:
	/* Description:   Constructor
	 */
	DataStruct();
	
	/* Description:   Destructor
	 */
	~DataStruct();
	
	/* Description:   Adds a new version.
	 * Input:         versionCode - The ID of the version to add.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if versionCode <= 0.
	 *                FAILURE - If versionCode isn't bigger than that of the previous versions.
	 *                SUCCESS - Otherwise.
	 */
	StatusType AddVersion(int versionCode);
	
	/* Description:   Adds a new application to the system.
	 * Input:         appID - ID of the application to add.
	 *                versionCode - The version that the application is compatible with.
	 *                downloadCount - The application's initial download count.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL, or if appID <=0, or if versionCode <=0, or if downloadCount < 0
	 *                FAILURE - If appID is already in the DS, or versionCode isn't in the DS.
	 *                SUCCESS - Otherwise.
	 */
	StatusType AddApplication(int appID, int versionCode, int downloadCount);
	
	/* Description:   Removes an existing application.
	 * Input:         appID - The ID of the application to remove.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if appID <= 0.
	 *                FAILURE - If appID isn't in the DS.
	 *                SUCCESS - Otherwise.
	 */
	StatusType RemoveApplication(int appID);
	
	/* Description:   Increases the download count of an application.
	 * Input:         appID - The ID of the application.
	 *		  downloadIncrease - The amount of downloads to add.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL, or if appID<=0, or if downloadIncrease<=0
	 *                FAILURE - If appID isn't in the DS.
	 *                SUCCESS - Otherwise.
	 */
	StatusType IncreaseDownloads(int appID, int downloadIncrease);
	
	/* Description:   Upgrades an application to the following version
	 * Input:         appID - The ID of the application.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL, or if appID<=0.
	 *                FAILURE - If appID isn't in the DS, or there isn't a following version.
	 *                SUCCESS - Otherwise.
	 */
	StatusType UpgradeApplication(int appID);
	
	/* Description:   Returns the most downloaded application in versionCode.
	 * 			If versionCode < 0, returns the most downloaded app in the entire DS.
	 * Input:         versionCode - The version that we'd like to get the data for.
	 * Output:        appID - A pointer to a variable that should be updated to the ID of the most downloaded app.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if appID == NULL or if versionCode == 0.
	 *                SUCCESS - Otherwise.
	 */
	StatusType GetTopApp(int versionCode, int *appID);
	
	/* Description:   Returns all the applications currently in versionCode sorted by their downloads.
	 * 			If versionCode < 0, returns all the applications in the entire DS sorted by their downloads.
	 * Input:         versionCode - The version that we'd like to get the data for.
	 * Output:        apps - A pointer to a to an array that you should update with the apps' IDs sorted by their downloads,
	 *			in case two apps have same download count they should be sorted by their ID.
	 *                numOfApps - A pointer to a variable that should be updated to the number of apps.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If any of the arguments is NULL or if versionCode == 0.
	 *                SUCCESS - Otherwise.
	 */
	StatusType GetAllAppsByDownloads(int versionCode, int **apps, int *numOfApps);
	
	/* Description:   Updates the download count of the applications where appID % groupBase == 0.
	 * 			For each matching app, multiplies its download count by multiplyFactor.
	 * Input:         groupBase - Represents a group of applications
	 *		  multiplyFactor - The multiply factor.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if groupBase < 1 or if multiplyFactor <=0
	 *                SUCCESS - Otherwise.
	 */
	StatusType UpdateDownloads(int groupBase, int multiplyFactor);

};
