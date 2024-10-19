/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class BrutalSolution
{
public:
    char findKthBit(int n, int k)
    {
        string s = "0";
        for (int i = 1; i <= n; ++i)
        {
            if (k <= s.size())
                return s[k - 1];
            auto ss = s;
            for (auto &&c : ss)
                c = (c == '0') ? '1' : '0';
            reverse(ss.begin(), ss.end());
            s = s + '1' + ss;
        }
        return '0';
    }
};

// @lc code=start
class Solution
{
public:
    char findKthBit(int n, int k)
    {
        int layer = n;
        int length = (1 << layer) - 1;
        bool flip = false;
        while (layer > 1)
        {
            if (k > (length + 1) / 2 )
            {
                k = length + 1 - k;
                flip = !flip;
            }
            else if (k == (length + 1) / 2)
                return !flip ? '1' : '0';
            length = (length - 1) / 2;
            layer--;
        }
        return !flip ? '0' : '1';
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.findKthBit(3, 1) << endl;
    cout << s.findKthBit(4, 11) << endl;
}
