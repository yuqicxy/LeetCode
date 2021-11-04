/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] < target){
                left++;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else
                return {left+1,right+1};
        }
        return {};
    }
};
// @lc code=end

