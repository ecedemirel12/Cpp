#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num)
{
    string str = to_string(num); //converting to string to check palindrome or not easily
    int len = str.length() - 1;  //the last character is \0 (null) so I don't want to compare it
    bool flag;
    for(int i = 0 ; i < str.length()/2 ; i++ )
    {
        if(str[i] == str[len])
        {
            flag = true;
            len--; 
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}

int main()
{
    int number, palindrome;
    cout << "Enter a number to check is palindrome or not: ";
    cin >> number;
    
    palindrome = isPalindrome(number);
    if(palindrome == 1)
        cout << "The number " << number << " is palindrome." << endl;
    else
        cout << "The number " << number << " is not palindrome." << endl;

    system("pause");
    return 0;
}