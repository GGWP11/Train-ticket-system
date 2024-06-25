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

Linkedlist::Linkedlist():backPtr(NULL), frontPtr(NULL){}

Linkedlist::~Linkedlist(){
    while(!isEmpty())
        dequeue();
}

bool Linkedlist::isEmpty() const{
    return bool(backPtr == NULL);
}

void Linkedlist::enqueue(string newItem){
    if(isEmpty()){
        frontPtr = new Node;
        frontPtr -> item = newItem;
        frontPtr -> next = NULL;
        backPtr = frontPtr;
    }
    else{
        Node *newPtr = new Node;
        newPtr -> item = newItem;
        newPtr -> next = NULL;
        backPtr -> next = newPtr;
        backPtr = newPtr;
    }
}

void Linkedlist::dequeue(){
    if(isEmpty())
        cout << "No seat available";
    else{
        Node *tempPtr = frontPtr;
        if(frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else{
            tempPtr = frontPtr;
            frontPtr = frontPtr -> next;
            tempPtr -> next = NULL;
            delete tempPtr;
        }
    }
}

void Linkedlist::display(string seatarr[50]){
    int x = 0;
    curPtr = frontPtr;
    cout << "[";
    while(curPtr != NULL){
        cout << curPtr -> item << " ";
        seatarr[x] = curPtr -> item;
        curPtr = curPtr -> next;
        x++;
    }
    cout << "]\n";
}
