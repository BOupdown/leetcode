#include <iostream>

class Solution{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;

        int open = 0;
        int close = 0;

        possibilities(n, res, open, close, "");

        return res;
    }

    void possibilities(int n, vector<string>& res, int open, int close, string current)
    {
        string temp = current;
        
        if(open == n && close == n)
        {
            res.push_back(current);
            return;
        }

        if(open < n)
        {
            current = current + '(';
            possibilities(n, res, open + 1, close, current);
            current = temp;
        }

        if(close < open)
        {
            current = current + ')';
            possibilities(n, res, open, close + 1, current);
            current = temp;
        }
        

    }
};