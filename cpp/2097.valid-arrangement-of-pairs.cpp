/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 */
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FailedSolution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int M = pairs.size();
        vector<vector<int>> ans(M, vector<int>(2,0));
        int flag = M-1;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < M; ++i)
            hash[pairs[i].front()].push_back(i);
        vector<bool> founded(M, false);
        for(int id = 0; id < M; ++id){
            if(!founded[id]){
                founded[id] = true;
                dfs(pairs, id, hash, founded, ans, flag);
                ans[flag--] = pairs[id];
            }
        }
        return ans;
    }

    void dfs(const vector<vector<int>>& pairs, const int id,
        const unordered_map<int, vector<int>> &hash,
        vector<bool> &founded,
        vector<vector<int>> &ans,
        int &flag){
        if(!hash.count(pairs[id].back())) return;
        for(int idx : hash.at(pairs[id].back())){
            if(!founded[idx]){
                founded[idx] = true;
                dfs(pairs, idx, hash, founded, ans, flag);
                ans[flag--] = pairs[idx];
            }
        }
    }
};

// @lc code=start
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        // Eulerian Path
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> in;
        unordered_map<int, int> out;
		// reserve spaces for unordered_map may help in runtime.
		adj.reserve(m);
		in.reserve(m);
		out.reserve(m);
        for (int i = 0; i < m; i++) {
            int u = pairs[i][0], v = pairs[i][1];
            in[v]++;
            out[u]++;
            adj[u].push(v);
        }
		// find the starting node
        int start = -1;
        for (auto& p : adj) {
            int i = p.first;
            if (out[i] - in[i] == 1) start = i;
        }
        if (start == -1) {
			// Eulerian Circuit -> start at any node
			start = adj.begin()->first;
        }
        vector<vector<int>> ans;
        euler(adj, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void euler(unordered_map<int, stack<int>>& adj, vector<vector<int>>& ans, int curr) {
        auto& stk = adj[curr];
        while (!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            euler(adj, ans, nei);
			// postorder
            ans.push_back({curr, nei});
        }
    }
};
// @lc code=end

std::ostream& operator<<(std::ostream &ss, const vector<int>& nums){
    ss << "[";
    for(auto num : nums){
        ss << num << ",";
    }
    ss <<"\b"<<"]";
    return ss;
}

ostream& operator<<(ostream &ss, const vector<vector<int>>& nums){
    ss << "[";
    for(auto num : nums){
        ss << num << ",";
    }
    ss << "\b" <<"]";
    return ss;
}

int main(){
    Solution s;
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
    cout << s.validArrangement(pairs) << endl;
    pairs = {{1,3},{3,2},{2,1}};
    cout << s.validArrangement(pairs) << endl;
    pairs = {{1,2},{1,3},{2,1}};
    cout << s.validArrangement(pairs) << endl;
    pairs = {{5,13},{10,6},{11,3},{15,19},{16,19},{1,10},{19,11},{4,16},{19,9},{5,11},{5,6},{13,5},{13,9},{9,15},{11,16},{6,9},{9,13},{3,1},{16,5},{6,5}};
    //[[4,16],[16,5],[5,6],[6,5],[5,11],[11,16],[16,19],[19,9],[9,13],[13,5],[5,13],[13,9],[9,15],[15,19],[19,11],[11,3],[3,1],[1,10],[10,6],[6,9]]
    cout << s.validArrangement(pairs) << endl;
}