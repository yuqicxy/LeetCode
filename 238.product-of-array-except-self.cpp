/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * @brief 
     *  For test case  [1, 2, 3, 4]
     *  fromBegin      [1, 1, 2, 6]
     *  fromEnd        [1, 4, 12,24]
     *  and then cross multiply fromBegin and fromEnd
     * get result [24,12,8,6]
     * @param nums 
     * @return vector<int> 
     */
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int N = nums.size();
    //     vector<int> fromBegin(N,1);
    //     vector<int> fromEnd(N,1);
    //     for(int i = 1; i < N; ++i){
    //         fromBegin[i] = fromBegin[i - 1] * nums[i -1];
    //         fromEnd[i] = fromEnd[i - 1] * nums[N - i];
    //     }
    //     vector<int> res(N);
    //     for(int i = 0; i < N; ++i){
    //         res[i] = fromBegin[i]* fromEnd[N - i - 1];
    //     }
    //     return res;
    // }

    /**
     * @brief Optimized for above solution
     * 
     * @param nums 
     * @return vector<int> 
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N,1);
        int fromBegin = 1;
        int fromEnd = 1;
        for(int i = 0; i < N; ++i){
            res[i] = res[i] * fromBegin;
            fromBegin = fromBegin * nums[i];
            res[N - i - 1] = res[N - i - 1] * fromEnd;
            fromEnd = fromEnd * nums[N - i - 1];
        }
        return res;
    }
};
// @lc code=end

