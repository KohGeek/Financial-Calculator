#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Release Candidate";
	static const char STATUS_SHORT[] =  "rc";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 1;
	static const long REVISION  = 1800;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 668;
	#define RC_FILEVERSION 1,0,1,1800
	#define RC_FILEVERSION_STRING "1, 0, 1, 1800\0"
	static const char FULLVERSION_STRING [] = "1.0.1.1800";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 6;
	

#endif //VERSION_H
