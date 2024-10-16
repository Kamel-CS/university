#include "../global/global.h"
#include "../struct/struct.h"


void save_books(Book* head, string* file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL)
        return;

    Book* current = head;
    while (current != NULL) {
        fprintf(file, "%s,%s,%d\n", file_name);
        current = current->next;
    }

    fclose(file_name);
}


Book* load_books(string* file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
        return NULL;

    Book* head = NULL, current = NULL;
}
