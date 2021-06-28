/*
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> res = {};
            unordered_map<int, int> hashMap;
            int size = nums.size();
            int search;
            
            for(int i = 0; i < size; i++)
            {
                search = target - nums[i];
            
                if(hashMap.find(search) != hashMap.end() && hashMap.find(search)->second != i)
                {
                    res.push_back(i);
                    res.push_back(hashMap.find(search)->second);
                    return res;  
                }
            
                hashMap.insert({nums[i], i});
            }
        
            return res;
        }
};


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution somme;

    vector<int> toPrint = somme.twoSum(nums, target);
    cout << "[" << toPrint[0] << "," << toPrint[1] << "]" << endl;
    
    return 0;
}