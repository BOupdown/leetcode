//      https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
            return {};

        string tab[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;

        letterCombinationsRecursive(res, digits, "", 0, tab);

        return res;
    }

    void letterCombinationsRecursive(vector<string>& result, string digits, string current, int index, string* tab)
    {
        if(index == digits.size())
        {
            result.push_back(current);
            return;
        }

        string letters = tab[digits[index] - '0'];

        for(int i = 0; i < letters.size(); i++)
        {
            letterCombinationsRecursive(result, digits, current + letters[i], index + 1, tab);
        }
    }
};
