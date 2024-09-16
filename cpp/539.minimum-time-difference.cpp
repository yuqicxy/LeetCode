/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<tuple<int,int>> valTimes;
        for(auto timepoint : timePoints){
            stringstream ss(timepoint);
            string token;
            getline(ss,token,':');
            int hour = atoi(token.c_str());
            getline(ss,token,':');
            int minute = atoi(token.c_str());
            valTimes.emplace_back(hour,minute);
        }

        sort(valTimes.begin(),valTimes.end(), [](tuple<int,int> a, tuple<int,int> b){
            return (get<0>(a) * 60 + get<1>(a)) < (get<0>(b) * 60 + get<1>(b));
        });

        int minimum = INT_MAX;
        for(size_t i = 0; i < valTimes.size(); ++i){
            int hour,minutes;
            tie(hour,minutes) = valTimes.at(i);
            int hourL,minL;
            if(i == 0){
                tie(hourL,minL) = valTimes.at(valTimes.size() - 1);
                minimum = min(minimum, 24*60 - hourL * 60 - minL + hour * 60 + minutes);
            }
            else{
                tie(hourL,minL) = valTimes.at(i - 1);
                minimum = min(minimum, (hour - hourL) * 60 + (minutes - minL));
            }
        }
        return minimum;                    
    }
};
// @lc code=end

int main(){
    vector<string> timePoints = {"23:59","00:00"};
    Solution s;
    cout<<s.findMinDifference(timePoints)<<endl;

    vector<string> timePoints2 = {"00:00","23:59","00:00"};
    cout<<s.findMinDifference(timePoints2)<<endl;
}