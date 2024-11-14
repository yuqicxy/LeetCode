/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lower = 1;
        int upper = 1000000000;
        while(lower < upper){
            auto mid = (lower + upper)/2;
            int timeCost = 0;
            for(auto pile : piles){
                timeCost += (pile + mid - 1)/mid;
            }
            if(timeCost <= h){
                upper = mid;
            }else{
                lower = mid + 1;
            }
        }
        return lower;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector piles{3,6,7,11};
    cout << s.minEatingSpeed(piles, 8) << endl;
    piles = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles, 5) << endl;
    piles = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles, 6) << endl;
}