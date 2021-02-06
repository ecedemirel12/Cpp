#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
    cout << "Enter a word: ";
    getline(cin, s1);
    string s2;
    cout << "Enter another word: ";
    getline(cin, s2);
    cout << s1.size() << " " << s2.size() << endl;  //length of strings
    cout << s1 + ' ' + s2 << endl;  //concatenation of the words

    //swapping first letters of the words
    char temp = s1[0];
    s1[0] = s2[0];
    s2[0] = temp;
    cout << s1 << " " << s2;

    system("pause");
    return 0;
}
