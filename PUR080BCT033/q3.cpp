/*

3. Define a class Library with bookTitle,author, and numberOfCopies as data members. Implement method to add new books, issue books,and return books.Ensure that the number of copies is appropiately updated for each opertaion.


*/
#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    int bookID;
    std::string bookTitle;
    std::string author;
    int numberOfCopies;

    Book(int id, std::string title, std::string author, int copies)
        : bookID(id), bookTitle(title), author(author), numberOfCopies(copies) {}
};

class Library {
private:
    std::vector<Book> books;
    int nextID = 1;  // To generate unique IDs for books

public:
    // Method to add a new book to the library
    void addBook(std::string title, std::string author, int copies) {
        for (auto &book : books) {
            if (book.bookTitle == title && book.author == author) {
                book.numberOfCopies += copies;
                std::cout << "Updated the number of copies for the book: " << title << std::endl;
                return;
            }
        }
        books.push_back(Book(nextID++, title, author, copies));
        std::cout << "Added new book: " << title << std::endl;
    }

    // Method to issue a book (decrease the number of copies)
    void issueBook(int id) {
        for (auto &book : books) {
            if (book.bookID == id) {
                if (book.numberOfCopies > 0) {
                    book.numberOfCopies--;
                    std::cout << "Issued book: " << book.bookTitle << std::endl;
                } else {
                    std::cout << "No copies available for book: " << book.bookTitle << std::endl;
                }
                return;
            }
        }
        std::cout << "Book not found with ID: " << id << std::endl;
    }

    // Method to return a book (increase the number of copies)
    void returnBook(int id) {
        for (auto &book : books) {
            if (book.bookID == id) {
                book.numberOfCopies++;
                std::cout << "Returned book: " << book.bookTitle << std::endl;
                return;
            }
        }
        std::cout << "Book not found with ID: " << id << std::endl;
    }

    // Method to display all books in the library
    void displayBooks() {
        std::cout << "Books available in the library:" << std::endl;
        for (const auto &book : books) {
            std::cout << "ID: " << book.bookID << ", Title: " << book.bookTitle 
                      << ", Author: " << book.author << ", Copies: " << book.numberOfCopies << std::endl;
        }
    }
};

int main() {
    Library library;
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", 5);
    library.addBook("1984", "George Orwell", 3);
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 4);

    library.displayBooks();

    library.issueBook(2);  // Issue the book with ID 2
    library.returnBook(1);  // Return the book with ID 1

    library.displayBooks();

    std::cin.get();

    return 0;
}
