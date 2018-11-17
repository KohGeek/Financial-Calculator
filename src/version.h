#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 1;
	static const long BUILD  = 105;
	static const long REVISION  = 588;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 192;
	#define RC_FILEVERSION 0,1,105,588
	#define RC_FILEVERSION_STRING "0, 1, 105, 588\0"
	static const char FULLVERSION_STRING [] = "0.1.105.588";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 5;
	

#endif //VERSION_H
