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
        // return bitset<sizeof(int) * 8>(n).count();

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
    cout <<"-10:" <<bitset<sizeof(int) * 8>(-10).to_string()<<endl;
    cout <<" 35:" <<bitset<sizeof(int) * 8>(35).to_string()<<endl;
    cout <<" 22:" <<bitset<sizeof(int) * 8>(22).to_string()<<endl;
    cout <<"  ^:" <<bitset<sizeof(int) * 8>(35^22).to_string()<<endl;
    cout << s.minBitFlips(35, 22) << endl;    
    cout << s.minBitFlips( 3, 4) << endl;
}
