/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <iostream>

using namespace std;

// @lc code=start

class Solution {
public:
    // map<char,function<int(int,int)>> mOpersFuncPtr{
    //     {'+', [](int left, int right){return left + right;}},
    //     {'-', [](int left, int right){return left - right;}},
    //     {'*', [](int left, int right){return left * right;}}
    // };

    vector<int> diffWaysToCompute(string expression) {
        size_t index = 0;
        bool isNumber = true;
        vector<int> ans;
        for(auto &&character : expression){
            index++;
            if(!isdigit(character)){
                isNumber = false;
                auto left = diffWaysToCompute(expression.substr(0,index));
                auto right = diffWaysToCompute(expression.substr(index+1));
                for(auto &&l : left){
                    for(auto &&r : right){
                        switch (character)
                        {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }

        if(isNumber) ans.push_back(stoi(expression));
        return ans;
    }
};
// @lc code=end

int main(){
    string expression = "2*3-4*5";
    Solution s;
    auto ans = s.diffWaysToCompute(expression);
    for (auto &&a : ans)
        cout<<a<<',';
    cout<<endl;

    ans = s.diffWaysToCompute("2-1-1");
    for (auto &&a : ans)
        cout<<a<<',';
    cout<<endl;
}