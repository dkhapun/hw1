/***************************************************************************/
/*                                                                         */
/* 234218 Data DSs 1, Winter 2014-2015                                     */
/*                                                                         */
/* Homework : Wet 1                                                        */
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/* File Name : main1.cpp                                                   */
/*                                                                         */
/* Holds the "int main()" function and the parser of the shell's           */
/* command line.                                                           */
/***************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library1.h"
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

/* The command's strings */
typedef enum {
	NONE_CMD = -2,
	COMMENT_CMD = -1,
	INIT_CMD = 0,
	ADDVERSION_CMD = 1,
	ADDAPP_CMD = 2,
	REMOVEAPP_CMD = 3,
	INCREASE_CMD = 4,
	UPGRADE_CMD = 5,
	GETTOPAPP_CMD = 6,
	GETALLAPPS_CMD = 7,
	UPDATE_CMD = 8,
	QUIT_CMD = 9
} commandType;

static const int numActions = 10;
static const char *commandStr[] = { "Init", "AddVersion", "AddApplication",
		"RemoveApplication", "IncreaseDownloads", "UpgradeApplication",
		"GetTopApp", "GetAllAppsByDownloads", "UpdateDownloads", "Quit" };

static const char* ReturnValToStr(int val) {
	switch (val) {
	case SUCCESS:
		return "SUCCESS";
	case ALLOCATION_ERROR:
		return "ALLOCATION_ERROR";
	case FAILURE:
		return "FAILURE";
	case INVALID_INPUT:
		return "INVALID_INPUT";
	default:
		return "";
	}
}

/* we assume maximum string size is not longer than 256  */
#define MAX_STRING_INPUT_SIZE (255)
#define MAX_BUFFER_SIZE       (255)

#define StrCmp(Src1,Src2) ( strncmp((Src1),(Src2),strlen(Src1)) == 0 )

typedef enum {
	error_free, error
} errorType;
static errorType parser(const char* const command);

#define ValidateRead(read_parameters,required_parameters,ErrorString) \
if ( (read_parameters)!=(required_parameters) ) { printf(ErrorString); return error; }

static bool isInit = false;

/***************************************************************************/
/* main                                                                    */
/***************************************************************************/

int main(int argc, const char**argv) {
	char buffer[MAX_STRING_INPUT_SIZE];

	// Reading commands
	while (fgets(buffer, MAX_STRING_INPUT_SIZE, stdin) != NULL) {
		fflush(stdout);
		if (parser(buffer) == error)
			break;
	};
	return 0;
}

/***************************************************************************/
/* Command Checker                                                         */
/***************************************************************************/

static commandType CheckCommand(const char* const command,
		const char** const command_arg) {
	if (command == NULL || strlen(command) == 0 || StrCmp("\n", command))
		return (NONE_CMD);
	if (StrCmp("#", command)) {
		if (strlen(command) > 1)
			printf("%s", command);
		return (COMMENT_CMD);
	};
	for (int index = 0; index < numActions; index++) {
		if (StrCmp(commandStr[index], command)) {
			*command_arg = command + strlen(commandStr[index]) + 1;
			return ((commandType) index);
		};
	};
	return (NONE_CMD);
}

/***************************************************************************/
/* Commands Functions                                                      */
/***************************************************************************/

static errorType OnInit(void** DS, const char* const command);
static errorType OnAddVersion(void* DS, const char* const command);
static errorType OnAddApplication(void* DS, const char* const command);
static errorType OnRemoveApplication(void* DS, const char* const command);
static errorType OnIncreaseDownloads(void* DS, const char* const command);
static errorType OnUpgradeApplication(void* DS, const char* const command);
static errorType OnGetTopApp(void* DS, const char* const command);
static errorType OnGetAllAppsByDownloads(void* DS, const char* const command);
static errorType OnUpdateDownloads(void* DS, const char* const command);
static errorType OnQuit(void** DS, const char* const command);

/***************************************************************************/
/* Parser                                                                  */
/***************************************************************************/

static errorType parser(const char* const command) {
	static void *DS = NULL; /* The general data structure */
	const char* command_args = NULL;
	errorType rtn_val = error;

	commandType command_val = CheckCommand(command, &command_args);

	switch (command_val) {

	case (INIT_CMD):
		rtn_val = OnInit(&DS, command_args);
		break;
	case (ADDVERSION_CMD):
		rtn_val = OnAddVersion(DS, command_args);
		break;
	case (ADDAPP_CMD):
		rtn_val = OnAddApplication(DS, command_args);
		break;
	case (REMOVEAPP_CMD):
		rtn_val = OnRemoveApplication(DS, command_args);
		break;
	case (INCREASE_CMD):
		rtn_val = OnIncreaseDownloads(DS, command_args);
		break;
	case (UPGRADE_CMD):
		rtn_val = OnUpgradeApplication(DS, command_args);
		break;
	case (GETTOPAPP_CMD):
		rtn_val = OnGetTopApp(DS, command_args);
		break;
	case (GETALLAPPS_CMD):
		rtn_val = OnGetAllAppsByDownloads(DS, command_args);
		break;
	case (UPDATE_CMD):
		rtn_val = OnUpdateDownloads(DS, command_args);
		break;
	case (QUIT_CMD):
		rtn_val = OnQuit(&DS, command_args);
		break;

	case (COMMENT_CMD):
		rtn_val = error_free;
		break;
	case (NONE_CMD):
		rtn_val = error;
		break;
	default:
		assert(false);
		break;
	};
	return (rtn_val);
}

/***************************************************************************/
/* OnInit                                                                  */
/***************************************************************************/
static errorType OnInit(void** DS, const char* const command) {
	if (isInit) {
		printf("Init was already called.\n");
		return (error_free);
	};
	isInit = true;

	*DS = Init();
	if (*DS == NULL) {
		printf("Init failed.\n");
		return error;
	};
	printf("Init done.\n");

	return error_free;
}

/***************************************************************************/
/* OnAddVersion                                                             */
/***************************************************************************/
static errorType OnAddVersion(void* DS, const char* const command) {
	int versionCode;
	ValidateRead(sscanf(command, "%d", &versionCode), 1, "AddVersion failed.\n");
	StatusType res = AddVersion(DS, versionCode);

	if (res != SUCCESS) {
		printf("AddVersion: %s\n", ReturnValToStr(res));
		return error_free;
	} else {
		printf("AddVersion: %s\n", ReturnValToStr(res));
	}

	return error_free;
}

/***************************************************************************/
/* OnAddApplication                                                          */
/***************************************************************************/
static errorType OnAddApplication(void* DS, const char* const command) {
	int appID;
	int versionCode;
	int downloadCount;
	ValidateRead(
			sscanf(command, "%d %d %d", &appID, &versionCode, &downloadCount),
			3, "AddApplication failed.\n");
	StatusType res = AddApplication(DS, appID, versionCode, downloadCount);

	if (res != SUCCESS) {
		printf("AddApplication: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("AddApplication: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnRemoveApplication                                                            */
/***************************************************************************/
static errorType OnRemoveApplication(void* DS, const char* const command) {
	int appID;
	ValidateRead(sscanf(command, "%d", &appID), 1,
			"RemoveApplication failed.\n");
	StatusType res = RemoveApplication(DS, appID);

	if (res != SUCCESS) {
		printf("RemoveApplication: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("RemoveApplication: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnIncreaseDownloads                                                         */
/***************************************************************************/
static errorType OnIncreaseDownloads(void* DS, const char* const command) {
	int appID;
	int downloadIncrease;
	ValidateRead(sscanf(command, "%d %d", &appID, &downloadIncrease), 2,
			"IncreaseDownloads failed.\n");
	StatusType res = IncreaseDownloads(DS, appID, downloadIncrease);

	if (res != SUCCESS) {
		printf("IncreaseDownloads: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("IncreaseDownloads: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnUpgradeApplication                                                            */
/***************************************************************************/
static errorType OnUpgradeApplication(void* DS, const char* const command) {
	int appID;
	ValidateRead(sscanf(command, "%d", &appID), 1,
			"UpgradeApplication failed.\n");
	StatusType res = UpgradeApplication(DS, appID);

	if (res != SUCCESS) {
		printf("UpgradeApplication: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("UpgradeApplication: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnGetTopApp                                                         */
/***************************************************************************/
static errorType OnGetTopApp(void* DS, const char* const command) {
	int versionCode;
	ValidateRead(sscanf(command, "%d", &versionCode), 1, "GetTopApp failed.\n");
	int appID;
	StatusType res = GetTopApp(DS, versionCode, &appID);

	if (res != SUCCESS) {
		printf("GetTopApp: %s\n", ReturnValToStr(res));
		return error_free;
	}

	cout << "Most downloaded app is: " << appID << endl;
	return error_free;
}

/***************************************************************************/
/* OnGetAllGames                                                        */
/***************************************************************************/

void PrintAll(int *apps, int numOfApps) {
	if (numOfApps > 0) {
		cout << "Rank	||	App" << endl;
	}

	for (int i = 0; i < numOfApps; i++) {
		cout << i + 1 << "\t||\t" << apps[i] << endl;
	}
	cout << "and there are no more apps!" << endl;

	free (apps);
}

static errorType OnGetAllAppsByDownloads(void* DS, const char* const command) {
	int versionCode;
	ValidateRead(sscanf(command, "%d", &versionCode), 1,
			"GetAllAppsByDownloads failed.\n");
	int* apps;
	int numOfApps;
	StatusType res = GetAllAppsByDownloads(DS, versionCode, &apps, &numOfApps);

	if (res != SUCCESS) {
		printf("GetAllAppsByDownloads: %s\n", ReturnValToStr(res));
		return error_free;
	}

	PrintAll(apps, numOfApps);
	return error_free;
}

/***************************************************************************/
/* OnUpdateDownloads                                                           */
/***************************************************************************/
static errorType OnUpdateDownloads(void* DS, const char* const command) {
	int groupBase;
	int multiplyFactor;
	ValidateRead(sscanf(command, "%d %d", &groupBase, &multiplyFactor), 2,
			"UpdateDownloads failed.\n");
	StatusType res = UpdateDownloads(DS, groupBase, multiplyFactor);

	if (res != SUCCESS) {
		printf("UpdateDownloads: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("UpdateDownloads: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnQuit                                                                  */
/***************************************************************************/
static errorType OnQuit(void** DS, const char* const command) {
	Quit(DS);
	if (*DS != NULL) {
		printf("Quit failed.\n");
		return error;
	};

	isInit = false;
	printf("Quit done.\n");

	return error_free;
}

#ifdef __cplusplus
}
#endif

