#include <iostream>

class Solution{
public:
    int strStr(string haystack, string needle)
    {
        if(needle.size() == 0)
            return 0;
        else if(haystack.size() == 0)
            return -1;
        
        if(haystack.size() < needle.size() || haystack.size() == 0)
            return -1;


        for(int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if(haystack.substr(i, needle.size()) == needle)
                return i;
                
        }

        return -1;
    }
};