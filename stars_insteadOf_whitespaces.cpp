#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;
    int lengthStr1;

    cout << "Enter a string: ";
    getline(cin, str1);
    lengthStr1 = str1.length();

    for(int i = 0 ; i < lengthStr1 ; i++)
    {
        //replacing whitespcaes with *
        if(str1[i] == ' ') 
            str1[i] = '*';
    }
    cout << str1 << endl;

    system("pause");
    return 0;
}