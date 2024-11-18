/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size(), -1);
        
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < equations.size(); ++i){
            auto eq = equations[i];
            auto iter = graph.find(eq[0]);
            if(iter != graph.end()){
                iter->second.insert({eq[1], values[i]});
            }else{
                graph[eq[0]] = {{eq[1], values[i]}};
            }

            iter = graph.find(eq[1]);
            if(iter != graph.end()){
                iter->second.insert({eq[0], 1.0f/values[i]});
            }else{
                graph[eq[1]] = {{eq[0], 1.0f/values[i]}};
            }
        }

        unordered_set<string> foundedNode;
        for(int i = 0; i < queries.size(); ++i){
            ans[i] = dfs(graph, foundedNode, queries[i]);
            foundedNode.clear();
        }

        return ans;
    }

    double dfs(unordered_map<string, unordered_map<string, double>>  &graph,unordered_set<string>& found, vector<string> &query){
        double val = -1;
        found.insert(query[0]);
        auto itr = graph.find(query[0]);
        if(itr != graph.end()){
            const auto &dests = itr->second;
            auto destItr = dests.find(query[1]);
            if(destItr != dests.end())
                return destItr->second;
            for(auto dest : dests){
                if(found.find(dest.first) != found.end())
                    continue;
                query[0] = dest.first;
                double v = dfs(graph, found, query);
                if(v > 0){
                    return v * dest.second;
                }
            }
        }
        return val;
    }
};
// @lc code=end

template<typename T>
ostream& operator<<(ostream& ss, const vector<T>& nums){
    ss << '[';
    for(auto num : nums){
        ss << num << ",";
    }
    ss << "\b" << "]";
    return ss;
}

int main(){
    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    cout << s.calcEquation(equations, values, queries) << endl;
    return 0;
}