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

Linkedlist l;
ticket t1;

bool seat[12][4];   //all array elements default set to 0

bool seatoccupied[12][4] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};

void ticket::displayseat(bool seat[12][4]){
    cout<<"\t"<<endl;
    cout<<"=================================="<<endl;
    cout<<"\t";
    for(int i=0;i<4;i++){
        cout<<1+i<<"\t";      //only loop the first statements, which is 1 -> 4
    }

        cout<<endl;

    for(int i=0;i<12;i++){          //ROWS (if there are two nested for loops)
        cout<<" "<<i+1<<"\t";
        for(int j=0;j<4;j++){       //COLUMNS (if there are two nested for loops)
            if(seat[i][j])
                cout<<"-\t";
            else
                cout<<"X\t";
        }
        cout<<"\n";                 //Spacing between ROWS
    }
    cout<<"=================================="<<endl;
    cout<<"\n";
}

int ticket::available(int type, int seatNum){      	//seatNum = Numbers, type = 1,2,3 or 4
    if(type == 1){
            if(seat[seatNum-1][1-1]){         //-1 as it is an array
                    seat[seatNum-1][1-1] = 0; //0 means the seat is available
            return true;
            }
    }
    if(type == 2){
            if(seat[seatNum-1][2-1]){
                    seat[seatNum-1][2-1] = 0;
            return true;
            }
    }
        if(type == 3){
            if(seat[seatNum-1][3-1]){
                    seat[seatNum-1][3-1] = 0;
            return true;
            }
    }
        if(type == 4){
            if(seat[seatNum-1][4-1]){
                    seat[seatNum-1][4-1] = 0;
            return true;
            }
    }
    return false;
}

string ticket::concate(int row, int column){            //concatenate seat row and column of seat selected
    string seatselected;

    seatselected = to_string(row) + to_string(column);
    return seatselected;
}

void ticket::departurestation(int &depart){
    string dep_station1, dep_station2, dep_station3;
    system("cls");

    depart_select:
    dep_station1 = "KL Sentral";
    dep_station2 = "Butterworth Train Station, Pulau Pinang";
    dep_station3 = "Batu Gajah Train Station, Perak";
    cout<<"=================================================="<<endl;
    cout<<"||\t\t Departure Station \t\t||"<<endl;
    cout<<"=================================================="<<endl;
    cout<<"|| Please choose your departure station:        ||\n";
    cout<<"||                                              ||\n";
    cout<<"|| 1. KL Sentral                                ||\n";
    cout<<"|| 2. Butterworth Train Station, Pulau Pinang   ||\n";
    cout<<"|| 3. Batu Gajah Train Station, Perak           ||\n";
    cout<<"==================================================\n"<<endl;

    while (true)
    {
        cout<<"Enter your option (1/2/3): ";
        cin>>depart;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose number 1-3 only." << endl;
            system("pause");
            system("cls");
            goto depart_select;
        }

        else
        {
            char confirmdepart;
            cout<<"\n";

            switch(depart)
            {
                case 1:
                    cout << "-> " << dep_station1 << endl;
                    goto dept_confirmation;
                    break;

                case 2:
                    cout << "-> " << dep_station2 << endl;
                    goto dept_confirmation;
                    break;

                case 3:
                    cout << "-> " << dep_station3 << endl;
                    goto dept_confirmation;
                    break;

                default:
                    cout << "Error! Invalid option\n" << endl;
                    system("pause");
                    system("cls");
                    goto depart_select;
                    break;
            }

            dept_confirmation:
            cout<<"\nFor confirmation, please press (Y/y) to continue to arrival station selection or (N/n) to select the departure station again.\n";
            cout<<"Your choice: ";
            cin>>confirmdepart;

            if (confirmdepart == 'Y' || confirmdepart == 'y')
            {
                cout<<"";
            }
            else if (confirmdepart == 'N' || confirmdepart == 'n')
            {
                system("pause");
                system ("cls");
                goto depart_select;
            }
            else
            {
                cout<<"Invalid input! Enter Y/y or N/n only.\n";
                system("pause");
                cout<<endl;
                goto dept_confirmation;
            }
            system("cls");
            break;
        }
    }
}

void ticket::ticketprice (){
    cout << "=============================================================" << endl;
    cout << "||                      Ticket Price                       ||" << endl;
    cout << "=============================================================" << endl;
    cout << "|| Ticket to Ipoh Train Station, Perak : RM10              ||\n";
    cout << "|| Ticket to Sungai Petani Train Station, Kedah : RM12     ||\n";
    cout << "|| Ticket to Gemas Train Station, Negeri Sembilan : RM15   ||\n";
    cout << "=============================================================" << endl;
    cout << "\n" << endl;

}

void ticket::arrivalstation(int &arrival){
    string arr_station1, arr_station2, arr_station3;
    char arrival_confirm;
    ticket repeat;

    select_arrival:
    arr_station1 = "Ipoh Train Station, Perak";
    arr_station2 = "Sungai Petani Train Station, Kedah ";
    arr_station3 = "Gemas Train Station, Negeri Sembilan";
    cout << "==================================================" << endl;
    cout << "||\t\t Arrival Station \t\t||" << endl;
    cout << "==================================================" <<endl;
    cout << "|| Please choose your arrival station:          ||\n";
    cout << "||                                              ||\n";
    cout << "|| 1. Ipoh Train Station, Perak                 ||\n";
    cout << "|| 2. Sungai Petani Train Station, Kedah        ||\n";
    cout << "|| 3. Gemas Train Station, Negeri Sembilan      ||\n";
    cout << "==================================================\n" <<endl;

    while (true)
    {
        cout << "Enter your option (1/2/3): ";
        cin >> arrival;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose 1-3 only." << endl;
            system("pause");
            system("cls");
            repeat.ticketprice();
            goto select_arrival;
        }

        else
        {
            cout << "\n";

            switch(arrival){
                case 1:
                    cout << "-> " << arr_station1 << endl;
                    goto arriv_confirmation;
                    break;
                case 2:
                    cout << "-> " << arr_station2 << endl;
                    goto arriv_confirmation;
                    break;

                case 3:
                    cout << "-> " << arr_station3 << endl;
                    goto arriv_confirmation;
                    break;

                default:
                    cout << "Error! Invalid option\n" << endl;
                    system("pause");
                    system("cls");
                    repeat.ticketprice();
                    goto select_arrival;
                    break;
            }

            arriv_confirmation:
            cout<<"\nFor confirmation, please press (Y/y) to continue to date selection or (N/n) to select the arrival station again.\n";
            cout<<"Your choice: ";
            cin>>arrival_confirm;

            if (arrival_confirm == 'Y' || arrival_confirm == 'y')
            {
                cout<<"";
            }
            else if (arrival_confirm == 'N' || arrival_confirm == 'n')
            {
                system("pause");
                system ("cls");
                repeat.ticketprice();
                goto select_arrival;
            }
            else
            {
                cout<<"Invalid input! Enter Y/y or N/n only.\n";
                system("pause");
                cout<<endl;
                goto arriv_confirmation;
            }
            break;
        }
    }
}

void ticket::dateselection(int &dep_month, int &dep_day){
    time_t mth = time(0);
    tm *themth = gmtime (&mth);
    char date_confirm;

    system("cls");
    select_date:
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"\t\t Choose the date of your departure \t\t"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<" __________________________________________________________"<<endl;
    cout<<"| As of now, our company allows booking for the upcoming   |\n";
    cout<<"|         3 months from the date of booking only.          |\n";
    cout<<"|                                                          |\n";
    cout<<"| Today's date is "<<__DATE__<<"                              |\n";
    cout<<"|                                                          |\n";
    cout<<"| Choose the month of your departure:                      |\n";
    cout<<"| 1. The current month: "<<themth ->tm_mon + 1<<setw(36)<<"  |\n";
    cout<<"| 2. The next month: "<<themth -> tm_mon + 2<<setw(39)<<"  |\n";
    cout<<"| 3. The next 2 months: "<<themth -> tm_mon + 3<<setw(36)<<"  |\n";
    cout<<"|__________________________________________________________|\n"<<endl;

    while (true)
    {
        cout<<"Enter the month of your choosing (1/2/3): ";
        cin>>dep_month;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose 1-3 only." << endl;
            system("pause");
            system("cls");
            goto select_date;
        }

        else
        {
            if (dep_month==1)
            {
                cout<<"Enter the date of your choosing after today's date ("<<themth->tm_mday<<"/"<<themth->tm_mon+1<<"): ";
                cin>>dep_day;

                if (dep_day<1 || dep_day>=32)
                {
                    cout<<"\nInvalid option! Please enter a valid date."<<endl;
                    system("pause");
                    system("cls");
                    goto select_date;
                }
                else if (dep_day == themth->tm_mday)
                {
                    cout<<"\nSorry! You cannot book a ticket that departs today.\n";
                    cout<<"Choose again.\n";
                    system("pause");
                    system("cls");
                    goto select_date;
                }
                else if (dep_day < themth->tm_mday)
                {
                    cout<<"\nInvalid! You cannot book a ticket for the date that already passed.\n";
                    cout<<"Choose again.\n";
                    system("pause");
                    system("cls");
                    goto select_date;
                }

                dep_month = themth->tm_mon+1;

                goto date_confirmation;

            }
            else if (dep_month == 2)
            {
                cout<<"Enter the date of your choosing: ";
                cin>>dep_day;

                if (dep_day<1 || dep_day>=29)
                {
                    cout<<"\nInvalid option! Please enter a valid date."<<endl;
                    system("pause");
                    system("cls");
                    goto select_date;
                }

                dep_month = themth->tm_mon+2;

                goto date_confirmation;

            } else if (dep_month == 3)
            {
                cout<<"Enter the date of your choosing: ";
                cin>>dep_day;

                if (dep_day<1 || dep_day>=32)
                {
                    cout<<"\nInvalid option! Please enter a valid date."<<endl;
                    system("pause");
                    system("cls");
                    goto select_date;
                }

                dep_month = themth->tm_mon+3;

                goto date_confirmation;
            } else
            {
                cout << "Error! Invalid option\n" << endl;
                system("pause");
                system("cls");
                goto select_date;
            }

        date_confirmation:
            if (dep_month==1)
            {
                cout<<"The date you chose is "<<dep_day<<"/"<<themth->tm_mon+1<<".\n\n";

            } else if (dep_month==2)
            {
                cout<<"The date you chose is "<<dep_day<<"/"<<themth->tm_mon+2<<".\n\n";

            } else if (dep_month==3)
            {
                cout<<"The date you chose is "<<dep_day<<"/"<<themth->tm_mon+3<<".\n\n";
            }

            cout<<"For confirmation, please press (Y/y) to continue to time selection or (N/n) to select the date again.\n";
            cout<<"Your choice: ";
            cin>>date_confirm;

            if (date_confirm == 'Y' || date_confirm == 'y')
            {

            }
            else if (date_confirm == 'N' || date_confirm == 'n')
            {
                system("pause");
                system ("cls");
                goto select_date;
            }
            else
            {
                cout<<"Invalid input! Enter Y/y or N/n only.\n";
                system("pause");
                cout<<endl;
                goto date_confirmation;
            }
        break;
        }
    }

}

void ticket::timeselection(int &dep_time){
    char time_confirm;

    system("cls");
    select_time:
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"\t\t Choose the time of your departure \t\t"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<" __________________________________________________________"<<endl;
    cout<<"|   There are only three (3) departure timing available.   |\n";
    cout<<"|                                                          |\n";
    cout<<"| Choose the timing of your departure (in military time):  |\n";
    cout<<"| 1. 1000 hour                                             |\n";
    cout<<"| 2. 1500 hour                                             |\n";
    cout<<"| 3. 2000 hour                                             |\n";
    cout<<"|__________________________________________________________|\n"<<endl;

    while (true)
    {
        cout<<"Enter the timing of your choosing: ";
        cin>>dep_time;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose 1-3 only." << endl;
            system("pause");
            system("cls");
            goto select_time;
        }

        else
        {
            if (dep_time == 1)
            {
                cout<<"You've chosen to depart at 1000 hour!\n";
                goto time_confirmation;

            } else if (dep_time == 2)
            {
                cout<<"You've chosen to depart at 1500 hour!\n";
                goto time_confirmation;

            } else if (dep_time == 3)
            {
                cout<<"You've chosen to depart at 2000 hour!\n";
                goto time_confirmation;

            } else if (dep_time<1 || dep_time>3)
            {
                cout<<"Invalid input! Please enter a valid option (1/2/3).\n";
                system("pause");
                system("cls");
                goto select_time;
            }

            time_confirmation:
            cout<<"\nFor confirmation, please press (Y/y) to continue to seat selection or (N/n) to select the timing again.\n";
            cout<<"Your choice: ";
            cin>>time_confirm;

            if (time_confirm == 'Y' || time_confirm == 'y')
            {
                cout<<"";
            }
            else if (time_confirm == 'N' || time_confirm == 'n')
            {
                system("pause");
                system ("cls");
                goto select_time;
            }
            else
            {
                cout<<"Invalid input! Enter Y/y or N/n only.\n";
                system("pause");
                cout<<endl;
                goto time_confirmation;
            }
            break;
        }
    }
}

void ticket::seatselection(int &tickets, string seatarr[50]){
    int seatNum;
    int NumOfTickets = 0;
    int type;

    system("cls");
    // ask user how many tickets to purchase
    numberOfTickets:
    cout << "+---------------------------------------------------+\n";
    cout << "|       Select number of tickets to be purchased    |\n";
    cout << "+---------------------------------------------------+\n";

    while (true)
    {
    cout << "Your choice -->";
    cin >> NumOfTickets;
    tickets = NumOfTickets; //assigned for later use in confirmation

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Enter numbers only." << endl;
            system("pause");
            system("cls");
            goto numberOfTickets;
        }

    // check for valid number of tickets
    if(tickets<=0 || tickets>10){
        cout << "Sorry, one user can only purchase 1 to 10 tickets.." << endl;
        cout << endl;
        system("pause");
        system("cls");
        goto numberOfTickets;
    }

    break;
    }

    system("cls");

    t1.seatmatrix(NumOfTickets,type,seatNum);

        //the matrix have been copied to seatmatrix function.

}


void ticket::seatmatrix (int &NumOfTickets, int &type, int &seatNum){
    if (NumOfTickets == 0){
        cout << "\nTicket selections have been processed!\n";
    }else{
        select_seat:

        memset(seat,1,sizeof(seat)); // initially all seats are available
        memmove(seat, seatoccupied, sizeof(seat));
        while (NumOfTickets != 0){
            cout<<"========================================="<<endl;
            cout<<"|| Current seat availability matrix :- ||"<<endl;
            cout<<"||-------------------------------------||"<<endl;
            cout<<"|| * - represents available seats      ||  "<<endl;
            cout<<"|| * X represents seat is occupied     ||  "<<endl;
            cout<<"========================================="<<endl;

            t1.displayseat(seat);
            cout<<"Enter the Column (1,2,3,4): ";
            cin>>type;
            cout<<"Enter the seat number: ";
            cin>>seatNum;

            if(t1.available(type, seatNum)){
                t1.searchseat(type,seatNum);
                if(t1.searchseat(type,seatNum)){
                    cout<<"Seat is available and has been assigned\n";
                    cout<< "-> " <<type<<seatNum<<endl;
                    cout<<"\nPress enter to continue...";
                    l.enqueue(t1.concate(type,seatNum));

                    if(type == 1){
                        if(seatoccupied[seatNum-1][1-1])         //-1 as it is an array
                            seatoccupied[seatNum-1][1-1] = false; //0 means the seat is available
                    }
                    if(type == 2){
                        if(seatoccupied[seatNum-1][2-1])
                            seatoccupied[seatNum-1][2-1] = false;
                    }
                    if(type == 3){
                        if(seatoccupied[seatNum-1][3-1])
                                seatoccupied[seatNum-1][3-1] = false;
                    }
                    if(type == 4){
                        if(seatoccupied[seatNum-1][4-1])
                                seatoccupied[seatNum-1][4-1] = false;
                    }


                    NumOfTickets--; // upon success of choosing the seat, minus NumOfTickets by 1
                    system("cls");
                }
                else{
                    cout << "Sorry.. the seat is taken.." << endl;
                    system("pause");
                    system("cls");
                    goto select_seat;
                }
            }else{
                cout<<"No seat is available according to your requirement\n\n";
                cout<<"Press enter to continue...";
                cin.ignore();
                cin.get();
                system("cls");
            }
        }

        t1.seatmatrix(NumOfTickets, type, seatNum);

    } //end of else

} //end of seatmatrix


int ticket::personalinfo(string &name, string &phoneno){
    int ans;

    cout << "+------------------------------------------------------+" << endl;
    cout << "|You are required to fill in your personal information |" << endl;
    cout << "+------------------------------------------------------+" << endl;

    bool validation;

    do{
        cin.ignore();
        cout << "Please enter your name: ";
        getline(cin,name);
        // loop back the whole thing if validation is false
            do{
                validation = true;
                cout << "Please enter your contact number: ";
                cin >> phoneno;
                for(char const& ch : phoneno){
                    if(!isdigit(ch))
                        validation = false;
                }
                if((phoneno.length()<10) || (phoneno.length()>11)){
                    validation = false;
                }
                if(validation==false){
                    cout << "Invalid contact number\n";
                    cout << "Only contact number with 10 or 11 digits is acceptable\n";
                }
        }while(validation==false);

    system("cls");
    // display personal information
    personalinfo:
    cout << "------------------------------------------------------" << endl;
    cout << "Name          : " << name << endl;
    cout << "Contact number: " << phoneno << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Confirm details" << endl;
    cout << "2. Go back to redo details" << endl;
    cout << "Your choice: ";

    while (true)
    {
        cin >> ans;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose number 1-2 only." << endl;
            system("pause");
            system("cls");
            goto personalinfo;
        }
        break;
    }

    if(ans==1){
        return 0;
    }
    while(ans<1 || ans>2){
        cout << "Error! Invalid input" << endl;
        system("pause");
        system("cls");
        goto personalinfo;
    }
    }while(ans==2);

    return 0;
}

void ticket::confirmation(string tname, string phone, int departopt, int arrivalopt, int chosenmonth, int chosenday, int chosentime, int tickets, string seatarr[50]){
    string depart_station[3] = {"KL Sentral","Butterworth Train Station, Pulau Pinang","Batu Gajah Train Station, Perak"};
    string arrive_station[3] = {"Ipoh Train Station, Perak","Sungai Petani Train Station, Kedah","Gemas Train Station, Negeri Sembilan"};
    string time[3] = {"1000 hours", "1500 hours", "2000 hours"};
    int line;
    char confirm;

    system("cls");
        cout << "--------------------------------------------------------------" << endl;
        cout << "Transaction number : ";

        // open file and get transaction number
        fstream transactionFile;
        transactionFile.open("transactionnum.txt", ios :: in);

        if (transactionFile.is_open()) {
            while (transactionFile >> line) {
                cout << line << endl;
            }

            transactionFile.close();
        }
        cout << "Name               : " << tname <<endl;
        cout << "Contact number     : " << phone << endl;
        cout << "Departure station  : " << depart_station[departopt-1] << endl;
        cout << "Arrival station    : " << arrive_station[arrivalopt-1] << endl;
        cout << "Date               : " << chosenmonth << "/" << chosenday << endl;
        cout << "Time               : " << time[chosentime-1] << endl;
        cout << "Tickets            : " << tickets << endl;
        cout << "Seats              : ";
        l.display(seatarr);
        cout << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << endl;

        cout << "\tConfirm ticket?" << endl;
        cout << "\tEnter Y to confirm..." << endl;
        cin >> confirm;

        if(confirm=='y' || confirm=='Y'){
            fstream ticketFile;
            ticketFile.open("ticket.txt", ios::app);

            if(ticketFile.is_open()){
                ticketFile << line << ", "<< tname << ", "<< phone << ", " << depart_station[departopt-1] << ", " << arrive_station[arrivalopt-1] << ", " << chosenmonth << "/" << chosenday << ", " << time[chosentime-1] << ", " << tickets;

                for (int x = 0; x < tickets; x++)
                    ticketFile << "," << seatarr[x];

                ticketFile << "," << endl;
                ticketFile.close();
            }

            line++;

            fstream seatFile;
            seatFile.open("seat.txt", ios::app);

            if(seatFile.is_open()){
                for (int x = 0; x < tickets; x++)
                    seatFile << "," << seatarr[x] << ",";
            }

            seatFile << endl;
            seatFile.close();


            fstream transactionFile;
            ofstream temp;
            transactionFile.open("transactionnum.txt", ios::app);
            if(transactionFile.is_open()){

                transactionFile.open("transactionnum.txt");
                temp.open("temp.txt");

                temp << line << endl;

                transactionFile.close();
                temp.close();

                remove("transactionnum.txt");
                rename("temp.txt","transactionnum.txt");

            }
        }
        else{
            exit(0);
        }
}

void ticket::payment(int arrivalopt, int tickets){
    misc miscfunction;
    int payment_selection;
    string method1, method2;
    string card_num,tac_num;
    const int max_card_num = 16;
    const int max_tac_num = 3;
    int ticketprice[3] = {10, 12, 15};


    method1="Cash";
    method2="Credit Card";

    system("cls");

    cout << "==========================" << endl;
    cout << "|| Your total is RM" << ticketprice[arrivalopt-1]*tickets << "   ||" << endl;
    cout << "==========================" << endl;

        miscfunction.payment();
        cin>>payment_selection;
        if(cin.fail())
        {
            miscfunction.wrongInput();
            miscfunction.payment();
        }
    switch(payment_selection){
    case 1:
            system("cls");
            cout<<"$$$$$$$$$$$ $      $     $     $       $  $     $     $        $    $$$$$$   $       $"<<endl;
            cout<<"     $      $      $    $ $    $ $     $  $   $        $      $    $      $  $       $"<<endl;
            cout<<"     $      $$$$$$$$   $   $   $   $   $  $ $            $  $      $      $  $       $"<<endl;
            cout<<"     $      $      $  $$$$$$$  $    $  $  $   $           $        $      $   $     $ "<<endl;
            cout<<"     $      $      $  $     $  $     $ $  4     $         $         $$$$$$     $$$$$   "<<endl;
            cout<<endl;
            cout<<"PLEASE PAY YOUR TICKETS AT THE COUNTER"<<endl;
            l.~Linkedlist();
      break;

      case 2:
    {

    system("cls");

      bool check_card_num=0;
      bool check_tac_num=0;
      do
            {
                cin.ignore();
                cout<<"Please enter your Card Number: ";
                getline(cin, card_num);
                check_card_num = miscfunction.check_number(card_num);
                if(card_num.size() != max_card_num)
                {
                    do
                    {
                        cout<<"Card numbers are invalid!"<<endl;
                        cout<<"Card payment numbers must be 16 numbers."<<endl;
                        cout<<"Please enter again."<<endl;
                        getline(cin, card_num);
                        break;
                    }while(card_num.size() !=max_card_num);
                }
                if(check_card_num==0)
                {
                    cout<<"Card numbers must be number!"<<endl;
                }
            }while(check_card_num==0 || (card_num.size() != max_card_num));
            cout<<"Your card is accepted!"<<endl;
            do
            {
                cin.ignore();
                cout<<"Please key in the TAC code : ";
                getline(cin,tac_num);
                check_tac_num = miscfunction.check_number(tac_num);
                if (tac_num.size() != max_tac_num)
                {
                    cout<<"Invalid TAC code"<<endl;
                    cout<<"Please try again or request a new TAC code"<<endl;
                    getline(cin, tac_num);
                    check_tac_num = miscfunction.check_number(tac_num);
                }
                if(check_tac_num==0)
                {
                    cout<<"INVALID TAC CODE!!!!"<<endl;
                }
            }while(check_tac_num==0 || (tac_num.size() != max_tac_num));
            cout<<"Payment is accepted"<<endl;

            goto payment_show;

            payment_show:

            cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            cout<<"$                     Thank You!!! Your Payment is Accepted             $\n";
            cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            l.~Linkedlist();
            break;
    }

}

}

void ticket::viewbooking(){
    system("cls");

    cout << "+-------------------------------------------------+" << endl;
    cout << "+                   View Booking                  +" << endl;
    cout << "+-------------------------------------------------+" << endl;

    ifstream ticketFile("ticket.txt");
    string data = "";
    while(getline(ticketFile, data,',')){
        cout << data << endl;
    }
    ticketFile.close();
}

void ticket::editbooking(){
    system("cls");
    ifstream ticketFile;
    ofstream tempFile;
    string temp;
    string st_txt1, st_txt2; //st_txt1 - original text, st_txt2 - new text
    int opt;

    edit_booking:
    ticketFile.open("ticket.txt");
    tempFile.open( "temp.txt");

    cout << "+-------------------------------------------------+" << endl;
    cout << "+                   Edit Booking                  +" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "+ 1.    Edit name                                 +" << endl;
    cout << "+ 2.    Edit contact number                       +" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << endl;

    while (true)
        {
            cout << "Enter 1 or 2 to edit: " << endl;
            cin >> opt;

             if (cin.fail())
            {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice! Choose number 1-2 only." << endl;
            system("pause");
            system("cls");
            goto edit_booking;
            }


    if(opt==1){
        cin.ignore();
        cout << "Enter the name that you want to edit\n";
        getline(cin, st_txt1);
        cout << endl;
        cout << "Enter the name that you want to replace\n";
        getline(cin, st_txt2);

        while (getline(ticketFile, temp)){ //get each line(booking) and store into temp variable
            if (temp.find(st_txt1) != string::npos){ //check if temp has st_txt1, if found
                temp.replace(temp.find(st_txt1), st_txt1.length(), st_txt2); //replace it with st_txt2
                cout << endl;
                cout << temp << endl; //display the modified booking to user
                cout << endl << "Edit success.\n";
            }
            tempFile << temp << endl; //write each line to tempFile
        }

        ticketFile.close();
        tempFile.close();

        remove("ticket.txt");
        rename("temp.txt","ticket.txt");
    }

    else if(opt==2){
        cin.ignore();
        cout << "Enter the contact number that you want to edit\n";
        getline(cin, st_txt1);
        cout << endl;
        cout << "Enter the contact number that you want to replace\n";
        getline(cin, st_txt2);

        while (getline(ticketFile, temp)){ //get each line(booking) and store into temp variable
            if (temp.find(st_txt1) != string::npos){ //check if temp has st_txt1, if found
                temp.replace(temp.find(st_txt1), st_txt1.length(), st_txt2); //replace it with st_txt2
                cout << endl;
                cout << temp << endl; //display the modified booking to user
                cout << endl << "Edit success.\n";
            }
            tempFile << temp << endl; //write each line to tempFile
        }

        ticketFile.close();
        tempFile.close();

        remove("ticket.txt");
        rename("temp.txt","ticket.txt");
    }

    else{
        cout << "Invalid option..\n";
        system("pause");
        system("cls");
        goto edit_booking;

    } break;
        }
}

int ticket::deletebooking(){
    system("cls");

    t1.viewbooking();

    string filename;
    int line_number;

    filename = "ticket.txt";

    cout << "+-------------------------------------------------+" << endl;
    cout << "+                  Delete Booking                 +" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "Enter transaction number to delete booking: ";
    cin >> line_number;

    fstream read_file;

    read_file.open(filename);

    //if failed opening the file
    if(read_file.fail()){
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<string> lines; //create a vector to store each line(booking)
    string line; //to temporary store each line to line variable

    //read each line from the file
    while(getline(read_file,line))
        lines.push_back(line); //hold the line in vector

    read_file.close();

    if(line_number > lines.size()){ //booking does not exist
        cout << endl;
        cout << "Transaction number " << line_number;
        cout << " does not exist." << endl;

        return 1; //without return 1/0 will display successfully delete
        }

        ofstream write_file;

        write_file.open(filename);

        if(write_file.fail()){
            cout << "Error opening file." << endl;
            return 1;
        }

        line_number--; // line 3 is equal to array 2
        for(int i=0; i<lines.size(); i++){
            if(i!=line_number)
                write_file << lines[i] << endl; //write back every line into text file

            else if(i==line_number)
                write_file << "" << endl; //replace the line_number booking with empty space
        }
        lines.clear(); //erase all elements in the vector
        write_file.close();


        filename = "seat.txt";              // erase seat taken as well

        read_file.open(filename);

        //read each line from the file
        while(getline(read_file,line))
            lines.push_back(line); //hold the line in vector

        read_file.close();

        write_file.open(filename);

        for(int i=0; i<lines.size(); i++){
            if(i!=line_number)
                write_file << lines[i] << endl;

            else if(i==line_number)
                write_file << "" << endl;
        }
        cout << endl;
        cout << "Successfully deleted booking for transaction number " << line_number+1 << endl;
        write_file.close();

    return 0;
}

bool ticket::searchseat(int type, int seatNum){             //search whether the seat is taken previously
    fstream seatFile;

    seatFile.open("seat.txt");

    vector<string> seatavailable;
    string search;
    string data = "";

    search = t1.concate(type,seatNum); //current seat entered by user (concatenate and assign to search)

    while(getline(seatFile,data,',')){
        seatavailable.push_back(data); //hold the seat in vector
    }

    seatFile.close();

    //search from start to end, if there is no match (return false)
    if(find(seatavailable.begin(), seatavailable.end(), search)!=seatavailable.end()){
        return false;
    }

    else{
        return true;
    }
}

