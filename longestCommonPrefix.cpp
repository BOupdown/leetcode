//      https://leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int minLength = strs[0].size();
        int count = 0;

        if(strs.size() == 1)
            return strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            if(strs[i].size() < minLength)
                minLength = strs[i].size();
        }

        for(int i = 0; i < minLength; i++)
        {
            for(int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                    return strs[0].substr(0, count);
            }

            count++;
        }

        return strs[0].substr(0, count);
    }
};
