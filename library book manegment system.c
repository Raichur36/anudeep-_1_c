#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

#define MAX_BOOKS 100

void addBook(Book books[], int *count);
void searchBook(Book books[], int count);
void deleteBook(Book books[], int *count);
void displayBooks(Book books[], int count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0; 
    int choice;

    do {
        
        printf("\nLibrary Book Management System\n");
        printf("----------------------------------\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                searchBook(books, count);
                break;
            case 3:
                deleteBook(books, &count);
                break;
            case 4:
                displayBooks(books, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &books[*count].id);
    printf("Enter book title: ");
    getchar(); // To consume newline left by scanf
    fgets(books[*count].title, 100, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0'; // Remove newline
    printf("Enter book author: ");
    fgets(books[*count].author, 100, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(Book books[], int count) {
    int id;
    printf("Enter the book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Book found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook(Book books[], int *count) {
    int id, found = 0;
    printf("Enter the book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            found = 1;
            // Shift remaining books left
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n\n", books[i].author);
    }
}
