#include <iostream>
#include <cstring>
using namespace std;

class Library
{
private:
    string bookTitle, author;
    int option;
    static int numberofCopies;

public:
    void interface()
    {

        while (1)
        {
            cout << "Welcome to the Library" << endl;
            cout << "1. Add a book" << endl;
            cout << "2. Issue a book" << endl;
            cout << "3.Return a book" << endl;
            cout << "4. Exit" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "\n";
                addNewBooks();
                cout << "\n";
                break;
            case 2:
                cout << "\n";
                issueBooks();
                cout << "\n";
                break;
            case 3:
                cout << "\n";
                returnBooks();
                cout << "\n";
                break;
            case 4:
                exit(0);

            default:
                cout << "\n";
                cout << "Invalid input";
                break;
            }
        }
    }
    void input()
    {
        cout << "\n";
        cout << "Enter the booktitle: ";
        cin >> bookTitle;
        cout << "Enter the author: ";
        cin >> author;
        cout << "Enter the number of copies: ";
        cin >> numberofCopies;
        cout << "\n";
        output();
        cout << "\n";
    }
    void output()
    {
        cout << "\n";
        cout << "Book title: " << bookTitle << endl
             << "Author: " << author << endl
             << "Number of copies in stock: " << numberofCopies;
        cout << "\n";
    }
    void addNewBooks()
    {
        int num;
        cout << "\n";
        cout << "How many new books are to be added: ";
        cin >> num;
        Library L;
        // Library *ptr[num];
        for (int i = 0; i < num; i++)
        {
            cout << "\n";
            // ptr[i] = new Library;
            L.input();
            cout << "\n";
            output();
            cout << "\n";

            // ptr[i]->input();
        }
    }

    void issueBooks()
    {
        cout << "\n";
        cout << "Enter the booktitle: " << endl;
        cin >> bookTitle;
        cout << "Enter the author: " << endl;
        cin >> author;

        if (this->bookTitle == bookTitle && this->author == author)
        {
            cout << "\n";
            cout << "Book issued";
            numberofCopies--;
            cout << "\n";
            output();
            cout << "\n";
        }
        else
        {
            cout << "\n";
            cout << "Book not found";
            cout << "\n";
        }
    }

    void returnBooks()
    {
        cout << "\n";
        cout << "Enter the booktitle: " << endl;
        cin >> bookTitle;
        cout << "Enter the author:" << endl;
        cin >> author;
        if (this->bookTitle == bookTitle && this->author == author)
        {
            cout << "Book returned";
            numberofCopies++;
            output();
            cout << "\n";
        }
    }
};

int Library::numberofCopies = 0;

int main()
{
    Library obj;
    obj.interface();
    //     int n;
    //     cout << "Enter the daily book transaction limit of library: ";
    //     cin >> n;
    //     Library *obj1[n];

    //     for (int i = 0; i < n; i++)
    //     {
    //         obj1[i] = new Library;
    //         obj1[i]->interface();
    //     }
    return 0;
}