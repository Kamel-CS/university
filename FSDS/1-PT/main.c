#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library/library.h"
#include "struct/struct.h"
#include "global/global.h"


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


int main() {
    int choice;
    int status = 0;
    char title[MAX_SIZE];
    List *head = NULL;

    do {
        display_menu();
        scanf("%d", &choice);
        getchar();  // remove leftover '\n' in the input stream
        
        switch (choice) {
            case 1: {
                Book new_book; 

                printf("Enter information of the book:\n");
                printf("\tTitle: ");
                fgets(new_book.title, sizeof(new_book.title), stdin);
                new_book.title[strcspn(new_book.title, "\n")] = '\0';

                printf("\tAuthor: ");
                fgets(new_book.author, sizeof(new_book.author), stdin);
                new_book.author[strcspn(new_book.author, "\n")] = '\0';

                printf("\tPublication year: ");
                scanf("%d", &new_book.publication_year);
                getchar();

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
                    printf("Book not found");
                break;
            }
            case 3: {
                printf("Enter the book's title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';

                Book edited_book;

                printf("Enter the new information:\n");
                printf("\tTitle: ");
                fgets(edited_book.title, sizeof(edited_book.title), stdin);
                edited_book.title[strcspn(edited_book.title, "\n")] = '\0';

                printf("\tAuthor: ");
                fgets(edited_book.author, sizeof(edited_book.author), stdin);
                edited_book.author[strcspn(edited_book.author, "\n")] = '\0';

                printf("\tPublication year: ");
                scanf("%d", &edited_book.publication_year);
                getchar();

                status = 0;
                head = edit_book(head, title, &edited_book, &status);
                if (status == -1)
                    printf("Book not found");
                break;
            }
            case 4: {
                display_books(head);
                break;
            }
           default:
                printf("Invalid choice, Please try again\n");
                break;
        }

    } while(choice != 7);

    return 0;
}
