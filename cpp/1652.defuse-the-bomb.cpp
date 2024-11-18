/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);
        if(k == 0) return ans;
        int j = k > 0 ? 1 : code.size() + k;
        int temp = accumulate(code.begin() + j, code.begin() + abs(k) + j, 0);
        ans[0] = temp;
        for(int i = 1; i < code.size(); ++i){
            temp += code[(j + abs(k)) % code.size()];
            temp -= code[j % code.size()];
            ++j;
            ans[i] = temp;
        }
        return ans;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, vector<int> nums){
    ss<<"[";
    for(auto num:nums){
        ss << num << ",";
    }
    ss<<"\b]";
    return ss;
}


int main(){
    Solution s;
    vector code{5,7,1,4};
    cout << s.decrypt(code, 3) << endl;
    cout << s.decrypt(code, 1) << endl;
    code = {2,4,9,3};
    cout << s.decrypt(code, -2) << endl;
}