#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

extern char* _cmonth[4];
extern char* _string[120];

void month_function(int nmonth);
long ichecker(long max, long min, int allowzero);
float fchecker(long max, long min, int allowzero);
double dchecker(long max, long min, int allowzero);

#endif // CORE_H_INCLUDED
