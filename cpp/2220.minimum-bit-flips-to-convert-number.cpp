/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */
#include <bitset>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int count = 0;
        while(n){
            n &= (n-1);
            count++;
        }

        return count;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout <<"-10:" <<bitset<sizeof(int)>(-10)<<endl;
    cout <<"10:" <<bitset<sizeof(int)>(10)<<endl;

    cout <<" 7:" <<bitset<sizeof(int)>(7)<<endl;
    cout <<" ^:" <<bitset<sizeof(int)>(10^7)<<endl;
    cout <<" 3:" <<bitset<sizeof(int)>(3)<<endl;
    cout <<" 4:" <<bitset<sizeof(int)>(4)<<endl;
    cout <<" ^:" <<bitset<sizeof(int)>(3^4)<<endl;
    cout << s.minBitFlips(10, 7) << endl;    
    cout << s.minBitFlips( 3, 4) << endl;
}
