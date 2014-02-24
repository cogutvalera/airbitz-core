/** * @fileDebug * AirBitz utility function prototypes * * This file contains misc debug functions * * @author Adam Harris * @version 1.0 */#include "ABC_Debug.h"#if DEBUG#include <stdio.h>#include <time.h>#include <string.h>#include <stdarg.h>void ABC_DebugLog(const char * format, ...){    static char szOut[4096];    struct tm *	newtime;    time_t		t;        time(&t);                /* Get time as long integer. */    newtime = localtime(&t); /* Convert to local time. */        sprintf(szOut, "%d-%02d-%02d %.2d:%.2d:%.2d ABC_Log: ",            newtime->tm_year + 1900,            newtime->tm_mon + 1,            newtime->tm_mday,            newtime->tm_hour, newtime->tm_min, newtime->tm_sec);    va_list	args;    va_start(args, format);    vsprintf(&(szOut[strlen(szOut)]), format, args);    // if it doesn't end in an newline, add it    if (szOut[strlen(szOut) - 1] != '\n')    {        szOut[strlen(szOut) + 1] = '\0';        szOut[strlen(szOut)] = '\n';    }    printf("%s", szOut);    va_end(args);}#elsevoid ABC_DebugLog(const char * format, ...){}#endif// EOF