#include <iostream>
#include <string>
using namespace std;

int romanToInt(string a)
{
    int len = a.length(), result = 0;
    for (int i = 0; i < len; i++)
    {
        if(a[i] == 'M' && a[i-1] != 'C' )  //if element i-1 is C, the number will decrease (I check it later)
        {
            result += 1000;
        }
        else if(a[i] == 'D' && a[i-1] != 'C')
        {
           result += 500;
        }
        else if(a[i] == 'C' && a[i-1] != 'X')
        {
            if(a[i+1] == 'D')  //C decreases the number which after itself sı I checked it here
                result += 400;
            else if(a[i+1] == 'M')
                result += 900;
            else
                result += 100;
        }
        else if(a[i] == 'L' && a[i-1] != 'X')
        {
            result += 50;
        }
        else if(a[i] == 'X' && (a[i-1] != 'I'))
        {
            if(a[i+1] == 'L')
                result += 40;
            else if(a[i+1] == 'C')
                result += 90;
            else
                result += 10;
        }
        else if(a[i] == 'V' && a[i-1] != 'I')
        {
            result += 5;
        }
        else if(a[i] == 'I')
        {
            if(a[i+1] == 'X')
                result += 9;
            else if(a[i+1] == 'V')
                result += 4;
            else
                result += 1;
        }    
    }

    return result;
}

int main()
{
    string roman;
    int num;
    cin >> roman;
    num = romanToInt(roman);
    cout << num << endl;

    return 0;
}