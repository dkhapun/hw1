#include <iostream>
#include <stdlib.h>
#include "library1.h"


using std::cin;
using std::cout;
using std::endl;




static int count = 1;
#define ASSERT(expr) do { \
if (!(expr)) {\
     cout<<"\nAssertion failed at line :"<< __LINE__<<")."<<endl; \
return false; \
}\
else {\
		cout<<"NICELY DONE ! you have passed "<<count++<< " tests.(line: "<< __LINE__<<")."<<endl; \
} \
}while(0)

#define ASSERT_EQUALS(expr,expected) ASSERT((expr) == (expected))
#define ASSERT_INVALID_INPUT(expr) ASSERT_EQUALS(expr, INVALID_INPUT)
#define ASSERT_ALLOCATION_ERROR(expr) ASSERT_EQUALS(expr, ALLOCATION_ERROR)
#define ASSERT_FAILURE(expr) ASSERT_EQUALS(expr, FAILURE)
#define ASSERT_SUCCESS(expr) ASSERT_EQUALS(expr, SUCCESS)
#define ASSERT_NULL(expr) ASSERT_EQUALS(expr, NULL)





int main()
{
	


	cout << "Testing the functions:" << endl;
	



	
	void* DS = Init();

	int top; 
	ASSERT_SUCCESS(GetTopApp(DS, -1, &top));
	ASSERT_EQUALS(top, -1);
	ASSERT_FAILURE(GetTopApp(DS, 1, &top));

	ASSERT_INVALID_INPUT(AddVersion(NULL, 1) );
	ASSERT_INVALID_INPUT(AddVersion(DS, 0));
	ASSERT_INVALID_INPUT(AddVersion(DS, -11));
	ASSERT_SUCCESS(AddVersion(DS, 1));
	ASSERT_FAILURE(AddVersion(DS, 1));// should fail?
	ASSERT_SUCCESS(AddVersion(DS, 3));
	ASSERT_FAILURE(AddVersion(DS, 2));
	
	ASSERT_SUCCESS(GetTopApp(DS, -1, &top));//NOT SURE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ASSERT_EQUALS(top, -1);


	ASSERT_INVALID_INPUT(AddApplication(NULL, 123, 1, 3));
	ASSERT_INVALID_INPUT(AddApplication(DS, -1, 1, 3));//APPID<=0
	ASSERT_INVALID_INPUT(AddApplication(DS, 0, 1, 3));//appid=0
	ASSERT_INVALID_INPUT(AddApplication(DS, 123, 0, 3));//version=0
	ASSERT_INVALID_INPUT(AddApplication(DS, 123, -1, 3));//version<0
	ASSERT_INVALID_INPUT(AddApplication(NULL, 123, 1, -1));//download<0
	ASSERT_FAILURE(AddApplication(DS, 100, 2, 1233));//version code doesnt exist
	ASSERT_SUCCESS(AddApplication(DS, 100, 1, 0));
	ASSERT_FAILURE(AddApplication(DS, 100, 1, 0));//appid already exist
	ASSERT_FAILURE(AddApplication(DS, 100, 3, 0));//appid already exist
	ASSERT_SUCCESS(AddApplication(DS, 101, 1, 0));
	ASSERT_SUCCESS(AddApplication(DS, 102, 1, 0));
	ASSERT_SUCCESS(AddApplication(DS, 300, 3, 0));
	ASSERT_SUCCESS(AddApplication(DS, 301, 3, 0));

	ASSERT_INVALID_INPUT(RemoveApplication(NULL, 100));
	ASSERT_INVALID_INPUT(RemoveApplication(DS, 0));//appid=0
	ASSERT_INVALID_INPUT(RemoveApplication(DS, -1));//appid<0
	ASSERT_FAILURE(RemoveApplication(DS, 2));//appid doesnt exist
	ASSERT_FAILURE(RemoveApplication(DS, 123));//appid doesnt exist
	ASSERT_SUCCESS(RemoveApplication(DS, 100));
	ASSERT_SUCCESS(AddApplication(DS, 100, 1, 0));
	ASSERT_SUCCESS(RemoveApplication(DS, 100));
	ASSERT_SUCCESS(AddApplication(DS, 100, 3, 0));
	ASSERT_SUCCESS(RemoveApplication(DS, 100));

	ASSERT_INVALID_INPUT(IncreaseDownloads(NULL, 101, 30));
	ASSERT_INVALID_INPUT(IncreaseDownloads(DS, 0, 30));//appId=0
	ASSERT_INVALID_INPUT(IncreaseDownloads(DS, -1, 30));//appId<0
	ASSERT_INVALID_INPUT(IncreaseDownloads(DS, 101, 0));//downinc=0
	ASSERT_INVALID_INPUT(IncreaseDownloads(DS, 101, -2));//downinc<0
	ASSERT_FAILURE(IncreaseDownloads(DS, 340, 20));//no appid
	ASSERT_FAILURE(IncreaseDownloads(DS, 340, 20));//no appid
	ASSERT_SUCCESS(IncreaseDownloads(DS, 101, 30));
	ASSERT_SUCCESS(IncreaseDownloads(DS, 102, 60));
	ASSERT_SUCCESS(IncreaseDownloads(DS, 300, 20));
	ASSERT_SUCCESS(IncreaseDownloads(DS, 301, 40));
	ASSERT_SUCCESS(IncreaseDownloads(DS, 300, 40));//102 should stay with the bigger appId
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//101=30      102=60
	//300=60      301=40

	GetTopApp(DS, -1, &top);
	ASSERT_EQUALS(top, 102);//102 should stay with the bigger appId
	ASSERT_SUCCESS(IncreaseDownloads(DS, 300, 1));
	GetTopApp(DS, -1, &top);
	ASSERT_EQUALS(top, 300);
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//101=30      102=60
	//300=61      301=40
	ASSERT_SUCCESS(IncreaseDownloads(DS, 101, 31));
	GetTopApp(DS, -1, &top);
	ASSERT_EQUALS(top, 101);
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//101=61      102=60
	//300=61      301=40
	ASSERT_SUCCESS(IncreaseDownloads(DS, 301, 60));
	GetTopApp(DS, -1, &top);
	ASSERT_EQUALS(top, 301);
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//101=61      102=60
	//300=61      301=100
	GetTopApp(DS, 1, &top);
	ASSERT_EQUALS(top, 101);
	GetTopApp(DS, 3, &top);
	ASSERT_EQUALS(top, 301);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 101, 40));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   101=101      102=60
	//version 3:   300=61      301=100

	ASSERT_INVALID_INPUT(UpgradeApplication(NULL, 100));
	ASSERT_INVALID_INPUT(UpgradeApplication(NULL, 101));
	ASSERT_INVALID_INPUT(UpgradeApplication(DS, 0));
	ASSERT_INVALID_INPUT(UpgradeApplication(DS, -1));
	ASSERT_FAILURE(UpgradeApplication(DS, 123));//no such appId
	ASSERT_FAILURE(UpgradeApplication(DS, 301));//no next version
	GetTopApp(DS, 3, &top);
	ASSERT_EQUALS(top, 301);//301 is still inside version 3
	ASSERT_SUCCESS(UpgradeApplication(DS, 101));//upgrade 101
	GetTopApp(DS, 3, &top);
	ASSERT_EQUALS(top, 101);//101 is indeed inside version 3 and its the biggest

	ASSERT_INVALID_INPUT(GetTopApp(NULL, 3, &top));
	ASSERT_INVALID_INPUT(GetTopApp(DS, 3,NULL));
	ASSERT_INVALID_INPUT(GetTopApp(DS, 0, &top));//version code=0
	ASSERT_FAILURE(GetTopApp(DS, 4, &top));//no such version 
	ASSERT_SUCCESS(AddVersion(DS, 4));
	ASSERT_SUCCESS(GetTopApp(DS, 4, &top));
	ASSERT_EQUALS(top, -1);
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=60
	//version 3:   101=101  301=100   300=61  
	//version 4:
	ASSERT_SUCCESS(GetTopApp(DS, 1, &top));
	ASSERT_EQUALS(top, 102);
	ASSERT_SUCCESS(GetTopApp(DS, 3, &top));
	ASSERT_EQUALS(top, 101);
	ASSERT_SUCCESS(GetTopApp(DS, -11, &top));
	ASSERT_EQUALS(top, 101);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 300, 40));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=60
	//version 3:   101=101      300=101		301=100
	//version 4:
	ASSERT_SUCCESS(GetTopApp(DS, -1, &top));
	ASSERT_EQUALS(top, 101);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 300, 9));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=60
	//version 3:   300=110		101=101      301=100
	//version 4:
	ASSERT_SUCCESS(GetTopApp(DS, -1, &top));
	ASSERT_EQUALS(top, 300);
	ASSERT_SUCCESS(GetTopApp(DS, 3, &top));
	ASSERT_EQUALS(top, 300);
	ASSERT_SUCCESS(GetTopApp(DS, 1, &top));
	ASSERT_EQUALS(top, 102);


	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=60
	//version 3:   300=110		101=101      301=100
	//version 4:
	int n;
	int *ptr;
	ASSERT_INVALID_INPUT(GetAllAppsByDownloads(NULL, 1, &ptr, &n));
	ASSERT_INVALID_INPUT(GetAllAppsByDownloads(DS, 1, NULL, &n));
	ASSERT_INVALID_INPUT(GetAllAppsByDownloads(DS, 1, &ptr, NULL));
	ASSERT_INVALID_INPUT(GetAllAppsByDownloads(DS, 0, &ptr, &n));
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, 4, &ptr, &n));
	ASSERT_EQUALS(n, 0);
	//delete[] ptr; no need:n=0
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 4);
	ASSERT_EQUALS(ptr[0], 300);
	ASSERT_EQUALS(ptr[1], 101);
	ASSERT_EQUALS(ptr[2], 301);
	ASSERT_EQUALS(ptr[3], 102);
	free(ptr);
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, 3, &ptr, &n));
	ASSERT_EQUALS(n, 3); 
	ASSERT_EQUALS(ptr[0], 300);
	ASSERT_EQUALS(ptr[1], 101);
	ASSERT_EQUALS(ptr[2], 301);
	free(ptr);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 301, 10));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=60
	//version 3:   300=110      301=110		101=101
	//version 4:
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 4);
	ASSERT_EQUALS(ptr[0], 300);
	ASSERT_EQUALS(ptr[1], 301);
	ASSERT_EQUALS(ptr[2], 101);
	ASSERT_EQUALS(ptr[3], 102);
	free(ptr);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 102, 50));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=110
	//version 3:   300=110      301=110		101=101
	//version 4:
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 4);
	ASSERT_EQUALS(ptr[0], 102);
	ASSERT_EQUALS(ptr[1], 300);
	ASSERT_EQUALS(ptr[2], 301);
	ASSERT_EQUALS(ptr[3], 101);
	free(ptr);
	ASSERT_SUCCESS(AddApplication(DS, 400, 4, 105));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=110
	//version 3:   300=110      301=110		101=101
	//version 4:   400=105
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 5);
	ASSERT_EQUALS(ptr[0], 102);
	ASSERT_EQUALS(ptr[1], 300);
	ASSERT_EQUALS(ptr[2], 301);
	ASSERT_EQUALS(ptr[3], 400);
	ASSERT_EQUALS(ptr[4], 101);
	free(ptr);
	ASSERT_SUCCESS(IncreaseDownloads(DS, 101, 100));
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=110
	//version 3:   101=201	300=110      301=110		
	//version 4:   400=105
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 5);
	ASSERT_EQUALS(ptr[0], 101);
	ASSERT_EQUALS(ptr[1], 102);
	ASSERT_EQUALS(ptr[2], 300);
	ASSERT_EQUALS(ptr[3], 301);
	ASSERT_EQUALS(ptr[4], 400);
	free(ptr);
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, 1, &ptr, &n));
	ASSERT_EQUALS(n, 1);
	ASSERT_EQUALS(ptr[0], 102);
	free(ptr);
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, 4, &ptr, &n));
	ASSERT_EQUALS(n, 1);
	ASSERT_EQUALS(ptr[0], 400);
	free(ptr);
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, 3, &ptr, &n));
	ASSERT_EQUALS(n, 3);
	ASSERT_EQUALS(ptr[0], 101);
	ASSERT_EQUALS(ptr[1], 300);
	ASSERT_EQUALS(ptr[2], 301);
	free(ptr);

	ASSERT_INVALID_INPUT(UpdateDownloads(NULL, 2, 2));
	ASSERT_INVALID_INPUT(UpdateDownloads(DS, 0, 2));
	ASSERT_INVALID_INPUT(UpdateDownloads(DS, -1, 2));
	ASSERT_INVALID_INPUT(UpdateDownloads(DS, 3, 0));
	ASSERT_INVALID_INPUT(UpdateDownloads(DS, 3, -2));
	ASSERT_SUCCESS(UpdateDownloads(DS, 2, 2));//multiply by 2 all the app with appID even
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=220
	//version 3:   300=220     101=201  	301=110		
	//version 4:   400=210
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 5);
	ASSERT_EQUALS(ptr[0], 102);
	ASSERT_EQUALS(ptr[1], 300);
	ASSERT_EQUALS(ptr[2], 400);
	ASSERT_EQUALS(ptr[3], 101);
	ASSERT_EQUALS(ptr[4], 301);
	free(ptr);
	ASSERT_SUCCESS(UpdateDownloads(DS, 1, 2));//multiply by 2 all the apps
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=440
	//version 3:   300=440     101=402  	301=220		
	//version 4:   400=420
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 5);
	ASSERT_EQUALS(ptr[0], 102);
	ASSERT_EQUALS(ptr[1], 300);
	ASSERT_EQUALS(ptr[2], 400);
	ASSERT_EQUALS(ptr[3], 101);
	ASSERT_EQUALS(ptr[4], 301);
	free(ptr);
	ASSERT_SUCCESS(UpdateDownloads(DS, 300, 2));//multiply by 2 only 300(he is the only one that appid % 300 = 0 )
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   102=440
	//version 3:   300=880     101=402  	301=220		
	//version 4:   400=420
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 5);
	ASSERT_EQUALS(ptr[0], 300);
	ASSERT_EQUALS(ptr[1], 102);
	ASSERT_EQUALS(ptr[2], 400);
	ASSERT_EQUALS(ptr[3], 101);
	ASSERT_EQUALS(ptr[4], 301);
	free(ptr);
	ASSERT_SUCCESS(AddApplication(DS, 1000, 1, 300));
	ASSERT_SUCCESS(AddApplication(DS, 1500, 1, 440));
	ASSERT_SUCCESS(UpdateDownloads(DS, 500, 2));//multiply by 2 only 1000 and 1500
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   1500=880	   1000=600     102=440
	//version 3:   300=880     101=402  	301=220		
	//version 4:   400=420
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 7);
	ASSERT_EQUALS(ptr[0], 300);
	ASSERT_EQUALS(ptr[1], 1500);
	ASSERT_EQUALS(ptr[2], 1000);
	ASSERT_EQUALS(ptr[3], 102);
	ASSERT_EQUALS(ptr[4], 400);
	ASSERT_EQUALS(ptr[5], 101);
	ASSERT_EQUALS(ptr[6], 301);
	free(ptr);
	ASSERT_SUCCESS(RemoveApplication(DS, 300));
	ASSERT_SUCCESS(UpdateDownloads(DS, 400, 3));//multiply by 3 only 400
	//the downlads by appId should be now:      (appId=numOfDownloads) 
	//version 1:   1500=880	   1000=600     102=440
	//version 3:   101=402  	301=220		
	//version 4:   400=1260
	ASSERT_SUCCESS(GetAllAppsByDownloads(DS, -1, &ptr, &n));
	ASSERT_EQUALS(n, 6);
	ASSERT_EQUALS(ptr[0], 400); 
	ASSERT_EQUALS(ptr[1], 1500);
	ASSERT_EQUALS(ptr[2], 1000);
	ASSERT_EQUALS(ptr[3], 102);
	ASSERT_EQUALS(ptr[4], 101);
	ASSERT_EQUALS(ptr[5], 301);
	free(ptr);


	Quit(&DS);
	ASSERT_NULL(DS);
cout << "everything was ok .done testing " << endl;
	return 0;
}