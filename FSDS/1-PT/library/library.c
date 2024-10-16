#include "../global/global.h"
#include "../struct/struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


List* add_book(List* head, Book* new_book, int* status) {
    List* new_node = malloc(sizeof(List));
    if (new_node == NULL) {
        *status = -1;
        return head;
    }
        
    new_node->book = *new_book;  // copying the book data
    new_node->next = head;

    return new_node;  // returns new head
}


List* delete_book(List* head, const char *title, int *status) {
    if (head == NULL) {
        *status = -1;   // List is empty
        return head;
    }
        
    // case 1: pop operation (element to delete is head)
    if (strcmp(head->book.title, title) == 0) {
        List* temp = head->next;
        free(head);
        return temp; // return new head
    }    

    // case 2: element to delete is not head
    List* current = head->next;
    List* previous = head;

    while (current != NULL) { 
        if (strcmp(head->book.title, title) == 0) {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    *status = -1;   // not found
    return head;
}


List* edit_book(List* head, char* title, Book* edited_book, int *status) {
    List* current = head;
    
    while (current != NULL) {
        if (strcmp(current->book.title, title) == 0) {
            strcpy(current->book.title, edited_book->title);
            strcpy(current->book.author, edited_book->author);
            current->book.publication_year = edited_book->publication_year;
            return head;
        } 
        current = current->next;
    } 
    *status = -1;
    return head;
}

void display_books(List* head) {
    List* current = head;
    while(current != NULL) {
        printf("[%s, %s, %d]\n", current->book.title, current->book.author, current->book.publication_year);
        current = current->next;
    }
}
