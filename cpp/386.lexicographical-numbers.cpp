/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i = 1; i < 10; ++i){
            if(i > n) break;
            ans.push_back(i);
            genertate(i, n , ans);
        }
        return ans;
    }

    void genertate(int prefix, int n , vector<int> &ans){
        for(int index = 0; index < 10; index++){
            int tmp = prefix * 10 + index;

            if(tmp > n) return;
            ans.push_back(tmp);

            genertate(tmp, n,ans);
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    for(auto &&i : s.lexicalOrder(13))
        cout << ',' << i;
    cout<<endl;
    for(auto &&i : s.lexicalOrder(2))
        cout << ',' << i;
    cout<<endl;
    return 0;
}
