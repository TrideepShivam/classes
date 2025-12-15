/*
 * candidate.h
 * Header collecting Candidate structures and function declarations
 */

#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "../config.h"

/* Function prototypes */
void registerCandidate(Candidate c);
void showCandidate(void);
Candidate getCandidateById(int id);
Candidate getCandidateByContact(char *Contact);

#endif /* CANDIDATE_H */
