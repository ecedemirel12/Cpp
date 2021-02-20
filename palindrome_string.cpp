#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	bool palindrome;

	getline(cin, str1);
	int len = str1.size();

	for(int i = 0 ; i < len/2 ; i++)
	{	
		if (str1[i] == str1[len-i-1])
			palindrome = true;
		else
			palindrome = false;
	}
	
	if(palindrome == true)
		cout << str1 << " is a palindrome word." << endl;
	else 
		cout << str1 << " is not a palindrome word." << endl;

	system("pause");
    return 0;
}