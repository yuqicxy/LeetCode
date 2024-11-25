/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <tuple>

using namespace std;

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const vector<int> directions{0,1,0,-1,0};
        string target = "123450";
        string original = "";
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                original += to_string(board[i][j]);
        unordered_set<string> founded;
        deque<tuple<string,int>> dq;
        dq.emplace_back(move(original), 0);
        while(!dq.empty()){
            string s;
            int step;
            tie(s, step) = dq.front();
            dq.pop_front();
            if(founded.contains(s))
                continue;
            founded.insert(s);
            if(s == target)
                return step;
            size_t pos = s.find_first_of('0');
            int i = pos / 3;
            int j = pos % 3;
            for(int z = 0; z < 4; ++z){
                int r = i + directions[z];
                int c = j + directions[z + 1];
                if(r > -1 && r < 2 && c < 3 && c > -1){
                    string t = s;
                    swap(t[pos], t[r * 3 + c]);
                    dq.emplace_back(move(t), step + 1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> board = {{1,2,3},{4,0,5}};
    cout<< s.slidingPuzzle(board)<<endl; // 1
    board = {{1,2,3},{5,4,0}};
    cout<< s.slidingPuzzle(board)<<endl; //-1
    board = {{4,1,2},{5,0,3}};
    cout<< s.slidingPuzzle(board)<<endl; //5
    return 0;
}