#include <iostream>
#include <stdlib.h>
using namespace std;
//game
char arr[11][11];  

void setBase()
{
    //seting the table
    for(int i = 0 ; i < 11 ; i++)  
    {
        for (int j = 0; j < 11; j++)
        {
            if(i == 3 || i == 7)
                arr[i][j] = '-';
            else if((j == 3 || j == 7) && j != i)
                arr[i][j] = '|';
            else
                arr[i][j] = ' ';
        }
    }
}

void printArr()
{
    for(int i = 0 ; i < 11 ; i++)
    {
        for(int j = 0 ; j < 11 ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setPlaces(char c, int &order)
{
    char num = '1';
    for(int i = 1 ; i <= 9 ; i += 4)
    {
        for(int j = 1 ; j <= 9 ; j += 4)
        {
            if(c == num && order == 1)
            {
                arr[i][j] = 'X';
                order = 2;
            }
            else if(c == num && order == 2)
            {
                arr[i][j] = 'O';
                order = 1;
            }
            else if(c == ' ')
            {
                arr[i][j] = num;
            }
            num++;
        }
    }
}

void table(char num, int &x, int &y)  //to reach the coordinates
{
    switch (num)
    {
        case '1':
            x = 1;
            y = 1;
            break;
        case '2':
            x = 1;
            y = 5;
            break;
        case '3':
            x = 1;
            y = 9;
            break;
        case '4':
            x = 5;
            y = 1;
            break;
        case '5':
            x = 5;
            y = 5;
            break;
        case '6':
            x = 5;
            y = 9;
            break;
        case '7':
            x = 9;
            y = 1;
            break;
        case '8':
            x = 9;
            y = 5;
            break;
        case '9':
            x = 9;
            y = 9;
            break;
        default:
            break;
    }
}

int main()
{
    char p1 = 'X', p2 = 'O';
    char choice = ' ';
    bool gameOver = false;
    int playerOrder = 1, x, y;
    setBase();
    do
    {
        system("cls");
        setPlaces(choice, playerOrder);
        printArr();
        cout << "Enter a place: ";
        cin >> choice;
        table(choice, x, y);
        while(arr[x][y] == 'X' || arr[x][y] == 'O')
        {
            cout << "Enter a place again: ";
            cin >> choice;
            table(choice, x, y);
        }

    } while (gameOver == false);
    
    

        
    system("pause");
    return 0;
}
