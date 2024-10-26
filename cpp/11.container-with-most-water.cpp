/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while(j > i){
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    vector height{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
    return 0;
}