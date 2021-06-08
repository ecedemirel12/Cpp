#include <iostream>
#include "AStack.h"


using namespace std;

int main()
{
    Stack<int> org;
    Stack<int> temp;
    int t;

    org.push(1);
    org.push(2);
    org.push(2);
    org.push(4);
    org.push(5);
    org.push(5);

    while(org.isEmpty() == false)
    {
        if(temp.isEmpty() == true)
        {
            temp.push(org.pop());
        }
        else
        {
            t = org.pop();
            if(t != temp.peek())
                temp.push(t);
        }
    }

    while(temp.isEmpty() != true)
    {
        org.push(temp.pop());
    }

    while(org.isEmpty() == false)
    {
        cout << org.pop() << "  ";
    }

    system("pause");
    return 0;
}