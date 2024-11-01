/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// LIS solution, work for any lengths of subsequence
class GenericSolution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        for(auto num : nums){
            auto itr = lower_bound(ans.begin(), ans.end(), num);
            if(itr != ans.end()){
                *itr = num;
            }else{
                ans.push_back(num);
                if(ans.size() > 2)
                    return true;
            }
        }
        return false;
    }
};

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int top = numeric_limits<int>::max();
        int bot = numeric_limits<int>::max();
        for(auto num : nums){
            if(num <= bot){
                bot = num;
            }else if(num <= top){
                top = num;
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{20,100,10,12,5,13};
    //true
    cout<<boolalpha << s.increasingTriplet(nums)<<endl; 
    //false
    nums = {2,4,-2,-3};
    cout<<boolalpha << s.increasingTriplet(nums)<<endl; 
    //true
    nums = {1,2,3,4,5};
    cout<<boolalpha << s.increasingTriplet(nums)<<endl; 
    //false
    nums = {5,4,3,2,1};
    cout<<boolalpha << s.increasingTriplet(nums)<<endl;
    //true
    nums = {2,1,5,0,4,6};
    cout<<boolalpha << s.increasingTriplet(nums)<<endl;
    //true
    nums = {0,2,0,1,2};
    cout<<boolalpha << s.increasingTriplet(nums)<<endl;
    return 0;
}