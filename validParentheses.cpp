#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    bool isValid(string s)
    {
        if(s.size() == 0 || s.size() == 1)
            return false;

        vector<char> ret;
        unordered_map<char, char> hash;
        
        hash['('] = ')';
        hash[')'] = 'a';
        hash[']'] = 'b';
        hash['['] = ']';
        hash['}'] = 'c';
        hash['{'] = '}';

    
        for(int i = 0; i < s.size(); i++)
        {
            if(ret.size() == 0 || hash[ret[ret.size() - 1]] != s[i])
                ret.push_back(s[i]);
            else
                ret.pop_back();
        }

        if(ret.size() == 0)
            return true;
        else
            return false;
    }
};
