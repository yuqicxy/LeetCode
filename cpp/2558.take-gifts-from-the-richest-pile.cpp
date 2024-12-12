/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;


class MySolution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue pq(gifts.begin(), gifts.end());
        long long count = 0;
        while(k-- > 0){
            int curr = pq.top();
            pq.pop();
            int left = floor(sqrt(curr));
            count += (curr - left);
            pq.push(left);
        }
        return accumulate<vector<int>::iterator, long long>(gifts.begin(), gifts.end(), 0) - count;
    }
};

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while(k-- > 0){
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = static_cast<int>(sqrt(gifts.back()));
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
// @lc code=end

int main(){
    Solution s;

    vector gifts{25,64,9,4,100};
    cout << s.pickGifts(gifts, 4) << endl; //29

    gifts = {1,1,1,1};
    cout << s.pickGifts(gifts, 4) << endl; //4

    return 0;
}