#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Release Candidate";
	static const char STATUS_SHORT[] =  "rc";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 1;
	static const long BUILD  = 72;
	static const long REVISION  = 1514;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 622;
	#define RC_FILEVERSION 1,1,72,1514
	#define RC_FILEVERSION_STRING "1, 1, 72, 1514\0"
	static const char FULLVERSION_STRING [] = "1.1.72.1514";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 90;
	

#endif //VERSION_H
