/*
 * config.h
 * Centralized common structures for the Library Management System
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Common data structures shared across the Library Management System
typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int hr;
	int min;
	int sec;
} Time;

typedef struct {
	char B_name[100];
	char Author[50];
	int price;
	char Genere[50];
	int B_count;
	int Book_ID;
} Book;

typedef struct {
	int id;
	char Name[50];
	char contact[11];
	char email[50];
	Date doj;
	Date doe;
} Candidate;

typedef struct {
	int id;
	int amount;
	Time time;
	Date date;
} Transaction;

typedef struct {
	int C_ID;
	int B_ID;
	Time entry;
	Time exit;
	Date date;
} LiveReading;

typedef struct {
	int C_ID;
	int B_ID;
	Date DOI;
	Date DOR;
} BookKeeping;

void setCurrentDateTime(Date *d, Time *t);

#endif /* CONFIG_H */
