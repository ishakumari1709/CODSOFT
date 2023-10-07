#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isCheckedOut;
    time_t dueDate;

    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isCheckedOut(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
    }

    void searchBook(string query) {
        for (const Book& book : books) {
            if (book.title == query || book.author == query || book.ISBN == query) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << endl;
                if (book.isCheckedOut) {
                    cout << "Status: Checked Out" << endl;
                    cout << "Due Date: " << ctime(&book.dueDate);
                } else {
                    cout << "Status: Available" << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void checkoutBook(string ISBN, int daysToReturn) {
        for (Book& book : books) {
            if (book.ISBN == ISBN && !book.isCheckedOut) {
                book.isCheckedOut = true;
                time(&book.dueDate);
                book.dueDate += daysToReturn * 24 * 60 * 60; // Convert days to seconds
                cout << "Book checked out successfully. Due Date: " << ctime(&book.dueDate);
                return;
            }
        }
        cout << "Book not available for checkout." << endl;
    }

    void returnBook(string ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN && book.isCheckedOut) {
                book.isCheckedOut = false;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not available for return." << endl;
    }
};

int main() {
    Library library;

    library.addBook("Book1", "Author1", "ISBN1");
    library.addBook("Book2", "Author2", "ISBN2");
    library.addBook("Book3", "Author3", "ISBN3");

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Checkout a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter title, author, or ISBN: ";
            string query;
            cin >> query;
            library.searchBook(query);
        } else if (choice == 2) {
            cout << "Enter ISBN of the book to checkout: ";
            string ISBN;
            cin >> ISBN;
            library.checkoutBook(ISBN, 14); // Assume a 14-day checkout period
        } else if (choice == 3) {
            cout << "Enter ISBN of the book to return: ";
            string ISBN;
            cin >> ISBN;
            library.returnBook(ISBN);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

