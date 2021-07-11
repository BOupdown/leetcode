#include <iostream>

using namespace std;

class Solution{
public:
    int reverse(int x)
    {
        int res = 0;

        while(x != 0)
        {
            res = x % 10 + res * 10;
            x = x / 10;
        }

        if(res <= 2147483647 && res >= -2147483648)
            return res;
        else
            return 0;
    }
};

int main()
{
    Solution solution;
    int number = 651654852;

    cout << solution.reverse(number) << endl;

    return 0;
}