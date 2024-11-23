/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class StupidSolution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int M = box.size();
        const int N = box.front().size();
        vector<vector<char>> ans(N, vector<char>(M,'.'));
        for(int r = 0; r < M; r++){
            int count = 0;
            for(int c = 0; c < N; c++){
                if(box[r][c] == '*'){
                    ans[c][M - 1 - r] = '*';
                    int row = c;
                    while(count--)
                        ans[--row][M - 1 - r] = '#';
                    count = 0;
                }else if(box[r][c] == '#'){
                    count++;
                }
            }
            int row = N;
            while(count--)
                ans[--row][M - 1 - r] = '#';
        }
        return ans;
    }
};


// @lc code=start
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int M = box.size();
        const int N = box.front().size();
        vector<vector<char>> ans(N, vector<char>(M,'.'));
        for(int row = 0; row < M; row++){
            for(int col = N - 1, k = N - 1; col >= 0; col--){
                if(box[row][col] == '*'){
                    k = col;
                    ans[k][M - 1 - row] = box[row][col];
                    k--;
                }
                else if(box[row][col] == '#'){
                    ans[k--][M - 1 - row] = box[row][col];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, const vector<vector<char>> &box)
{
    ss << '[' << endl;
    for(const auto &row : box){
        ss<<"  [";
        for(auto ele : row){
            ss << ele << " ,";
        }
        ss<<"\b"<< "],"<<endl;
    }
    ss<<']';
    return ss;
}


int main(){
    Solution s;

    vector<vector<char>> box{{'#','.','#'}};
    cout << s.rotateTheBox(box) << endl;

    box = {{'#','.','*','.'},
            {'#','#','*','.'}};
    cout << s.rotateTheBox(box) << endl;

    box = {{'#','#','*','.','*','.'},
            {'#','#','#','*','.','.'},
            {'#','#','#','.','#','.'}};
    cout << s.rotateTheBox(box) << endl;
    return 0;
}