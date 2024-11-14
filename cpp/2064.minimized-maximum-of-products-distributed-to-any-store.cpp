/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class StupidSolution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        priority_queue<tuple<int, int ,int> > pq; // quantity, storeNum, productType 
        for(int i = 0; i < quantities.size(); ++i){
            pq.emplace(quantities[i], 1, i);
        }
        n -= quantities.size();
        while(n--){
            auto [quantity, storeNum, productType] = pq.top();
            storeNum++;
            pq.pop();
            pq.emplace((quantities[productType] + storeNum - 1)/storeNum , storeNum, productType);
        }
        return get<0>(pq.top());
    }
};

// @lc code=start
class Solution {
public:
    //binary search
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto upper = *max_element(begin(quantities),end(quantities));
        auto lower = 1;
        while(lower < upper){
            auto mid = (upper + lower) / 2;
            int storeNum = 0;
            for(auto quantity : quantities)
                storeNum += (quantity + mid - 1) / mid;
            if(storeNum <= n)
                upper = mid;
            else
                lower = mid + 1;
        }
        return lower;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector quantities{11,6};
    cout << s.minimizedMaximum(6, quantities) << endl;

    quantities = {15,10,10};
    cout << s.minimizedMaximum(7, quantities) << endl;

    quantities = {100000};
    cout << s.minimizedMaximum(1, quantities) << endl;
    
    return 0;
}