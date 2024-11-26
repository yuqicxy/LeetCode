/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto edge: edges)
            indegree[edge[1]]++;
        if(count(indegree.begin(), indegree.end(), 0) > 1)
            return -1;
        auto itr = find(indegree.begin(),indegree.end(),0);
        return static_cast<int>(distance(indegree.begin(), itr));
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> edges={{0,1},{1,2}};
    cout << s.findChampion(3, edges) << endl; // 0
    edges = {{0,2},{1,3},{1,2}};
    cout << s.findChampion(4, edges) << endl; //-1
    return 0;
}
