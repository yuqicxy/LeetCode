/*
 * @lc app=leetcode id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        items.push_back({0,0});
        sort(items.begin(), items.end());

        for(size_t i = 1; i < items.size(); ++i)
            items[i][1] = max(items[i-1][1], items[i][1]);

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto query : queries){
            auto itr = upper_bound(begin(items), end(items), vector{query, INT_MAX});
            ans.push_back((--itr)->back());
        }
        return ans;
    }
};
// @lc code=end

ostream& operator<< (ostream& ss, vector<int> nums){
    cout << "[";
    for(auto num:nums){
        cout << num << ", ";
    }
    cout << "\b\b" << "]";
    return ss;
}

int main(){
    Solution s;

    vector<vector<int>> items{{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector queries{1,2,3,4,5,6};
    cout << s.maximumBeauty(items, queries) << endl;

    items = {{1,2},{1,2},{1,3},{1,4}};
    queries = {1};
    cout << s.maximumBeauty(items, queries) << endl;

    items = {{10,1000}};
    queries = {5};
    cout << s.maximumBeauty(items, queries) << endl;

    items = {{193,732},{781,962},{864,954},{749,627},{136,746},{478,548},
            {640,908},{210,799},{567,715},{914,388},{487,853},{533,554},
            {247,919},{958,150},{193,523},{176,656},{395,469},{763,821},
            {542,946},{701,676}};
    queries = {885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584};
    cout << s.maximumBeauty(items, queries) << endl; //[962,962,962,962,746,962,962,962,946,962,962,919,746,746,962,962,962,919,962]

    return 0;
}