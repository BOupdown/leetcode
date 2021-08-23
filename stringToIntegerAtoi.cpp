//      https://leetcode.com/problems/string-to-integer-atoi/
#include <iostream>

using namespace std;

class Solution{
public:
    int myAtoi(string s)
    {
        int temp = 0;
        double size = s.size();
        double res = 0;
        int ascii = 0;
        bool negatif = false;

        if((s[0] < 48 || s[0] > 57) && s[0] != 32 && s[0] != 43 && s[0] != 45)
            return 0;

        while(s[temp] == 48 || s[temp] == 32)
        {
            if(temp < (size - 1))
                temp++;
        }

        if(s[temp] == '+')
        {
            negatif = false;
            temp++;
        }else if(s[temp] == '-'){
            negatif = true;
            temp++;
        }

        if((s[temp] < 48 || s[temp] > 57) && s[temp] != 32)
            return 0;


        while(s[temp] >= 48 && s[temp] <= 57 && temp < size)
        {
            switch(s[temp])
            {
                case 48 :
                    ascii = 0;
                    break;
                case 49 :
                    ascii = 1;
                    break;
                case 50 :
                    ascii = 2;
                    break;
                case 51 :
                    ascii = 3;
                    break;
                case 52 :
                    ascii = 4;
                    break;
                case 53 :
                    ascii = 5;
                    break;
                case 54 :
                    ascii = 6;
                    break;
                case 55 :
                    ascii = 7;
                    break;
                case 56 :
                    ascii = 8;
                    break;
                case 57 :
                    ascii = 9;
                    break;
            }

            res = res * 10 + ascii;
            temp++;
        }

        if(negatif == false && res <= 2147483647)
            return int(res);
        else if(negatif == true && res <= 2147483648)
            return -(int(res));
        else if(negatif == false && res > 2147483647)
            return 2147483647;
        else if(negatif == true && res > 2147483648)
            return -2147483648;

        if(negatif == true)
            res = -1 * res;


        return res;

    }
};
