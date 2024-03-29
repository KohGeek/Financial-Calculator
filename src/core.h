#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

//This declares that the global variable are shared across numerous .c files
extern char* _cmonth[4];
extern char* _string[120];
extern char* _units[10];

//Forward declaration of functions
int flush();
void month_function(int nmonth);
long ichecker(long max, long min, int allowzero, int psfix);
float fchecker(float max, float min, int allowzero, int psfix);
double dchecker(double max, double min, int allowzero, int psfix);

#endif // CORE_H_INCLUDED
