/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class InitialSolution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return static_cast<int>(word2.size());
        if(word2.size() == 0) return static_cast<int>(word1.size());
        int ans = INT_MAX;
        queue<tuple<string, string, int>> sq;
        sq.push({word1,word2,0});
        while(!sq.empty()){
            string w1, w2;
            int step;
            tie(w1, w2, step)= sq.front();
            sq.pop();
            int l = static_cast<int>(min(w1.size(), w2.size()));
            int i = 0;
            for(; i < l; ++i){
                if(w1[i] != w2[i])
                    break;
            }
            w1 = w1.substr(i);
            w2 = w2.substr(i);
            if(w1.empty() || w2.empty())
                ans = min(ans, step + static_cast<int>(max(w1.size(), w2.size())));
            else{
                sq.push({w1.substr(1), w2, step + 1}); //remove
                sq.push({w1.substr(1), w2.substr(1), step + 1}); //replace
                sq.push({w1, w2.substr(1), step + 1}); //insert
            }
        }
        return ans;
    }
};

class SecondSolution {
public:
    int minDistance(string word1, string word2) {
        int w1len = static_cast<int>(word1.size()), w2len = static_cast<int>(word2.size());
        if(w1len == 0) return w2len;
        if(w2len == 0) return w1len;
        int ans = INT_MAX;
        queue<tuple<int, int, int>> sq;
        sq.push({0, 0, 0});
        while(!sq.empty()){
            int w1left, w2left, step;
            tie(w1left, w2left, step)= sq.front();
            sq.pop();
            while(w1left < w1len && w2left < w2len && word1[w1left] == word2[w2left]){
                w1left++;
                w2left++;
            }
            if(w1left == w1len || w2left == w2len)
                ans = min(ans, step + static_cast<int>(max(w1len - w1left, w2len - w2left)));
            else{
                sq.push({w1left + 1,w2left, step + 1});     //remove
                sq.push({w1left + 1,w2left + 1, step + 1}); //replace
                sq.push({w1left ,w2left + 1, step + 1});    //insert
            }
        }
        return ans;
    }
};

class SuccesssDPSolution {
public:
    int minDistance(string word1, string word2) {
        int w1len = static_cast<int>(word1.size()), w2len = static_cast<int>(word2.size());
        if(w1len == 0) return w2len;
        if(w2len == 0) return w1len;
        int ans = INT_MAX;
        vector<vector<int>> dp(w1len + 1, vector<int>(w2len + 1,INT_MAX));
        queue<tuple<int, int, int>> sq;
        sq.push({0, 0, 0});
        while(!sq.empty()){
            int w1left, w2left, step;
            tie(w1left, w2left, step)= sq.front();
            sq.pop();
            while(w1left < w1len && w2left < w2len && word1[w1left] == word2[w2left]){
                w1left++;
                w2left++;
            }
            if(w1left == w1len || w2left == w2len)
                ans = min(ans, step + static_cast<int>(max(w1len - w1left, w2len - w2left)));
            else{
                step++;
                if(dp[w1left + 1][w2left] > step){
                    dp[w1left + 1][w2left]  = step;
                    sq.push({w1left + 1,w2left, step});     //remove
                }
                if(dp[w1left + 1][w2left + 1] > step){
                    dp[w1left + 1][w2left + 1] = step;
                    sq.push({w1left + 1,w2left + 1, step}); //replace
                }
                if(dp[w1left][w2left + 1] > step){
                    dp[w1left][w2left + 1] = step;
                    sq.push({w1left ,w2left + 1, step});    //insert
                }
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1len = static_cast<int>(word1.size()), w2len = static_cast<int>(word2.size());
        if(w1len == 0) return w2len;
        if(w2len == 0) return w1len;
        int ans = INT_MAX;
        vector<vector<int>> dp(w1len + 1, vector<int>(w2len + 1,INT_MAX));
        queue<tuple<int, int, int>> sq;
        sq.push({0, 0, 0});
        while(!sq.empty()){
            int w1left, w2left, step;
            tie(w1left, w2left, step)= sq.front();
            sq.pop();
            if(w1left < w1len && w2left < w2len)
            {
                if(word1[w1left] == word2[w2left]){
                    if(dp[w1left + 1][w2left + 1] > step){
                        dp[w1left + 1][w2left + 1] = step;
                        sq.push({w1left + 1,w2left + 1, step});
                    }
                }
                else{
                    step++;
                    if(dp[w1left + 1][w2left] > step){
                        dp[w1left + 1][w2left]  = step;
                        sq.push({w1left + 1,w2left, step});     //remove
                    }
                    if(dp[w1left + 1][w2left + 1] > step){
                        dp[w1left + 1][w2left + 1] = step;
                        sq.push({w1left + 1,w2left + 1, step}); //replace
                    }
                    if(dp[w1left][w2left + 1] > step){
                        dp[w1left][w2left + 1] = step;
                        sq.push({w1left ,w2left + 1, step});    //insert
                    }
                }
            }
        }
        // return ans;
        return dp.back().back();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minDistance("a",      "b") << endl; //1
    cout << s.minDistance("horse",      "ros") << endl; //3
    cout << s.minDistance("intention", "execution") << endl; //5
    cout << s.minDistance("dinitrophenylhydrazine","acetylphenylhydrazine") << endl; //6
    cout << s.minDistance("zoogeologist","zoologicoarchaeologist") << endl; //10
}