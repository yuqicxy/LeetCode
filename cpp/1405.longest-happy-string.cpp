/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class StupidSolution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        vector<pair<int, char>> mq;
        if(a > 0) mq.push_back({a,'a'});
        if(b > 0) mq.push_back({b,'b'});
        if(c > 0) mq.push_back({c,'c'});
        make_heap(mq.begin(), mq.end());
        while(!mq.empty()){
            auto top = mq.begin();
            if(ans.size() > 1 && *ans.rbegin() == *(ans.rbegin() + 1) && *ans.rbegin() == top->second){
                if(!(mq.size() > 1))
                    break;
                pop_heap(mq.begin(),mq.end());
                ans += top->second;
                if(!(--(top->first) > 0))
                    mq.erase(top);
                make_heap(mq.begin(), mq.end());
            }else{
                ans += top->second;
                if(!(--(top->first) > 0))
                    mq.erase(top);
                make_heap(mq.begin(), mq.end());
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        deque<pair<int, char>> mq;
        if(a > 0) mq.push_back({a,'a'});
        if(b > 0) mq.push_back({b,'b'});
        if(c > 0) mq.push_back({c,'c'});
        while(!mq.empty()){
            make_heap(mq.begin(), mq.end());
            auto top = mq.begin();
            if(*ans.rbegin() == top->second && ans.size() > 1 &&  *ans.rbegin() == *(ans.rbegin() + 1)){
                if(!(mq.size() > 1))
                    break;
                pop_heap(mq.begin(),mq.end());
                ans += top->second;
                if(!(--(top->first) > 0))
                    mq.pop_front();
            }else{
                ans += top->second;
                if(!(--(top->first) > 0))
                    mq.pop_front();
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.longestDiverseString(1,1,7) << endl;
    cout << s.longestDiverseString(7,1,0) << endl;
}