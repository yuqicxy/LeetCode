/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        int number;
        istringstream iss(s);
        stack<int> stk;
        char op = '+';
        while(iss>>number){
            if(op == '+' || op == '-'){
                stk.push(op == '+' ? number : -number);
            }else{
                int last = stk.top();
                stk.pop();
                if(op=='*') last *= number;
                else last /= number;
                stk.push(last);
            }
            iss>>op;
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.calculate("3+5/2");
    return 1;
}
// @lc code=end

