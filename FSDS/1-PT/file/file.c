#include "../global/global.h"
#include "../struct/struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void save_books(List *head, const char *filename) {
    FILE *file = fopen(filename, "w"); // Open the file in write mode
    if (!file)
        return;

    List *current = head; // Start from the head of the list
    char buffer[256];

    while (current != NULL) {
        // Format the book's details into a single string (buffer)
        snprintf(buffer, sizeof(buffer), "%s,%s,%d\n", current->book.title, current->book.author, current->book.publication_year);
        
        // Write the buffer to the file using fwrite
        fwrite(buffer, sizeof(char), strlen(buffer), file);

        current = current->next;
    }

    fclose(file); // Close the file
}


List* load_books(const char* filename) {
    FILE* file = fopen(filename, "r"); // Open in read mode (text mode)
    if (!file)
        return NULL;

    List* head = NULL;
    List* current = NULL;

    // Buffer for reading lines from the file
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) { // Read line by line
        Book tempBook;
        // Parse the buffer
        sscanf(buffer, "%99[^,],%99[^,],%d", tempBook.title, tempBook.author, &tempBook.publication_year);

        List* new_node = (List*)malloc(sizeof(List));
        if (!new_node) {
            fclose(file);
            return NULL;
        }

        new_node->book = tempBook; // Copy the book data
        new_node->next = NULL;

        // If list is empty, set head to the new node
        if (!head) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    fclose(file);
    return head;
}
