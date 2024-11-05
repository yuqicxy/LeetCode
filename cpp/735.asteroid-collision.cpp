/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> stk;
        for(int i = 0;i < asteroids.size(); ++i){
            int right = asteroids[i];
            while(!stk.empty()){
                int left = stk.back();
                if(right < 0 && left * right < 0){
                    if(abs(left) > abs(right)){
                        right = 0;
                    }else if(abs(left) == abs(right)){
                        right = 0;
                        stk.pop_back();
                    }
                    else{
                        stk.pop_back();
                        continue;
                    }
                }
                break;
            }
            if(right != 0)
                stk.push_back(right);
        }
        return vector<int>(stk.begin(), stk.end());
    }
};

// @lc code=end
ostream& operator<<(ostream &ss, const vector<int> &nums){
    ss << "[";
    for(auto num : nums)
        ss << num << ", ";
    ss << "]";
    return ss;
}

int main(){
    Solution s;
    vector asteroids{5,10,-5};
    cout << s.asteroidCollision(asteroids) << endl;
    asteroids = {8,-8};
    cout << s.asteroidCollision(asteroids) << endl;
    asteroids = {10,2,-5};
    cout << s.asteroidCollision(asteroids) << endl;
    asteroids = {-2,-1,1,2};
    cout << s.asteroidCollision(asteroids) << endl;
    asteroids = {-2,-2,1,-2};
    cout << s.asteroidCollision(asteroids) << endl;
    return 0;
}
