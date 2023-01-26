//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/submissions/885822407/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.length();
        int left = 0;
        int l = 0;
        int right = 0;
        int r = n - 1;
        int count = 0;
        while (l < r)
        {
            while (l < r and left >= 0)
            {
                if (s[l] == '[')
                    left++;
                else
                    left--;
                l++;
            }
            if (left < 0)
                l--;
            while (l < r and right >= 0)
            {
                if (s[r] == '[')
                    right--;
                else
                    right++;
                r--;
            }
            if (right < 0)
                r++;
            if (l < r)
            {
                swap(s[l], s[r]);
                left++;
                right++;
                count++;
            }
        }
        return count;
    }
};
