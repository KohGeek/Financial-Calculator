#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 1;
	static const long BUILD  = 1;
	static const long REVISION  = 2387;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 695;
	#define RC_FILEVERSION 1,1,1,2387
	#define RC_FILEVERSION_STRING "1, 1, 1, 2387\0"
	static const char FULLVERSION_STRING [] = "1.1.1.2387";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 20;
	

#endif //VERSION_H
