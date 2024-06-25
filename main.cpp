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

int main(){
    ticket t1;
    string seatarr[50] = {};
    string tname, phone;

    int departopt, arrivalopt, chosenmonth, chosenday, chosentime, tickets, select1;
    char selection;

    main_menu:
    cout<<endl;
    cout<<"\t #   #  #      #     # ##### #     ##### ###### ##   ## ######    ** **      "<<endl;
    cout<<"\t #   #  #      #     # #     #     #     #    # # # # # #        *  *  *     "<<endl;
    cout<<"\t #####  #      #  #  # ####  #     #     #    # #  #  # #####    *     *     "<<endl;
    cout<<"\t #   #  #      # # # # #     #     #     #    # #     # #         *   *      "<<endl;
    cout<<"\t #   #  #  ,   ##   ## ##### ##### ##### ###### #     # ######      *        "<<endl;
    cout<<endl;

    cout << "\t\t  ==================================================" << endl;
    cout << "\t\t  ||    WELCOME TO XXX TRAIN TICKETING SYSTEM     ||" << endl;
    cout << "\t\t  ==================================================" <<endl;
    cout << "\t\t  ||        Please choose your selection:         ||\n";
    cout << "\t\t  ||                                              ||\n";
    cout << "\t\t  || (1) Purchase Ticket                          ||\n";
    cout << "\t\t  || (2) View All Records                         ||\n";
    cout << "\t\t  || (3) Edit Booking Record                      ||\n";
    cout << "\t\t  || (4) Delete Booking Record                    ||\n";
    cout << "\t\t  || (5) Exit System                              ||\n";
    cout << "\t\t  ==================================================\n" <<endl;

    while (true)
    {
    cout << "Please choose: ";
    cin >> select1;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid choice! Choose number 1-5 only." << endl;
        system("pause");
        system("cls");
        goto main_menu;
    }

    else
    {
        if(select1==1){
        t1.departurestation(departopt);
        t1.ticketprice();
        t1.arrivalstation(arrivalopt);
        t1.dateselection(chosenmonth, chosenday);
        t1.timeselection(chosentime);
        t1.seatselection(tickets,seatarr);
        t1.personalinfo(tname, phone);
        t1.confirmation(tname,phone,departopt,arrivalopt,chosenmonth,chosenday,chosentime,tickets,seatarr);
        t1.payment(arrivalopt, tickets);
        cout << "Return to main menu? (y/Y)" << endl;
        cin >> selection;
        if(selection=='y' || selection=='Y'){
            system("cls");
            goto main_menu;
        }
        else{
            exit(0);
        }
        }

        else if(select1==2){
            t1.viewbooking();
            cout << "Return to main menu? (y/Y)" << endl;
            cin >> selection;
            if(selection=='y' || selection=='Y'){
                system("cls");
                goto main_menu;
            }
            else{
                exit(0);
            }
        }

        else if(select1==3){
            t1.editbooking();
            cout << "Return to main menu? (y/Y)" << endl;
            cin >> selection;
            if(selection=='y' || selection=='Y'){
                system("cls");
                goto main_menu;
            }
            else{
                exit(0);
            }
        }

        else if(select1==4){
            t1.deletebooking();
            cout << "Return to main menu? (y/Y)" << endl;
            cin >> selection;
            if(selection=='y' || selection=='Y'){
                system("cls");
                goto main_menu;
            }
            else{
                exit(0);
            }
        }

        else if(select1==5){
            exit(0);
        }

        else{
            cout << "Invalid choice! Enter 1-5 only." << endl;
            system("pause");
            system("cls");
            goto main_menu;
        }
        return 0;

        break;
    }
    }
}
