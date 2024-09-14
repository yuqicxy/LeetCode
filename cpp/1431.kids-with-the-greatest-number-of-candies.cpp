/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto maxEle = *(max_element(candies.cbegin(),candies.cend()));

        vector<bool> ans;
        for (auto candyPerKid : candies){
            ans.push_back(!(candyPerKid + extraCandies < maxEle));
        }
        return ans;
    }
};
// @lc code=end
template<typename T>
std::ostream& operator<<(std::ostream& ss, const vector<T> &output){
    ss << "[";
    for (auto i : output)
        ss << i << ",";
    ss<< "\b]" << endl;
    return ss;
}

int main(){
    Solution s;
    cout << boolalpha <<s.kidsWithCandies(vector{2,3,5,1,3} , 3);
    //[true,true,true,false,true] 
    cout << s.kidsWithCandies(vector{4,2,1,1,2} , 1);
    //[true,false,false,false,false] 
    cout << s.kidsWithCandies(vector{12,1,12} , 10);
    //[true,false,true]
}

