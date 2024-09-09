/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */
#include <string>
#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<size_t> r_q,d_q;

        for(size_t roundIndex = 0; roundIndex < senate.size(); ++roundIndex)
            senate[roundIndex] == 'R' ? r_q.push(roundIndex) : d_q.push(roundIndex);

        while(!r_q.empty() && !d_q.empty()){
            size_t r = r_q.front();
            size_t d = d_q.front();
            r_q.pop();
            d_q.pop();
            r < d ? r_q.push(r+senate.size()) : d_q.push(d+senate.size());
        }

        return r_q.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end
int main(){
    Solution s;
    cout<<s.predictPartyVictory("RD")<<endl; //Radiant win
    cout<<s.predictPartyVictory("RDD")<<endl; //Dire win
    cout<<s.predictPartyVictory("RDRDD")<<endl; //Radiant win
    cout<<s.predictPartyVictory("DDRRR")<<endl; //Dire win
}

