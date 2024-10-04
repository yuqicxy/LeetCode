/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class FaultSolution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        size_t sum = 0;
        unordered_map<int, int> mHash;
        for_each(skill.begin(), skill.end(), [&](const int &val){
            sum += val;  //sum overflow
            mHash[val] = mHash.count(val) ? mHash[val] + 1 : 1;
        });
        size_t n = skill.size();
        if(sum % (n / 2) != 0) return -1;

        int subArraySum = (int)(sum / (n / 2));
        int res = 0;
        
        for(size_t i = 0; i < n; ++i){
            int wanted = subArraySum - skill[i];
            if(mHash.count(wanted) && mHash[wanted] > 0){
                mHash[wanted]--;
                res += wanted * skill[i];
            }else{
                return -1;
            }
        }
        return res / 2;
    }
};

// @lc code=start
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        int N = skill.size()/2;
        int subSum =  skill.front() + skill.back();

        size_t i = 0, j = 2 * N - 1;
        long long res = 0;
        for(;i < j; ++i, --j){
            if(skill[i] + skill[j] != subSum)
                return -1;
            else
                res += skill[i] * skill[j];
        }
        return res;
    }

};
// @lc code=end

int main(){
    Solution s;
    vector<int> skill{3,2,5,1,3,4};
    cout << s.dividePlayers(skill) << endl;
    skill = {3,4};
    cout << s.dividePlayers(skill) << endl;
    skill = {1,1,2,3};
    cout << s.dividePlayers(skill) << endl;
    return 0;
}