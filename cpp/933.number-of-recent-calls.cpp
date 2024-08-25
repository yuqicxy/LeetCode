/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
// @lc code=start
class RecentCounter {
public:
    RecentCounter() {
    }
    
    // int ping(int t) {
    //     int i = 1;
    //     const int threshold = t - 3000;
    //     for_each(mHistory.begin(),mHistory.end(),[threshold,&i](auto value){
    //         if(!(value < threshold)) ++i;
    //     });
    //     mHistory.push_back(t);
    //     return i;
    // }

    int ping(int t){
        const int threshold = t - 3000;
        mHistory.push_back(t);
        while(mHistory.front() < threshold)
            mHistory.pop_front();

        return mHistory.size();
    }
private:
    deque<int> mHistory;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

int main(){
    RecentCounter *obj = new RecentCounter();
    vector<int> times{1,100,3001,3002}, result;
    for(auto t : times){
        result.push_back(obj->ping(t));
    }
    return 0;
}