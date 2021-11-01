/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length())
            return addStrings(num2,num1);
        int sum = 0;
        auto num1Itr = num1.rbegin();
        for(auto num2Itr = num2.rbegin(); num2Itr != num2.rend(); ++num2Itr,++num1Itr){
            sum = sum + (*num1Itr - '0') + (*num2Itr - '0');
            *num1Itr = sum%10 + '0';
            sum = sum/10;
        }
        while(sum != 0){
            if(num1Itr != num1.rend()){
                sum = (*num1Itr  - '0') + sum;
                *num1Itr = sum%10 + '0';
                sum = sum/10;
                num1Itr++;
            }else{
                char c = sum + '0';
                stringstream ss;
                ss<<c;
                string str;
                ss>>str;
                num1 = str.append(num1);
                sum = 0;
            }
        }
        return num1;
    }
};
// @lc code=end

