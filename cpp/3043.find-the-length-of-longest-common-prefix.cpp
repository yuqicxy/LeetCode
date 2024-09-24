/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] find the length of the longest common prefix
 */

#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> foundPrefix;
        for (auto num : arr1){
            while(num > 0){
                foundPrefix.insert(num);
                num = num / 10;
            }
        }

        int longestPrefixLength = 0;
        for(auto num : arr2){
            while(num > 0){
                if(foundPrefix.find(num) != foundPrefix.end()){
                    longestPrefixLength = max(longestPrefixLength,static_cast<int>(to_string(num).length()));
                }
                num = num / 10;
            }
        }

        return longestCommonPrefix;
    }
};
// @lc code=end

int main(){
    Solution s;
    auto arr1 = vector<int>{1,10,100};
    auto arr2 = vector<int>{1000};
    cout << s.longestCommonPrefix(arr1, arr2) << endl;
}