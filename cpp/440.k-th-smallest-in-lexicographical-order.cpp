/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while(k > 0){
            int steps = cal_gaps(n , curr, curr + 1);
            if(k < steps){
                curr *= 10;
                k -= 1;
            }else{
                k -= steps;
                curr += 1;
            }
        }
        return curr;
    }

    /**
     * @brief 
     *  start and finish must be the same level of tree
     * 
     *  Calculate the node num in the same level between start and finish 
     * 
     * E.g.
     * Suppose n = 150
     * For start = 1 ; finish = 2 ;   1 step, then goto
     *     start = 10; finish = 20;   10 step, then goto
     *     start = 100; finish = 200; 50 step because reach max limit 150 in this level
     * 
     * @param n 
     * @param start 
     * @param finish 
     * @return size_t 
     */
    int cal_gaps(int n, size_t start, size_t finish){
        int steps = 0;
        while(start <= n){
            if(finish > n + 1){
                steps += n + 1  - start;
            }
            else{
                steps += finish - start;
            }
            start *= 10;
            finish *= 10;
        }
        return steps;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.findKthNumber(13,2) <<endl;
    cout << s.findKthNumber(10,3) <<endl;
    cout << s.findKthNumber(1,1) <<endl;
    // cout << s.findKthNumber(13,4) <<endl;
}
