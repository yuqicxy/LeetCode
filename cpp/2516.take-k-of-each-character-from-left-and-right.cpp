/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;

        vector<int> counts(3, 0);
        for(int i = 0; i < s.size(); ++i)
            counts[s[i] - 'a']++;

        for(auto count : counts)
            if(count < k)
                return -1;
        
        int window = 0;
        int ans = INT_MAX;
        int j = 0;

        for(int i = 0; i < s.size(); ++i){
            counts[s[i] - 'a']--;
            window++;
            while(counts[s[i] - 'a'] < k){
                counts[s[j] - 'a']++;
                j++;
                window--;
            }
            ans = min(ans, (int)s.size() - window);
        }

        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.takeCharacters("aabaaaacaabc", 2) << endl;

    return 0;
}