/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hash;
        for(int val : arr){
            if(hash.count(2 * val) || (val % 2 == 0 && hash.count(val / 2)))
                return true;
            hash.insert(val);
        }
        return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha;
    vector arr{10,2,5,3};
    cout << s.checkIfExist(arr) << endl;
    arr = {3,1,7,11};
    cout << s.checkIfExist(arr) << endl;
    arr = {3,1,7,11,0};
    cout << s.checkIfExist(arr) << endl;
    return 0;
}