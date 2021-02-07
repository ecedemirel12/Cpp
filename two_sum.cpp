#include <iostream>
#include <vector>
using namespace std;

//QUESTION: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.


class Solution
{
    private:
        vector<int> nums, index;  //I used vector because ı want a dynamic array(ı don't knw the size)
        int target;
    
    public:
        Solution() {}
        Solution(vector<int> n, int t) : nums(n), target(t) {}

        vector<int> two_sum() //I returned the index array as a parameter
        {
            for(int i = 0 ; i < nums.size() ; i ++)
            {
                for(int j = i + 1 ; j < nums.size() ; j ++) //it starts with i + 1 because i don't want to look the same element, different elements should give the target
                {
                    if(nums[i] + nums[j] == target)
                    {
                        index.push_back(i);
                        index.push_back(j);
                    }
                }
            }
            return index;
        }
};

int main()
{
    vector<int> nums, result;
    int target, input, n;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter elements of array: ";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> input;
        nums.push_back(input);
    }
    cout << "Enter the target: ";
    cin >> target;
    Solution x(nums, target);

    result = x.two_sum();
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    system("pause");
    return 0;
}
