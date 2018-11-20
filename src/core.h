#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

extern char* _cmonth[4];
extern char* _string[120];

void month_function(int nmonth);
long ichecker(long max, long min, int allowzero);
float fchecker(float max, float min, int allowzero, int percentage);
double dchecker(double max, double min, int allowzero);

#endif // CORE_H_INCLUDED
