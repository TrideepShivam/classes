/*
 * book.h
 * Header collecting Book structure and function declarations
 */

#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char B_name[100];
    char Author[50];
    int price;
    char Genere[50];
    int B_count;
    int Book_ID;
} Book;

/* Function prototypes from book.c */
void B_Register(Book B_R);
Book B_Retrive(int id);
void get_book_by_author(const char *author);
int get_ID(void);
void get_book_by_genere(const char *genere);
void get_book_by_name(const char *name);
Book Showall_Book ();
#endif /* BOOK_H */
