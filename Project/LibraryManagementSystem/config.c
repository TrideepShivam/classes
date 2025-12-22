// Centralized definitions live in config.h
#include "config.h"
#include <time.h>

void setCurrentDateTime(Date *d, Time *t)
{
	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);

	// Update Date
	d->day = timeinfo->tm_mday;
	d->month = timeinfo->tm_mon + 1;	// tm_mon is 0–11
	d->year = timeinfo->tm_year + 1900; // tm_year is years since 1900

	// Update Time
	t->hr = timeinfo->tm_hour;
	t->min = timeinfo->tm_min;
	t->sec = timeinfo->tm_sec;
}