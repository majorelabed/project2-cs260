#include <iostream>
#include "head.h"

using namespace std;
int main(int argc, char **argv)
{
    cout << "Welcome to our humble joint! " << endl;
    Queue q;
    Stack *s = new Stack(atoi(argv[1]));
    q.loadQueue();
    char optionInput = ' ';
    while (true)
    {
        cout << "Please enter a command" << endl
             << "(E)nqueue, (D)equeue, Disp(l)ay (P)op (Q)uit" << endl;
        cin >> optionInput;

        switch (optionInput)
        {
        case 'E':
        case 'e':
            q.enQueue();
            break;
        case 'D':
        case 'd':
            q.deQueue(*s);
            break;
        case 'L':
        case 'l':
            q.display();
            break;
        case 'P':
        case 'p':
            s->pop();
            break;
        case 'q':
        case 'Q':
            q.writeQueue();
            return 0;
        }
    }
    return 0;
}
