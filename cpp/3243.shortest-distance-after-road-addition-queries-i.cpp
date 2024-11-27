/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 * 
 * Accepted
    972/972 cases passed (29 ms)
    Your runtime beats 90 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (51.1 MB)
 */
#include <vector>
#include<iostream>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> roads(n);
        vector<int> distances(n);
        iota(distances.begin(), distances.end(), 0);
        vector<int> ans;
        ans.reserve(queries.size());
        for(const auto& query : queries){
            roads[query[1]].push_back(query[0]);
            for(int v = query[1]; v < n; ++v){
                distances[v] = min(distances[v - 1] + 1, distances[v]);
                for(int l : roads[v])
                    distances[v] = min(distances[l] + 1, distances[v]);
            }
            ans.push_back(distances.back());
        }
        return ans;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, vector<int> nums){
    ss << '[';
    for(auto num : nums)
        ss << num << ',';
    ss<<"\b"<<"]";
    return ss;
}

int main(){
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};// 321
    cout << s.shortestDistanceAfterQueries(n,queries) << endl;
    n = 4;
    queries = {{0,3},{0,2}};// 11
    cout << s.shortestDistanceAfterQueries(n,queries) << endl;

    queries = {{4,6},{0,3}};// 53
    cout << s.shortestDistanceAfterQueries(7,queries) << endl;
    return 0;
}