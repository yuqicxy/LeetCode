/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class StupidSolution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unsigned int ROW = static_cast<unsigned int>(grid.size());
        int ans = 0;
        unordered_map<string,int> s;
        for(auto r = 0u; r < ROW; ++r){
            string tmp= "";
            for(auto c = 0u; c < ROW; ++c){
                tmp += "#" + to_string(grid[r][c]); 
            }
            s[tmp]++;
        }

        for(auto c = 0u; c < ROW; ++c){
            string tmp = "";
            for(auto r = 0u; r < ROW; ++r){
                tmp += "#" + to_string(grid[r][c]);
            }
            ans += s[tmp];
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unsigned int ROW = static_cast<unsigned int>(grid.size());
        int ans = 0;
        map<vector<int>,int> s;
        for(auto r = 0u; r < ROW; ++r)
            s[grid[r]]++;
        for(auto c = 0u; c < ROW; ++c){
            vector<int> col;
            for(auto r = 0u; r < ROW; ++r)
                col.push_back(grid[r][c]);
            auto itr = s.find(col);
            if(itr != end(s))
                ans+=itr->second;
        }
        return ans;
    }
};

// @lc code=end
#include <iostream>
int main(){
    Solution s;
    vector<vector<int>> grid{{3,2,1},{1,7,6},{2,7,7}};
    cout << s.equalPairs(grid) << endl; 
    grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << s.equalPairs(grid) << endl; 
    return 0;
}
