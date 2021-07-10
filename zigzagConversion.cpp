/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 *And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 *
 * Example :
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 */


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

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string result = solution.convert(s, numRows);
    cout << result << endl;

    return 0;
}