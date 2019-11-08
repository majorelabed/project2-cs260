#include "head.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
}

Stack::Stack(int arraySize)
{
    members = new MemberData[arraySize];
    size = arraySize;
}

//******************************************************************************************

void Stack::push()
{
    cout << "Is anyone intreasted in coupons? " << endl;
    char option = ' ';
    int num;
    cin >> option;
    if (option == 'y')
    {
        cout << "how many members are intrested? " << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            MemberData *data = new MemberData;
            cout << "please insert your name: " << endl;
            cin >> data->name;
            cout << "please insert your email adress: " << endl;
            cin >> data->email;

            if (index == sizeof(members) - 1)
            {
                MemberData *tempMembers = new MemberData[sizeof(members) + size];
                for (int j = 0; j < sizeof(members); j++)
                    tempMembers[j] = members[j];
                members = tempMembers;
                members[index] = *data;
                index++;
            }
            else
            {
                members[index] = *data;
                index++;
            }
        }
    }
}

//****************************************************************************************

void Stack::pop()
{
    ofstream ofile;
    ofile.open(fileName);
    cout << members[0].name << " What kind of coupons are you intrested in?" << endl;
    cin >> members[0].coupons;
    ofile << members[0].name << " ," << members[0].email << " ," << members[0].coupons << endl;
    cout << "Thank you, visit us again!" << endl;
    for (int i = 1; i <= index; i++)
        members[i - 1] = members[i];
    index--;
    ofile.close();
}

/*

data Group = Group {
    name :: String,
    specialSeating :: String,
    size :: Int
}

groups = [Group {...}, Group {...}}]

format g = 
    name g ++ " " ++ specialSeating g ++ " " ++ show (size g)

formattedGroups = map format groups

*/