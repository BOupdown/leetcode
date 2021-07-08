/*
 *  Given a string s, return the longest palindromic substring in s.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        if(s.size() <= 1)
            return s;

        bool res[s.size()][s.size()];

        for(int i = 0; i < s.size(); i++)
        {
            res[i][i] = true;

            if(i != n-1)
                res[i][i+1] = (s[i] == s[i+1]);
        }

        for(int i = n-3; i >= 0; --i){
            for(int j = i+2; j<n; ++j){
                res[i][j] = (res[i+1][j-1] && s[i]==s[j]);
            }
        }

        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(res[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }

        return maxstr;
    }
};

int main()
{
    string s = "babad";
    Solution solution;

    cout << solution.longestPalindrome(s) << endl;

    return 0;
}