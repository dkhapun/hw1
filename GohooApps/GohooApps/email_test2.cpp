/*
 * stress_tests.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Denis
 */


#include "library1.h"
#include "email_test2.h"
#include <stdlib.h>
#include "display.h"
#include <iostream>
using namespace std;

// STRESS_TEST1 checks DS's Strength at maintaining large amounts of data.
bool STRESS_TEST1();

// STRESS_TEST2 checks correctness of DS in removal of applications.
bool STRESS_TEST2();

// STRESS_TEST3 checks "increase downloads" , "upgrade version"
bool STRESS_TEST3();

//STRESS_TEST4 checks "update downloads" and "get all applications by downloads"
bool STRESS_TEST4();

// random generated operations.
bool STRESS_TEST5();

bool STRESS_TEST1() {
	void* DS = Init();

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 1) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 2) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 3) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 4) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 5) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 6) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 7) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 8) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 9) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 10) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 11) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 12) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 13) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 14) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 15) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 16) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 17) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 18) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 19) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 20) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 21) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 22) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 23) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 24) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 25) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 26) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 27) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 28) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 29) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 30) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 31) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 32) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 33) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 34) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 35) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 36) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 37) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 38) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 39) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 40) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 41) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 42) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 43) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 44) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 45) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 46) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 47) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 48) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 49) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 50) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 51) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 52) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 53) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 54) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 55) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 56) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 57) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 58) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 59) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 60) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 61) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 62) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 63) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 64) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 65) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 66) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 67) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 68) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 69) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 70) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 71) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 72) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 73) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 74) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 75) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 76) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 77) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 78) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 79) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 80) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 81) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 82) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 83) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 84) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 85) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 86) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 87) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 88) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 89) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 90) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 91) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 92) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 93) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 94) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 95) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 96) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 97) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 98) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 99) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 100) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 101) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 102) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 103) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 104) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 105) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 106) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 107) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 108) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 109) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 110) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 111) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 112) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 113) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 114) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 115) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 116) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 117) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 118) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 119) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 120) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 121) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 122) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 123) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 124) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 125) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 126) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 127) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 128) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 129) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 130) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 131) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 132) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 133) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 134) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 135) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 136) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 137) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 138) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 139) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 140) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 141) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 142) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 143) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 144) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 145) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 146) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 147) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 148) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 149) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 150) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 151) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 152) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 153) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 154) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 155) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 156) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 157) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 158) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 159) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 160) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 161) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 162) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 163) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 164) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 165) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 166) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 167) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 168) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 169) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 170) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 171) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 172) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 173) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 174) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 175) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 176) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 177) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 178) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 179) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 180) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 181) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 182) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 183) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 184) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 185) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 186) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 187) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 188) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 189) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 190) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 191) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 192) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 193) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 194) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 195) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 196) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 197) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 198) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 199) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 200) );

	ASSERT_TRUE( SUCCESS == AddApplication(DS, 1,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 2,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 3,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 4,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 5,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 6,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 7,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 8,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 9,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 10,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 11,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 12,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 13,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 14,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 15,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 16,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 17,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 18,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 19,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 20,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 21,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 22,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 23,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 24,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 25,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 26,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 27,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 28,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 29,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 30,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 31,1,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,2,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,3,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,4,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,5,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,6,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,7,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,8,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,9,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 31,10,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 32,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 33,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 34,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 35,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 36,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 37,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 38,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 39,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 40,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 41,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 42,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 43,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 44,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 45,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 46,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 47,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 48,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 49,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 50,1,2) ); //top application for version 1.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 51,2,2) ); //top application for version 2.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 52,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 53,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 54,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 55,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 56,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 57,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 58,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 59,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 60,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 61,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 62,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 63,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 64,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 65,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 66,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 67,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 68,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 69,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 70,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 71,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 72,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 73,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 74,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 75,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 76,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 77,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 78,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 79,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 80,3,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 81,3,1000) ); //top application for version 3.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 82,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 83,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 84,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 85,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 86,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 87,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 88,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 89,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 90,3,1000) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 91,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 92,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 93,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 94,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 95,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 96,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 97,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 98,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 99,4,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 100,4,20) ); //best application for version 4.

	// checking application being added correctly.
	int app = 0;
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 50 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 51 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 3,&app) );
	ASSERT_TRUE( 81 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 4,&app) );
	ASSERT_TRUE( 100 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 81 == app );

	// adds new applications.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 101,10,5) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 102,10,6) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 103,10,7) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 104,10,8) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 105,10,9) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 106,10,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 107,10,11) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 108,10,12) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 109,10,13) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 110,10,14) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 111,10,15) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 112,10,16) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 113,10,17) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 114,10,18) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 115,10,19) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 116,10,20) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 117,10,21) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 118,10,22) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 119,10,23) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 120,10,24) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 121,10,25) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 122,10,26) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 123,10,27) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 124,10,28) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 125,10,29) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 126,10,30) ); //top application for version 10.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 127,100,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 128,100,199) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 129,100,991) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 130,100,999) ); //top application for version 100.

	// checking application being added correctly.
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 50 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 51 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 3,&app) );
	ASSERT_TRUE( 81 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 4,&app) );
	ASSERT_TRUE( 100 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 10,&app) );
	ASSERT_TRUE( 126 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 100,&app) );
	ASSERT_TRUE( 130 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 81 == app );

	return true;
}

bool STRESS_TEST2() {
	void* DS = Init();

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 1) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 2) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 3) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 4) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 5) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 6) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 7) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 8) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 9) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 10) );

	ASSERT_TRUE( SUCCESS == AddApplication(DS, 1,1,1) ); //top application for version 1.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 2,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 3,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 4,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 5,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 6,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 7,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 8,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 9,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 10,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 11,2,2) ); //top application for version 2.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 12,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 13,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 14,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 15,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 16,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 17,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 18,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 19,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 20,2,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 21,3,2) ); //top application for version 3.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 22,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 23,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 24,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 25,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 26,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 27,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 28,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 29,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 30,3,2) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 31,8,8) ); //top application for version 8.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 32,8,8) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 33,9,9) ); //top application for version 9.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 34,9,9) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 35,10,10) ); //top application for version 10.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 36,10,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 37,10,10) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 38,7,7) ); //top application for version 7.
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 39,7,7) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 40,7,7) );

	// checking application being added correctly.
	int app = 0;
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 1 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 11 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 3,&app) );
	ASSERT_TRUE( 21 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 7,&app) );
	ASSERT_TRUE( 38 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 8,&app) );
	ASSERT_TRUE( 31 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 9,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 10,&app) );
	ASSERT_TRUE( 35 == app );

	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 35 == app );

	// should only successfully remove applications in range 1-40.



	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 10) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 101) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 101) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 99) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 43) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 56) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 12) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 67) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 999) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 100) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 2) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 3) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 14) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 22) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 55) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 27) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 31) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 1) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 1) );

cout << endl << "before:" << endl;
display(DS);
cout << "--------------------------------------" << endl;
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 6) );
cout << "after:" << endl;
display(DS);

	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 90) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 34424) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 700) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 8) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 9) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 10) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 40) );

	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 30) );

	// checking new top application in each version.
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 4 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 11 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 3,&app) );
	ASSERT_TRUE( 21 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 7,&app) );
	ASSERT_TRUE( 38 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 8,&app) );
	ASSERT_TRUE( 32 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 9,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 10,&app) );
	ASSERT_TRUE( 35 == app );

	// top application in DS.
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 35 == app );

	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 4) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 11) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 21) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 38) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 32) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 33) );
	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 35) );

	// checking new top application in each version.
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 5 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 13 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 3,&app) );
	ASSERT_TRUE( 23 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 7,&app) );
	ASSERT_TRUE( 39 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 8,&app) );
	ASSERT_TRUE( -1 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 9,&app) );
	ASSERT_TRUE( 34 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 10,&app) );
	ASSERT_TRUE( 36 == app );

	// top application in DS.
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 36 == app );

	return true;
}

bool STRESS_TEST3() {
	void* DS = Init();

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 1) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 2) );

	ASSERT_TRUE( SUCCESS == AddApplication(DS, 1,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 2,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 3,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 4,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 5,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 6,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 7,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 8,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 9,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 10,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 11,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 12,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 13,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 14,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 15,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 16,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 17,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 18,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 19,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 20,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 21,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 22,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 23,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 24,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 25,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 26,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 27,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 28,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 29,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 30,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 31,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 32,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 33,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 34,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 35,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 36,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 37,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 38,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 39,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 40,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 41,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 42,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 43,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 44,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 45,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 46,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 47,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 48,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 49,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 50,1,1) );

	int app = 0;
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 1 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( -1 == app );

	// at the end of upgrade applications 1-32 are in version 2,the others still in version 1.
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 1));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 2));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 3));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 4));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 5));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 6));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 7));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 8));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 9));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 10));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 11));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 12));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 13));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 14));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 15));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 16));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 17));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 18));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 19));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 20));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 21));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 22));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 23));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 24));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 25));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 26));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 27));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 28));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 29));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 30));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 31));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 32));

	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 1 == app );

	// checking that "IncreaseDownloads" isn't doing troubles.
	for( int i = 1 ; i <= 50 ; i++) {
		for( int j = 1 ; j <=3 ; j++)
		ASSERT_TRUE( SUCCESS == IncreaseDownloads(DS, i,j) );
	}

	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 1,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 2,&app) );
	ASSERT_TRUE( 1 == app );

	return true;
}

bool STRESS_TEST4() {
	void* DS = Init();

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 1) );

	ASSERT_TRUE( SUCCESS == AddApplication(DS, 1,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 2,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 3,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 4,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 5,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 6,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 7,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 8,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 9,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 10,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 11,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 12,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 13,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 14,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 15,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 16,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 17,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 18,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 19,1,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 20,1,1) );

	int numOfApps;
	int* apps;

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 2 == apps[1] );
	ASSERT_TRUE( 3 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 7 == apps[6] );
	ASSERT_TRUE( 8 == apps[7] );
	ASSERT_TRUE( 9 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );
	ASSERT_TRUE( 11 == apps[10] );
	ASSERT_TRUE( 12 == apps[11] );
	ASSERT_TRUE( 13 == apps[12] );
	ASSERT_TRUE( 14 == apps[13] );
	ASSERT_TRUE( 15 == apps[14] );
	ASSERT_TRUE( 16 == apps[15] );
	ASSERT_TRUE( 17 == apps[16] );
	ASSERT_TRUE( 18 == apps[17] );
	ASSERT_TRUE( 19 == apps[18] );
	ASSERT_TRUE( 20 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 2,2));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 2 == apps[0] );
	ASSERT_TRUE( 4 == apps[1] );
	ASSERT_TRUE( 6 == apps[2] );
	ASSERT_TRUE( 8 == apps[3] );
	ASSERT_TRUE( 10 == apps[4] );
	ASSERT_TRUE( 12 == apps[5] );
	ASSERT_TRUE( 14 == apps[6] );
	ASSERT_TRUE( 16 == apps[7] );
	ASSERT_TRUE( 18 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );
	ASSERT_TRUE( 1 == apps[10] );
	ASSERT_TRUE( 3 == apps[11] );
	ASSERT_TRUE( 5 == apps[12] );
	ASSERT_TRUE( 7 == apps[13] );
	ASSERT_TRUE( 9 == apps[14] );
	ASSERT_TRUE( 11 == apps[15] );
	ASSERT_TRUE( 13 == apps[16] );
	ASSERT_TRUE( 15 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 5,2));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 1,50));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 31,2));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	for( int i = 1 ; i <= 20 ; i++ )
		ASSERT_TRUE( SUCCESS == RemoveApplication(DS, i) );

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 2) );

	for( int i = 1 ; i <= 10 ; i++ )
		ASSERT_TRUE( SUCCESS == AddApplication(DS, i,1,1) );

	for( int i = 11 ; i <= 20 ; i++ )
		ASSERT_TRUE( SUCCESS == AddApplication(DS, i,2,2) );

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 1,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 2 == apps[1] );
	ASSERT_TRUE( 3 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 7 == apps[6] );
	ASSERT_TRUE( 8 == apps[7] );
	ASSERT_TRUE( 9 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 2,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 11 == apps[0] );
	ASSERT_TRUE( 12 == apps[1] );
	ASSERT_TRUE( 13 == apps[2] );
	ASSERT_TRUE( 14 == apps[3] );
	ASSERT_TRUE( 15 == apps[4] );
	ASSERT_TRUE( 16 == apps[5] );
	ASSERT_TRUE( 17 == apps[6] );
	ASSERT_TRUE( 18 == apps[7] );
	ASSERT_TRUE( 19 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 11 == apps[0] );
	ASSERT_TRUE( 12 == apps[1] );
	ASSERT_TRUE( 13 == apps[2] );
	ASSERT_TRUE( 14 == apps[3] );
	ASSERT_TRUE( 15 == apps[4] );
	ASSERT_TRUE( 16 == apps[5] );
	ASSERT_TRUE( 17 == apps[6] );
	ASSERT_TRUE( 18 == apps[7] );
	ASSERT_TRUE( 19 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );
	ASSERT_TRUE( 1 == apps[10] );
	ASSERT_TRUE( 2 == apps[11] );
	ASSERT_TRUE( 3 == apps[12] );
	ASSERT_TRUE( 4 == apps[13] );
	ASSERT_TRUE( 5 == apps[14] );
	ASSERT_TRUE( 6 == apps[15] );
	ASSERT_TRUE( 7 == apps[16] );
	ASSERT_TRUE( 8 == apps[17] );
	ASSERT_TRUE( 9 == apps[18] );
	ASSERT_TRUE( 10 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 2,2));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 12 == apps[0] );
	ASSERT_TRUE( 14 == apps[1] );
	ASSERT_TRUE( 16 == apps[2] );
	ASSERT_TRUE( 18 == apps[3] );
	ASSERT_TRUE( 20 == apps[4] );
	ASSERT_TRUE( 2 == apps[5] );
	ASSERT_TRUE( 4 == apps[6] );
	ASSERT_TRUE( 6 == apps[7] );
	ASSERT_TRUE( 8 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );
	ASSERT_TRUE( 11 == apps[10] );
	ASSERT_TRUE( 13 == apps[11] );
	ASSERT_TRUE( 15 == apps[12] );
	ASSERT_TRUE( 17 == apps[13] );
	ASSERT_TRUE( 19 == apps[14] );
	ASSERT_TRUE( 1 == apps[15] );
	ASSERT_TRUE( 3 == apps[16] );
	ASSERT_TRUE( 5 == apps[17] );
	ASSERT_TRUE( 7 == apps[18] );
	ASSERT_TRUE( 9 == apps[19] );


	free(apps);

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 1,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 2 == apps[0] );
	ASSERT_TRUE( 4 == apps[1] );
	ASSERT_TRUE( 6 == apps[2] );
	ASSERT_TRUE( 8 == apps[3] );
	ASSERT_TRUE( 10 == apps[4] );
	ASSERT_TRUE( 1 == apps[5] );
	ASSERT_TRUE( 3 == apps[6] );
	ASSERT_TRUE( 5 == apps[7] );
	ASSERT_TRUE( 7 == apps[8] );
	ASSERT_TRUE( 9 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 2,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 12 == apps[0] );
	ASSERT_TRUE( 14 == apps[1] );
	ASSERT_TRUE( 16 == apps[2] );
	ASSERT_TRUE( 18 == apps[3] );
	ASSERT_TRUE( 20 == apps[4] );
	ASSERT_TRUE( 11 == apps[5] );
	ASSERT_TRUE( 13 == apps[6] );
	ASSERT_TRUE( 15 == apps[7] );
	ASSERT_TRUE( 17 == apps[8] );
	ASSERT_TRUE( 19 == apps[9] );

	free(apps);

	return true;
}

bool STRESS_TEST5() {
	void* DS = Init();

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 6) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 1,1,1) );
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 21));
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 11) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 1,5,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 1,7,1) );
	ASSERT_TRUE( SUCCESS == AddApplication(DS, 1,6,1) );
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 34));
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 16));
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 6));
	ASSERT_TRUE( FAILURE == AddVersion(DS, 2) );
	ASSERT_TRUE( FAILURE == RemoveApplication(DS, 300) );
	ASSERT_TRUE( FAILURE == AddVersion(DS, 3) );
	ASSERT_TRUE( SUCCESS == AddVersion(DS, 7) );
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 19));
	ASSERT_TRUE( FAILURE == UpgradeApplication(DS, 3));
	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 1));

	// we have version 7 containing application 1,and version 6 with no application.
	int numOfApps;
	int* apps;
	int app;

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 6,&apps,&numOfApps));
	ASSERT_TRUE( 0 == numOfApps );
	free(apps);

	ASSERT_TRUE( SUCCESS == AddApplication(DS, 6,6,2) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 6,6,1) );
	ASSERT_TRUE( FAILURE == AddApplication(DS, 6,7,2) );

	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 6,&app) );
	ASSERT_TRUE( 6 == app);
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, 7,&app) );
	ASSERT_TRUE( 1 == app);
	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 6 == app);

	ASSERT_TRUE( FAILURE == AddVersion(DS, 7) );

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -5,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 6 == apps[0] );
	ASSERT_TRUE( 1 == apps[1] );

	free(apps);

	// case version doesn't exist.
	ASSERT_TRUE( FAILURE == GetAllAppsByDownloads(DS, 3,&apps,&numOfApps) );

	ASSERT_TRUE( SUCCESS == RemoveApplication(DS, 6) );

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, -234,&apps,&numOfApps));
	ASSERT_TRUE( 1 == numOfApps );
	ASSERT_TRUE( 1 == apps[0] );


	free(apps);

	ASSERT_TRUE( SUCCESS == AddVersion(DS, 24) );
	// in case the version has no applications.
	ASSERT_TRUE( SUCCESS == GetAllAppsByDownloads(DS, 24,&apps,&numOfApps) );
	ASSERT_TRUE( 0 == numOfApps );
	ASSERT_TRUE( NULL == apps );


	ASSERT_TRUE( SUCCESS == AddApplication(DS, 24,24,1) );

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 24,&apps,&numOfApps));
	ASSERT_TRUE( 1 == numOfApps );
	ASSERT_TRUE( 24 == apps[0] );

	free(apps);

	ASSERT_TRUE( SUCCESS == GetTopApp(DS, -1,&app) );
	ASSERT_TRUE( 1 == app);

	ASSERT_TRUE( SUCCESS == UpgradeApplication(DS, 1));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 24,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 24 == apps[1] );

	free(apps);

	ASSERT_NO_THROW(UpdateDownloads(DS, 24,24));

	ASSERT_NO_THROW(GetAllAppsByDownloads(DS, 24,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 24 == apps[0] );
	ASSERT_TRUE( 1 == apps[1] );

	free(apps);

	return true;
}

int main() {
	RUN_TEST(STRESS_TEST1);
	RUN_TEST(STRESS_TEST2);
	//RUN_TEST(STRESS_TEST3);
	//RUN_TEST(STRESS_TEST4);
	//RUN_TEST(STRESS_TEST5);
	return 0;
}
