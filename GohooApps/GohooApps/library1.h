/****************************************************************************/
/*                                                                          */
/* This file contains the interface functions                               */
/* you should use for the wet ex 1                                          */ 
/*                                                                          */ 
/****************************************************************************/

/****************************************************************************/
/*                                                                          */ 
/* File Name : library1.h                                                   */ 
/*                                                                          */ 
/****************************************************************************/

#ifndef _234218_WET1_
#define _234218_WET1_

#ifdef __cplusplus
extern "C" {
#endif

/* Return Values
 * ----------------------------------- */
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;

/* Required Interface for the Data Structure
 * -----------------------------------------*/

/* Description:   Initiates the data structure.
 * Input:         DS - A pointer to the data structure.
 * Output:        None.
 * Return Values: A pointer to a new instance of the data structure - as a void* pointer.
 */
void* Init();

/* Description:   Adds a new version.
 * Input:         DS - A pointer to the data structure.
 *                versionCode - The ID of the version to add.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if versionCode <= 0.
 *                FAILURE - If versionCode isn't bigger than that of the previous versions.
 *                SUCCESS - Otherwise.
 */
StatusType AddVersion(void *DS, int versionCode);

/* Description:   Adds a new application to the system.
 * Input:         DS - A pointer to the data structure.
 *                appID - ID of the application to add.
 *                versionCode - The version that the application is compatible with.
 *                downloadCount - The application's initial download count.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if appID <=0, or if versionCode <=0, or if downloadCount < 0
 *                FAILURE - If appID is already in the DS, or versionCode isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType AddApplication(void *DS, int appID, int versionCode, int downloadCount);

/* Description:   Removes an existing application.
 * Input:         DS - A pointer to the data structure.
 *                appID - The ID of the application to remove.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if appID <= 0.
 *                FAILURE - If appID isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType RemoveApplication(void *DS, int appID);

/* Description:   Increases the download count of an application.
 * Input:         DS - A pointer to the data structure.
 *                appID - The ID of the application.
 *		  downloadIncrease - The amount of downloads to add.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if appID<=0, or if downloadIncrease<=0
 *                FAILURE - If appID isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType IncreaseDownloads(void *DS, int appID, int downloadIncrease);

/* Description:   Upgrades an application to the following version
 * Input:         DS - A pointer to the data structure.
 *                appID - The ID of the application.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if appID<=0.
 *                FAILURE - If appID isn't in the DS, or there isn't a following version.
 *                SUCCESS - Otherwise.
 */
StatusType UpgradeApplication(void *DS, int appID);

/* Description:   Returns the most downloaded application in versionCode.
 * 			If versionCode < 0, returns the most downloaded app in the entire DS.
 * Input:         DS - A pointer to the data structure.
 *                versionCode - The version that we'd like to get the data for.
 * Output:        appID - A pointer to a variable that should be updated to the ID of the most downloaded app.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if appID == NULL or if versionCode == 0.
 *                SUCCESS - Otherwise.
 */
StatusType GetTopApp(void *DS, int versionCode, int *appID);

/* Description:   Returns all the applications currently in versionCode sorted by their downloads.
 * 			If versionCode < 0, returns all the applications in the entire DS sorted by their downloads.
 * Input:         DS - A pointer to the data structure.
 *                versionCode - The version that we'd like to get the data for.
 * Output:        apps - A pointer to a to an array that you should update with the apps' IDs sorted by their downloads,
 *			in case two apps have same download count they should be sorted by their ID.
 *                numOfApps - A pointer to a variable that should be updated to the number of apps.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If any of the arguments is NULL or if versionCode == 0.
 *                SUCCESS - Otherwise.
 */
StatusType GetAllAppsByDownloads(void *DS, int versionCode, int **apps, int *numOfApps);

/* Description:   Updates the download count of the applications where appID % groupBase == 0.
 * 			For each matching app, multiplies its download count by multiplyFactor.
 * Input:         DS - A pointer to the data structure.
 *                groupBase - Represents a group of applications
 *		  multiplyFactor - The multiply factor.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if groupBase < 1 or if multiplyFactor <=0
 *                SUCCESS - Otherwise.
 */
StatusType UpdateDownloads(void *DS, int groupBase, int multiplyFactor);


/* Description:   Quits and deletes the database.
 *                DS should be set to NULL.
 * Input:         DS - A pointer to the data structure.
 * Output:        None.
 * Return Values: None.
 */
void Quit(void** DS);

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1_ */ 

