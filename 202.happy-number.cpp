/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(set.count(n) == 0){
            if(n == 1) return true;
            set.emplace(n);
            int sum = 0;
            while(n != 0)
            {
                int reminder = n % 10;
                n = n/10;
                sum += pow(reminder,2);
            }
            n = sum;
        }
        return false;
    }
};
// @lc code=end

