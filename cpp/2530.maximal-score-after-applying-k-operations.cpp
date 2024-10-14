/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> heap(nums.begin(), nums.end());
        while(k-- && !heap.empty()){
            int val = heap.top();
            ans += val;
            heap.pop();
            int value = (val + 2) / 3;
            if(value)
                heap.push(value);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    vector nums{10,10,10,10,10};
    Solution s;
    cout << s.maxKelements(nums, 5) << endl;
    nums = {1,10,3,3,3};
    cout << s.maxKelements(nums, 3) << endl;
    nums = {756902131, 995414896,
            95906472 , 149914376,
            387433380, 848985151};
    cout << s.maxKelements(nums, 6) << endl; //3603535575

}