/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (size_t i = 0; i < flowerbed.size(); ++i) {
            if(!flowerbed[i]) {
                bool checkLast = true;
                if( i > 0 && flowerbed[i - 1])
                    checkLast = false;
                bool checkNext = true;
                if( i < flowerbed.size() - 1 && flowerbed[i + 1])
                    checkNext  = false;
                if(checkLast && checkNext){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n > 0 ? false : true;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha << s.canPlaceFlowers(vector{1,0,0,0,1} , 1) << endl;
    cout << s.canPlaceFlowers(vector{1,0,0,0,0,1} , 2);

}