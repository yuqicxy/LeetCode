/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

#include <vector>
#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;


class MySolution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> hm;
        int ans = 0;
        for(const auto &row : matrix){
            bitset<300> b1;
            bitset<300> b2;
            for(int i = 0 ; i < row.size(); ++i){
                b1.set(i, row[i]);
                b2.set(i, !row[i]);
            }
            hm[b1]++;
            hm[b2]++;
            ans = max(ans , max(hm[b1], hm[b2]));
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> hm;
        int ans = 0;
        for(const auto &row : matrix){
            bitset<300> b1;
            for(int i = 0 ; i < row.size(); ++i)
                b1.set(i, row[i] ^ row[0]);
            hm[b1]++;
            ans = max(ans , hm[b1]);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> matrix{{0,0,0},{0,0,1},{1,1,0}};
    cout << s.maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}