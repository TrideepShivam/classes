/*
 * candidate.h
 * Header collecting Candidate structures and function declarations
 */

#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char Name[50];
    char contact[11];
    char email[50];
    Date doj;
    Date doe;
} Candidate;

/* Function prototypes */
void registerCandidate(Candidate c);
void showCandidate(void);
Candidate getCandidateById(int id);

#endif /* CANDIDATE_H */
