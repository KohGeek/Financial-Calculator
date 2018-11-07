#ifndef VERSION_H
#define VERSION_H

	//Date Version Types
	static const char DATE[] = "08";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 0;
	static const long BUILD  = 11;
	static const long REVISION  = 63;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 18;
	#define RC_FILEVERSION 0,0,11,63
	#define RC_FILEVERSION_STRING "0, 0, 11, 63\0"
	static const char FULLVERSION_STRING [] = "0.0.11.63";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 11;
	

#endif //VERSION_H
