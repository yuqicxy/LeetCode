/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0; 
        for(; i < arr.size() - 1 && arr[i] <= arr[i + 1]; ++i){}
        int ans = arr.size() - i - 1;
        for(int j = arr.size() - 1; j > i;){
            while(i >= 0 && arr[i] > arr[j])
                i--;
            ans = min(ans, j - i - 1);
            if(arr[j - 1] <= arr[j])
                j--;
            else
                break;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector arr{1,2,3,10,4,2,3,5};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //3

    arr = {5,4,3,2,1};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //4

    arr = {1,2,3};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //0

    arr={1};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //0

    arr = {6,3,10,11,15,20,13,3,18,12};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //8
    
    arr={2,2,2,1,1,1};
    cout << s.findLengthOfShortestSubarray(arr) << endl; //3
}