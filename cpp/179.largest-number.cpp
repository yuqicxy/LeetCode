/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(all_of(nums.begin(), nums.end(), [](int val){ return val == 0; }))
            return "0";
        vector<string> numsstr;
        transform(nums.begin(), nums.end(), back_inserter(numsstr),
            [](int num){
                return to_string(num);
            }
        );

        sort(numsstr.begin(),numsstr.end(),
            [](string left, string right)->bool{ 
                return (left + right) > (right + left);
            }
        );

        string ans = std::accumulate(numsstr.begin(),numsstr.end(),string(""));
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> data1{10,2};
    cout << s.largestNumber(data1) << endl;
    vector<int> data2{3,30,34,5,9};
    cout << s.largestNumber(data2) << endl;
    vector<int> data3{0,0};
    cout << s.largestNumber(data3) << endl;
}