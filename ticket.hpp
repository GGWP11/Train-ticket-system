#ifndef ticket_hpp
#define ticket_hpp
#include <string>
#include <iostream>
using namespace std;

class ticket{
public:
    void departurestation(int &depart);
    void ticketprice();
    void arrivalstation(int &arrival);
    void dateselection(int &dep_month, int &dep_day);
    void timeselection(int &dep_time);
    void seatmatrix (int &NumOfTickets, int &type, int &seatNum);
    void seatselection(int &tickets, string seatarr[50]);
    int personalinfo(string &name, string &phoneno);
    void confirmation(string tname, string phone, int departopt, int arrivalopt, int chosenmonth, int chosenday, int chosentime, int tickets, string seatarr[50]);
    void displayseat(bool seat[12][4]);
    int available(int type, int seatNum);
    void payment(int arrivalopt, int tickets);
    string concate(int row, int column);
    void viewbooking();
    void editbooking();
    int deletebooking();
    bool searchseat(int type, int seatNum);

    string ori_sta_choose;
};


#endif // ticket_hpp
