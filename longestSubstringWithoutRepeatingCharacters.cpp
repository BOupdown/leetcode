//      https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> res;
        int max = 0;
        int j = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(find(res.begin(), res.end(), s[i]) == res.end())
            {
                res.push_back(s[i]);
                if((i - j + 1) > max)
                    max = i - j + 1;
            }else{
                while(find(res.begin(), res.end(), s[i]) != res.end())
                {
                    res.erase(res.begin());
                    j++;
                }

                res.push_back(s[i]);
            }
        }

        return max;
    }
};
