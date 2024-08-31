/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
#include <set>
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> results;
        results.insert(0);
        deque<int> keys;
        keys.push_back(0);
        while(!keys.empty()){
            auto key = keys.front();
            keys.pop_front();
            for(auto k : rooms[key]){
                auto p = results.insert(k);
                if(p.second)
                    keys.push_back(k);
            }
        }
        if(results.size() == rooms.size())
            return true;
        return false;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};
    bool result = s.canVisitAllRooms(rooms);
    return result;
}
