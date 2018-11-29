/**
 * This part of the code was intended only for autoversioing and
 * logging purpose, a function provided as-is by Code:Blocks.
**/

#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 1;
	static const long BUILD  = 2;
	static const long REVISION  = 2563;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 698;
	#define RC_FILEVERSION 1,1,2,2563
	#define RC_FILEVERSION_STRING "1, 1, 2, 2563\0"
	static const char FULLVERSION_STRING [] = "1.1.2.2563";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 23;


#endif //VERSION_H
