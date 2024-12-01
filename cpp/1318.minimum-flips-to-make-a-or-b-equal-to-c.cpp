/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

#include <iostream>
#include <bit>

using namespace std;

class StupidSolution {
public:
    int minFlips(int a, int b, int c) {
        int i = 0;
        int ans = 0;
        int m = max(max(a,b),c);
        while(m >= (1 << i)){
            if(c & (1 << i)){
                if(!((a & (1 << i)) | (b & (1 << i))))
                    ans++;
             }else{
                if(a & (1 << i))
                    ans++;
                if(b & (1 << i))
                    ans++;
            }
            ++i;
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return popcount<unsigned int>((a | b) ^ c) + popcount<unsigned int>(a & b & ((a | b) ^ c));
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minFlips(2,6,5) << endl;//3
    cout << s.minFlips(4,2,7) << endl;//1
    cout << s.minFlips(1,2,3) << endl;//0
    cout << s.minFlips(8,3,5) << endl;//3
}

