#include "head.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    first = nullptr;
    last = nullptr;
}
//******************************
void Queue::display()
{
    if (front == NULL)
    {
        cout << "The Queueu Is Empty!" << endl;
    }
    else
    {
        Node *temp = front;
        if (front == rear)
        {
            cout << temp->data->groupName << " "
                 << "Size " << temp->data->groupSize << " "
                 << temp->data->specialSeating << endl;
        }
        else
        {
            do
            {
                cout << temp->data->groupName << " "
                     << "Size " << temp->data->groupSize << " "
                     << temp->data->specialSeating << endl;
                temp = temp->link;
            } while (temp != front);
        }
    }
}
//***********************************************
void Queue::assign(int size, Node *temp, Group *group)
{
    cout << "Enter group name: ";
    cin >> temp->data->groupName;
    cout << "Do you folks require any special seating? (Y)es (N)o";
    char option;
    cin >> option;
    switch (option)
    {
    case 'Y':
    case 'y':
        cout << "What kind of seating is right for you? ";
        cin >> temp->data->specialSeating;
        cin.ignore();
        break;
    }
}
//*************************************************
int Queue::enQueue()
{
    cout << "Hello, enter party size: ";
    int size;
    cin >> size;
    if (size <= 0)
    {
        cout << "Group can not have 0 or less members." << endl;
        return 1;
    }
    Node *temp = new Node;
    temp->data = new Group;
    temp->data->groupSize = size;

    if (front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
        temp->link = front;
    }
    assign(size, temp, temp->data);
    return 0;
}
//******************************************************
void Queue::deQueue(Stack &s)
{
    if (front == NULL)
    {
        cout << "The Queueu Is Empty!" << endl;
    }
    else
    {
        s.push();
    }
    if (front == rear)
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else // There are more than one nodes
    {
        Node *temp = front;
        front = front->link;
        rear->link = front;
        free(temp);
    }
}
//*******************************************************
/*void Stack::push()
{
    cout << "Is anyone intreasted in coupons? " << endl;
    char option = ' ';
    int i = 0;
    int num;
    cin >> option;
    if (option == 'y')
    {
        cout << "how many members are intrested? " << endl;
        cin >> num;
        while (num > i)
        {
            MemberNode *temp = new MemberNode;
            temp->data = new MemberData;
            if (first == nullptr)
            {
                first = temp;
                last = temp;
            }
            else
            {
                last->link = temp;
                last = temp;
                temp->link = first;
            }
            cout << "please insert your name: " << endl;
            cin >> temp->data->name;
            cout << "please insert your email adress: " << endl;
            cin >> temp->data->email;
            i = i + 1;
        }
    }
}
*/
//*******************************************************
void Queue::loadQueue()
{
    char input[SIZE];
    ifstream inputfile;
    inputfile.open(fileName);
    char name[SIZE];
    int size;
    char seat[SIZE];
    while (inputfile >> name >> size >> seat)
    {
        Node *temp = new Node;
        temp->data = new Group;
        strcpy(temp->data->groupName, name);
        temp->data->groupSize = size;
        strcpy(temp->data->specialSeating, seat);

        if (front == nullptr)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->link = temp;
            rear = temp;
            temp->link = front;
        }
    }
}
//*********************************************************
void Queue::writeQueue()
{
    if (front == NULL)
    {
        cout << "Nothing Has Been Writin" << endl;
    }
    else
    {
        ofstream ofile;
        ofile.open(fileName);
        Node *temp = front;
        if (front == rear)
        {
            ofile << temp->data->groupName << endl
                  << temp->data->groupSize << endl
                  << temp->data->specialSeating << endl
                  << endl;
        }
        else
        {
            do
            {
                ofile << temp->data->groupName << endl
                      << temp->data->groupSize << endl
                      << temp->data->specialSeating << endl
                      << endl;
                temp = temp->link;
            } while (temp != front);
        }
        ofile.close();
    }
}
//**********************************************************
/*Queue::~Queue(){
    writeQueue();
}*/