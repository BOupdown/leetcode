//      https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int max = min(height[l], height[r]) * (r - l);

        while(l != r)
        {
            if(height[l] < height[r])
                l++;
            else
                r--;

            if(max < (min(height[l], height[r]) * (r - l)))
                max = min(height[l], height[r]) * (r - l);
        }

        return max;
    }
};
