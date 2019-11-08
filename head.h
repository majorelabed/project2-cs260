#ifndef _HEAD_
#define _HEAD_
#include <cstdlib>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

const int SIZE = 50;

struct MemberData
{
    char coupons[SIZE];
    char name[SIZE];
    char email[SIZE];
};

struct MemberNode
{
    // MemberNode *link;
    MemberData *data;
};

struct Group
{
    char groupName[SIZE];
    char specialSeating[SIZE] = ".";
    int groupSize;
};

struct Node
{
    Group *data;
    Node *link;
};

class Stack
{
    char fileName[SIZE] = "customers.txt";
    MemberData *members;
    int index =0;
    int size =0;

public:
    Stack();
    Stack(int arraySize);
    void push();
    void pop();
};

class Queue
{
    Node *front, *rear;
    MemberNode *first, *last;
    char fileName[SIZE] = "queue.txt";

public:
    Queue();
    int enQueue();
    void deQueue(Stack& s);
    void assign(int size, Node *temp, Group *group);
    void display();
    void loadQueue();
    void writeQueue();
};

#endif
