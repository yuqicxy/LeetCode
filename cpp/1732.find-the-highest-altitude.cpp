/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = altitude;
        for(auto itr = gain.begin(); itr < gain.end(); ++itr){
            altitude += *itr;
            maxAltitude = maxAltitude > altitude ? maxAltitude : altitude;
        }
        return maxAltitude;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> gain{-5,1,5,0,-7};
    vector<int> gain2{-4,-3,-2,-1,4,3,2};
    s.largestAltitude(gain);
    s.largestAltitude(gain2);
    return 0;
}

