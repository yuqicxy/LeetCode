/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) 
    {
        mSeries[start]++;
        mSeries[end]--;
        int signal = 0;
        for (auto it = mSeries.begin(); it != mSeries.end(); it++) {
            signal += it->second;
            if (signal == 3){
                mSeries[start]--;
                mSeries[end]++;
                return false;
            }
        }
        return true;
    }

private: 
    map<int,int> mSeries; //pair< end, start>
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

int main(){
    MyCalendarTwo myCalendarTwo;// = new MyCalendarTwo();
    cout << boolalpha;
    // cout << myCalendarTwo.book(26,35) << endl; // true
    // cout << myCalendarTwo.book(26,32) << endl; // true
    // cout << myCalendarTwo.book(25,32) << endl; // false


    cout << myCalendarTwo.book(10, 20) << endl; // return True, The event can be booked. 
    cout << myCalendarTwo.book(50, 60) << endl; // return True, The event can be booked. 
    cout << myCalendarTwo.book(10, 40) << endl; // return True, The event can be double booked. 
    cout << myCalendarTwo.book(5, 15) << endl;  // return False, The event cannot be booked, because it would result in a triple booking.
    cout << myCalendarTwo.book(5, 10) << endl; // return True, The event can be booked, as it does not use time 10 which is already double booked.
    cout << myCalendarTwo.book(25, 55) << endl; // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
}

