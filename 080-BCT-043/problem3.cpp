#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookTitle;
    string author;
    int numberOfCopies;
    int issuedCopies;

public:
    Library(const string& title, const string& auth, int copies)
        : bookTitle(title), author(auth), numberOfCopies(copies), issuedCopies(0) {}

    void addBook(int additionalCopies) {
        if (additionalCopies < 0) {
            cout << "Cannot add negative copies." << endl;
            return;
        }
        
        numberOfCopies += additionalCopies;
        cout << "Added " << additionalCopies << " copies of " << bookTitle << " by " << author << endl;
    }

    void issueBook(int numCopies) {
        if (numCopies < 0) {
            cout << "Cannot issue negative copies." << endl;
            return;
        }
        if (numberOfCopies >= numCopies) {
            numberOfCopies -= numCopies;
            issuedCopies += numCopies;
            cout << "Issued " << numCopies << " copies of " << bookTitle << " by " << author << endl;
        } else {
            cout << "Not enough copies available for " << bookTitle << " by " << author << endl;
        }
    }

    void returnBook(int numCopies) {
        if (numCopies < 0) {
            cout << "Cannot return negative copies." << endl;
            return;
        }
        if (numCopies <= issuedCopies) {
            numberOfCopies += numCopies;
            issuedCopies -= numCopies;
            cout << "Returned " << numCopies << " copies of " << bookTitle << " by " << author << endl;
        } else {
            cout << "You are trying to return more copies than you have issued. Please try again." << endl;
        }
    }

    void displayBookDetails() const {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies Available: " << numberOfCopies << endl;
    }
};

int main() {
    string bookTitle;
    string author;
    int noc, additional, issueCopies, returnCopies;

    cout << "Enter book title, author name, and number of copies:" << endl;
    getline(cin, bookTitle);
    getline(cin, author);
    cin >> noc;
    cin.ignore();

    Library book1(bookTitle, author, noc);

    book1.displayBookDetails();

    while (true) {
        cout << "1. Add copies\n2. Issue copies\n3. Return copies\n0. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0:
                return 0;
            case 1:
                cout << "Enter number of additional copies: ";
                cin >> additional;
                book1.addBook(additional);
                break;
            case 2:
                cout << "Enter number of copies to issue: ";
                cin >> issueCopies;
                book1.issueBook(issueCopies);
                break;
            case 3:
                cout << "Enter number of copies to return: ";
                cin >> returnCopies;
                book1.returnBook(returnCopies);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        book1.displayBookDetails();
    }

    return 0;
}
