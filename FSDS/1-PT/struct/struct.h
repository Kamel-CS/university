#ifndef STRUCT_H
#define STRUCT_H

typedef struct Book{
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    int publication_year;
} Book;

typedef struct List {
    Book book;
    struct List* next;
} List;

#endif
