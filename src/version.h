#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Release Candidate";
	static const char STATUS_SHORT[] =  "rc";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 14;
	static const long REVISION  = 2305;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 694;
	#define RC_FILEVERSION 1,0,14,2305
	#define RC_FILEVERSION_STRING "1, 0, 14, 2305\0"
	static const char FULLVERSION_STRING [] = "1.0.14.2305";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 19;
	

#endif //VERSION_H
