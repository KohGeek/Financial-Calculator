#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

extern char* _cmonth[4];
extern char* _string[120];

extern int _gint;
extern float _gfloat;
extern double _gdouble;

void month_function(int nmonth);
int dchecker(double max, double min, int type, int allowzero);

#endif // CORE_H_INCLUDED
