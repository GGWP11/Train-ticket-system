#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <string>
#include <iostream>

class Linkedlist{
public:
    Linkedlist();
    ~Linkedlist();

    bool isEmpty() const;
    void enqueue(string newItem);
    void dequeue();
    void display(string seatarr[50]);

    struct Node{
        string item;
        Node *next;
    };

    Node *backPtr;
    Node *frontPtr;
    Node *curPtr;
};

#endif // LINKEDLIST_HPP


