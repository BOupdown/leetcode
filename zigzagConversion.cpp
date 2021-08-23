//      https://leetcode.com/problems/zigzag-conversion/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int interval = 2 * numRows - 2;
        int step;
        int size = s.size();
        vector<char> res;

        if(size <= numRows || numRows == 1)
            return s;

        for(int i = 0; i < size; i = i + interval)
        {
            res.push_back(s[i]);
        }

        for(int i = 1; i < (numRows - 1); i++)
        {
            step = interval - 2 * i;
            int j = i;

            while(j < size)
            {
                res.push_back(s[j]);

                if((j + step) < size)
                    res.push_back(s[j+step]);
                else
                    break;

                j += interval;
            }
        }

        for(int i = numRows - 1; i < size; i = i + interval)
        {
            res.push_back(s[i]);
        }

        string result(res.begin(), res.end());

        return result;
    }
};
