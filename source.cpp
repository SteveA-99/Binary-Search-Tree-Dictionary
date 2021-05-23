/*
CS281 - Spring 2020
Phone Book
Steven Awakem
5 / 8 / 20
This is a dictionary that uses a binary search tree to add and search words
*/

#include <iostream>
#include "dictionary.h"
using namespace std;
int menu();
void pauseScreen2();
void pauseScreen();
void clearScreen();
int main()
{
    int choice = 0;
    dictionary d;
    string w;
    string def;
    do {
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "What word do you want to find?" << endl;
            cin >> w;
            d.searchWord(w);
            pauseScreen();
            clearScreen();
            break;
        case 2:
            cout << "Type the word:" << endl;
            cin.clear();
            cin.sync();
            cin.ignore(256,'\n');
            getline(cin, w);          
            cout << "def" << endl;
            getline(cin, def);
            d.addWord(w, def);
            pauseScreen2();
            clearScreen();
            break;
        case 3:
            d.displayWord();
            pauseScreen();
            clearScreen();
            break;

        }
    } while (choice != 4);




    return 0;
}


int menu()
{
    int choice;
    cout << "Menu" << endl;
    cout << "---------" << endl;
    cout << "1. Search for definition" << endl;
    cout << "2. Add word" << endl;
    cout << "3. Display list" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;

    while (choice < 1 or choice > 5)
    {
        cout << "Enter a valid menu item" << endl;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        cin >> choice;
    }
    return choice;

}
void pauseScreen2()
{
    cout << "Enter to continue!" << endl;
    cin.get();
}
void pauseScreen()
{
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter to continue!" << endl;
    cin.get();
}

void clearScreen()
{

    system("CLS");
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}








