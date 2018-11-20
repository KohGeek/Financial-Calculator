#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 1;
	static const long BUILD  = 156;
	static const long REVISION  = 859;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 310;
	#define RC_FILEVERSION 0,1,156,859
	#define RC_FILEVERSION_STRING "0, 1, 156, 859\0"
	static const char FULLVERSION_STRING [] = "0.1.156.859";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 56;
	

#endif //VERSION_H
