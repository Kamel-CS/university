#ifndef FILE_H
#define FILE_H

#include "../struct/struct.h"
// function prototypes
void save_books(List *head, const char *filename);
List* load_books(const char *filename);


#endif
