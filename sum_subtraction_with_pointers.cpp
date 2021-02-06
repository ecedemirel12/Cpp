#include <iostream>
#include <math.h>
using namespace std;

void calculate(int *a, int *b) {
    int aTemp, bTemp;
    aTemp = *a + *b;
    bTemp = abs(*a - *b);
    *a = aTemp; //storing the sum in a
    *b = bTemp; //storing the subtraction in b
}

int main() {
    int a, b;
    int *pnt = &a, *pntb = &b; //pointers for a and b

    cout << "Enter two integer numbers:";
    cin >> a >> b;
    calculate(pnt, pntb);
    cout << a << " " << b  << endl;

    system("pause");
    return 0;
}
