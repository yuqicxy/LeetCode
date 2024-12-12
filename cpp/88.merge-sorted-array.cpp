/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[i + j + 1] = nums2[j];
                j--;
            }else{
                nums1[i + j + 1] = nums1[i];
                i--;
            }
        }
        while(j >= 0){
            nums1[j] = nums2[j];
            --j;
        }
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
    vector nums1 = {1,2,3,0,0,0};
    vector nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    cout << nums1 << endl;
    nums1 = {1};
    nums2 = {};
    s.merge(nums1, 1, nums2, 0);
    cout << nums1 << endl;
    nums1 = {0};
    nums2 = {1};
    s.merge(nums1, 0, nums2, 1);
    cout << nums1 << endl;
}