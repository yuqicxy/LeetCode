/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */
#include <vector>
#include <functional>
using namespace std;

class SolutionStupid {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<vector<int>> store(arr.size(), vector<int>(arr.size(), -1));
        function<int(int,int)> subQuery = [&](int left, int right)->int{
            if(auto val = store[left][right]; val != -1)
                return val;
            if(right - left > 0){
                int mid = (right - left) / 2 + left;
                int leftVal = store[left][mid];
                if(leftVal == -1){
                    leftVal = subQuery(left, mid);
                    store[left][mid] = leftVal;
                }

                int rightVal = store[mid + 1][right];
                if(rightVal == -1){
                    rightVal = subQuery(mid + 1, right);
                    store[mid + 1][right] = rightVal;
                }
                store[left][right] =  leftVal ^ rightVal;
                return store[left][right];
            }else
                return arr[left];
        };
        vector<int> results;
        for(auto query : queries){
            results.push_back(subQuery(query[0],query[1]));
        }
        return results;
    }
};

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xor(arr.size(),0)
        xor[0] = arr[0];
        for(size_t i = 1; i < arr.size(); ++i)
            xor[i] = arr[i] ^ xor[i-1];

        vector<int> results;
        for(auto query : queries)
            if(query[0] == 0)
                results.push_back( arr[query[1]] );
            else
                results.push_back( arr[query[0] - 1] ^ arr[query[1]] );
        return results;
    }
};

// @lc code=end
int main(){
    Solution s;
    // Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
    // Output: [2,7,14,8] 
    auto resutl = s.xorQueries(vector{1,3,4,8}, vector<vector<int>>{{0,1},{1,2},{0,3},{3,3}});
    // Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
    // Output: [8,0,4,4]
    resutl = s.xorQueries(vector{4,8,2,10}, vector<vector<int>>{{2,3},{1,3},{0,0},{0,3}});
    return 0;
}

