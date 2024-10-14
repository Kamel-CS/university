#include "../global/global.h"
#include "../struct/struct.h"
#include <stdlib.h>
#include <string.h>


Book* add_book(Book* head, Book* new_book) {
    new_book->next = head;
    head = new_book;

    return head;
}


Book* delete_book(Book* head, char *title) {
    // case 1: pop operation (element to delete is head)
    if (strcmp(head->title, title) == 0) {
        Book* temp = head->next;
        head = head->next;
        free(temp);
        return head;
    }    

    // case 2: element to delete is not head
    Book* current = head->next;
    Book* previous = head;

    while (current != NULL) { 
        if (strcmp(head->title, title) == 0) {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
}


Book* edit_book(head *Book, char* title, Book* edited_book) {
    Book* current = head;
    
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            current->title = edit_book->title;
            current->author = edit_book->author;
            current->publication_year = edit_book->publication_year;
        } 
    } 
    return head;
}
