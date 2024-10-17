# PT 1: Modular Programming for a Library Management

A simple book management system implemented in C, which allows users to manage a collection of books using a linked list. The program supports adding, editing, deleting, saving, and loading books from a text file.

## Project Structure

```shell
.
├── book
├── books.txt
├── file
│   ├── file.c
│   └── file.h
├── global
│   └── global.h
├── library
│   ├── library.c
│   └── library.h
├── main.c
├── README.md
└── struct
    └── struct.h
```

## Features

- Add new books to the list
- Delete existing books
- Edit book information
- Display the list of books
- Save the current book list to a file
- Load a book list from a file


## Data Structure

The system uses a linked list to manage books. Each book has the following attributes:

- **Title**: The title of the book
- **Author**: The author of the book
- **Publication Year**: The year the book was published

### Book Struct Definition

```c
typedef struct {
    char title[100];
    char author[100];
    int publication_year;
} Book;

typedef struct list {
    Book book;
    struct list *next;
} List;
