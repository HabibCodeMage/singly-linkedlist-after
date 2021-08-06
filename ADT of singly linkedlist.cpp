// singly linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"singlylinkedlist.h"
using namespace std;
int main()
{
    singlylinkedlist<double> linkedlist;
    char flag = ' ';
    do
    {

        cout << "enter A to append node\n";
        cout << "enter D to delete node\n";
        cout << "enter I to insert \n";
        cout << "enter U to update \n";
        cout << "enter e to exit\n";
        cin.get(flag);
        cin.ignore();
        while (toupper(flag) != 'E' && toupper(flag) != 'D' && toupper(flag) != 'U' && toupper(flag) != 'A'  && toupper(flag) != 'I')
        {
            cout << "enter A to append node\n";
            cout << "enter D to delete node\n";
            cout << "enter I to insert \n";
            cout << "enter U to update \n";
            cout << "enter e to exit\n";
            cin.get(flag);
            cin.ignore();
        }
        if (toupper(flag) == 'A')
        {
            double num;
            cout << "enter value to append node\n";
            cin >> num;
            cin.ignore();
            linkedlist.appendnode(num);
        }
        else if (toupper(flag) == 'D')
        {

            double num;
            cout << "enter value to delete node\n";
            cin >> num;
            cin.ignore();
            linkedlist.deletenode(num);
        }
        else if (toupper(flag) == 'I')
        {

            double num;
            cout << "enter value to insert \n";
            cin >> num;
            cin.ignore();
            linkedlist.insertnode(num);
        }
        else if (toupper(flag) == 'U')
        {

            double num,
                    num2;
            cout << "enter value which you want to update \n";
            cin >> num;
            cout << "enter new value you want to replace the previous\n";
            cin >> num2;
            cin.ignore();
            linkedlist.update(num,num2);
        }
        else
        {
            break;
        }


    } while (toupper(flag) != 'E');

    linkedlist.printvalues();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
