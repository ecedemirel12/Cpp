#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums;
    vector<int>::iterator it;
    int inputs;

    cout << "Enter the elements if the elements are finished, enter -1: ";
    while (cin >> inputs && inputs != -1 ) 
    {
        nums.push_back(inputs);
    }

    for(int i = 0 ; i < nums.size(); i++)
    {
        for(int j = 0 ; j < nums.size() ; j++)
        {
            if(j != i && nums[j] == nums[i])
            {
                it = nums.begin() + j;
                nums.erase(it);
            }
        }
    }

    //for ascending order
    int temp;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        for(int j = 0 ; j < nums.size()-1-i ; j++)
        {
            if(nums[j] > nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j + 1] = temp;
            }
        }
    }


    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "   ";
    }

    system("pause");
    return 0;
}