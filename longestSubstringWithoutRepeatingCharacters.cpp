/*
 * Given a string s, find the length of the longest substring without repeating characters.
 */

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

int main()
{
    Solution solution;
    string s = "pwwkew";

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}