/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size(); 
        int ans = 0;
        int m = 0;
        for(int i = 0;i < N; ++i){
            m = max(m, arr[i]);
            ans += (m == i);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector arr{4,3,2,1,0};
    cout << s.maxChunksToSorted(arr) << endl; //1
  
    arr = {1,0,2,3,4};
    cout << s.maxChunksToSorted(arr) << endl; //4

    arr = {1,0,2,4,3};
    cout << s.maxChunksToSorted(arr) << endl; //3

    arr = {2,1,0};
    cout << s.maxChunksToSorted(arr) << endl; //1

    arr = {1,2,3,4,5,0};
    cout << s.maxChunksToSorted(arr) << endl; //1
}
