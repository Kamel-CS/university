#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library/library.h"
#include "struct/struct.h"
#include "global/global.h"
#include "file/file.h"


void display_menu() {
    printf("\n");
    printf("   * * * * * * * * * * * * * * * * * * * *\n");
    printf("   *           Book Manager               *\n");
    printf("   * * * * * * * * * * * * * * * * * * * *\n");
    printf("   *                                       *\n");
    printf("   *  1. Add a book                       *\n");
    printf("   *  2. Delete a book                    *\n");
    printf("   *  3. Edit a book                      *\n");
    printf("   *  4. Display the list of books        *\n");
    printf("   *  5. Save the books to a file         *\n");
    printf("   *  6. Load the books from a file       *\n");
    printf("   *  7. Quit                             *\n");
    printf("   *                                       *\n");
    printf("   * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("\nChoose an action: ");
}


Book book_input() {
    Book new_book;

    printf("\tTitle: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';

    printf("\tAuthor: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';

    printf("\tPublication year: ");
    scanf("%d", &new_book.publication_year);
    getchar();

    return new_book;
}


int main() {
    int choice;
    int status = 0;
    char title[MAX_SIZE];
    List *head = NULL;
    const char* filename = "books.txt";

    do {
        display_menu();
        scanf("%d", &choice);
        getchar();  // remove leftover '\n' in the input stream
        
        switch (choice) {
            case 1: {
                printf("Enter information of the book:\n");
                Book new_book = book_input();

                status = 0;
                head = add_book(head, &new_book, &status);
                if (status == -1)
                    printf("Memory allocation failed");
                break;
            }
            case 2: {
                printf("Enter the book's title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; 
                
                status = 0;
                head = delete_book(head, title, &status);
                if (status == -1)
                    printf("List is empty");
                else if (status == 1)
                    printf("Book not found");
                break;
            }
            case 3: {
                printf("Enter the book's title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Enter the new information:\n");
                Book edited_book = book_input();
                
                status = 0;
                head = edit_book(head, title, &edited_book, &status);
                if (status == -1)
                    printf("Book not found");
                break;
            }
            case 4:
                if (head == NULL)
                    printf("List is empty");
                else
                    display_books(head);
                break;

            case 5: 
                save_books(head, filename);
                break;
            
            case 6:
                if (head != NULL) {
                    printf("You have unsaved books!\n");
                    printf("Loading the file before saving will cause data loss!\n");

                    char ch;
                    printf("Do you want to save before loading (y/n)? ");
                    scanf(" %c", &ch);

                    if (ch == 'y' || ch == 'Y')
                        save_books(head, filename);
                    else {
                        printf("Unsaved books will be lost. Proceeding without saving.\n");
                        head = NULL; // Discard the current list
                    }
                }
                head = load_books(filename);
                break;

            case 7:
                printf("Quitting the program...\n");
                break;

           default:
                printf("Invalid choice, Please try again\n");
                break;
        }

    } while(choice != 7);

    return 0;
}
