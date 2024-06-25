#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <cctype>
#include  <bits/stdc++.h>
#include "ticket.hpp"
#include "misc.hpp"
#include "Linkedlist.hpp"
using namespace std;

void misc::wrongInput()
{
    cout << "Number please" << endl;
    cin.clear ();
    cin.ignore(123,'\n');
    system("pause");
    system("cls");
}
void misc::payment()
{
   cout << "\t\t  ==================================================" << endl;
    cout << "\t\t  ||Please Choose a Payment Method for your Ticket ||" << endl;
    cout << "\t\t  ==================================================" <<endl;
    cout << "\t\t  ||        Please choose your selection:         ||\n";
    cout << "\t\t  ||                                              ||\n";
    cout << "\t\t  || (1) Cash                                     ||\n";
    cout << "\t\t  || (2) Credit/Debit Card                        ||\n";
    cout << "\t\t  ==================================================\n" <<endl;
    cout << "Please choose: ";
}
bool misc::check_number(string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

