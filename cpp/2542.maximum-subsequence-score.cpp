/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<tuple<int,int>> arr;
        for(int i = 0; i < nums1.size(); ++i)
            arr.emplace_back(nums2[i],nums1[i]);
        //descending order
        sort(begin(arr), end(arr), greater<tuple<int,int>>());
        long long ans = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto [num2, num1] : arr){
            pq.push(num1);
            sum += num1;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = max(ans, sum * num2);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector nums1{1,3,3,2}, nums2{2,1,3,4};
    cout << s.maxScore(nums1, nums2, 3) << endl;

    nums1 = {4,2,3,1,1};
    nums2 = {7,5,10,9,6};
    cout << s.maxScore(nums1, nums2, 1) << endl;

    return 0;
}