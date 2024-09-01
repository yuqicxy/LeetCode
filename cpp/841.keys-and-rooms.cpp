/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
#include <set>
#include <vector>
#include <deque>
using namespace std;
class Solution_Qi {
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

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> openedRoom(rooms.size(),false);
        openedRoom[0] = true;
        int count = dfs(rooms,0,openedRoom) + 1;
        return count == rooms.size();
    }

    int dfs(vector<vector<int>>& rooms, const int &key,vector<bool>& openedRoom){
        int count = 0;
        for(auto subKey : rooms[key]){
            if(openedRoom[subKey]) continue;
            openedRoom[subKey] = true;
            count += dfs(rooms,subKey,openedRoom) + 1;
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};
    vector<vector<int>> rooms{{1},{2},{3},{}};
    bool result = s.canVisitAllRooms(rooms);
    return result;
}
