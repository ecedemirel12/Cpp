#include <iostream>
#include <vector>
using namespace std;

//QUESTION: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.


class Solution
{
    private:
        vector<int> nums;  //I used vector because ı want a dynamic array(ı don't knw the size)
        int target, index[2];
    
    public:
        Solution() {}
        Solution(vector<int> n, int t) : nums(n), target(t) {}

        void two_sum(int index[]) //I returned the index array as a parameter
        {
            for(int i = 0 ; i < nums.size() ; i ++)
            {
                for(int j = i + 1 ; j < nums.size() ; j ++) //it starts with i + 1 because i don't want to look the same element, different elements should give the target
                {
                    if(nums[i] + nums[j] == target)
                    {
                        index[0] = i;
                        index[1] = j;
                    }
                }
            }
        }
};

int main()
{
    vector<int> nums = {3, 3};
    int target = 6;
    Solution x(nums, target);

    int result[2];
    x.two_sum(result);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    system("pause");
    return 0;
}
