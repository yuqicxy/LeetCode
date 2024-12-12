/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>
#include <iostream>

using namespace std;

class MySolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i] == val){
                swap(nums[i],nums[j]);
                j--;
            }else{
                ++i;
            }
        }
        return i;
    }
};

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};
// @lc code=end


ostream& operator<<(ostream& ss, const vector<int> &nums){
    ss << "[";
    for(auto num : nums){
        ss << num << " ,";
    }
    ss << "\b]";
    return ss;
}

int main(){
    Solution s;

    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    cout << nums << endl;

    nums = {0,1,2,2,3,0,4,2};
    val = 2;
    cout << s.removeElement(nums, val) << endl;
    cout << nums << endl;
}