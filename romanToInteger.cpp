#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> hash;

        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;

        for(int i = 0; i < s.size(); i++)
        {
            if(i < s.size() - 1)
            {
                if(hash[s[i]] < hash[s[i+1]])
                {
                    res += hash[s[i+1]] - hash[s[i]];
                    i++;
                }else{
                    res += hash[s[i]];
                }
            }else{
                res += hash[s[i]];
            }
        }

        return res;
    }
};

int main()
{
    string s = "III";
    Solution solution;
    cout << solution.romanToInt(s) << endl;

    return 0;
}