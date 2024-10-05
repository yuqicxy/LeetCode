/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        size_t N = s1.size();
        size_t M = s2.size();
        vector<int> dict(26,0);
        for (auto &&character : s1)
            dict[character - 'a']++;
        auto tmp = dict;
        for(int j = 0; j < M; ++j){
            auto index = s2[j] - 'a';
            if(dict[index] != 0){
                tmp[index]--;
            }
            if(!(j < N)){
                index = s2[j - N] - 'a';
                if(dict[index] != 0){
                    tmp[index]++;
                }
            }
            if(all_of(tmp.begin(), tmp.end(), [](auto val){return val == 0;}))
                return true;
        }
        return false;     
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha;
    cout << s.checkInclusion("ab", "eidbaoo") << endl;
    cout << s.checkInclusion("ab", "boa") << endl;
    cout << s.checkInclusion("adc", "dcda") << endl; //true
}
