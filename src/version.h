#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 2;
	static const long BUILD  = 212;
	static const long REVISION  = 1129;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 450;
	#define RC_FILEVERSION 0,2,212,1129
	#define RC_FILEVERSION_STRING "0, 2, 212, 1129\0"
	static const char FULLVERSION_STRING [] = "0.2.212.1129";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 12;
	

#endif //VERSION_H
