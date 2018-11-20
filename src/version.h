#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 2;
	static const long BUILD  = 218;
	static const long REVISION  = 1154;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 472;
	#define RC_FILEVERSION 0,2,218,1154
	#define RC_FILEVERSION_STRING "0, 2, 218, 1154\0"
	static const char FULLVERSION_STRING [] = "0.2.218.1154";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 18;
	

#endif //VERSION_H
