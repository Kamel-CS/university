#ifndef LIBRARY_H
#define LIBRARY_H

#include "../global/global.h"
#include "../struct/struct.h"
// function prototypes
List* add_book(List* head, Book* new_book, int* status);
List* delete_book(List* head, const char *title, int *status);
List* edit_book(List* head, char* title, Book* edited_book, int *status);
void display_books(List* head);

#endif
