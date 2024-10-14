#ifndef STRUCT_H
#define STRUCT_H

typedef struct Book {
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    int publication_year;
    struct Book *next; 
} Book;

#endif
