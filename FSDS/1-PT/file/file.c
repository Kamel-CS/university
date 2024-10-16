#include "../global/global.h"
#include "../struct/struct.h"
#include <stdlib.h>


void save_books(List *head, const char *filename) {
    FILE *file = fopen(filename, "w"); // Open the file in write mode
    if (!file)
        return;

    List *current = head; // Start from the head of the list
    while (current != NULL) {
        // Write the book fields separated by commas
        fprintf(file, "%s,%s,%d\n", current->book.title, current->book.author, current->book.publication_year);
        current = current->next; // Move to the next node
    }

    fclose(file); // Close the file
}
