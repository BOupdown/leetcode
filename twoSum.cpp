//      https://leetcode.com/problems/two-sum/
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
