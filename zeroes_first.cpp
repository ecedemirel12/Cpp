#include <iostream>
using namespace std;

void first_zero(int arr[],int size)
{
	int temp;
	for(int i = 1 ; i < size ; i++)  //i starts with 1 because we look number of before i
	{
		if(arr[i] == 0)
		{
			for(int j = i ; j > 0 ; j--)
			{
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main()
{
    int n=5;
    int arr[n];
    
    cout << "Enter the elements of array(5x5):";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array:" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    first_zero(arr, n);
    cout << "\nNew array:" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}