/*
 * book.h
 * Header collecting Book structure and function declarations
 */

#ifndef BOOK_H
#define BOOK_H

#include "../config.h"

/* Function prototypes from book.c */
void B_Register(Book B_R);
Book B_Retrive(int id);
void get_book_by_author(const char *author);
int get_ID(void);
void get_book_by_genere(const char *genere);
void get_book_by_name(const char *name);
Book Showall_Book (void);
void is_available(int id);
#endif /* BOOK_H */
