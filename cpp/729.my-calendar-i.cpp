/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class StupidMyCalendar {
public:
    StupidMyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto &&r : mRanges){
            int b, e;
            tie(b, e) = r;
            if(max(b,start) < min(e, end)) 
                return false;
        }
        mRanges.push_back(make_tuple(start, end));
        return true;
    }
private:
    vector<tuple<int,int>> mRanges;
};

// @lc code=start
class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto itr = mRanges.upper_bound(start);
        if(itr != mRanges.end() && itr->second < end) return false;
        mRanges.insert({end, start});
        return true;
    }
private:
    map<int,int> mRanges;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

int main(){
    MyCalendar myCalendar;
    myCalendar.book(10, 20); // return True
    myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
    myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
}
