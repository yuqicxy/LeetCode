/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> dq;
        int ans = 0; 
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i){
            while(!dq.empty() && heights[dq.back()] > heights[i]){
                int h = heights[dq.back()];
                dq.pop_back();
                int w = dq.empty() ? i : i - dq.back() - 1;
                ans = max(h * w, ans);
            }
            dq.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector heights{2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl; //10

    heights = {2,4};
    cout << s.largestRectangleArea(heights) << endl; //4

    heights = {2,1,2};
    cout << s.largestRectangleArea(heights) << endl; //3
    
    heights = {1,2,2,2};
    cout << s.largestRectangleArea(heights) << endl; //6

    heights = {5,4,1,2};
    cout << s.largestRectangleArea(heights) << endl; //8

    heights = {0,9};
    cout << s.largestRectangleArea(heights) << endl; //9

    heights = {4,2,0,3,2,5};
    cout << s.largestRectangleArea(heights) << endl; //6

    heights = vector<int>(30000, 1);
    cout << s.largestRectangleArea(heights) << endl; //30000

    return 0;
}