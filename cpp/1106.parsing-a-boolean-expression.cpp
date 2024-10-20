/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stringstream ss(expression);
        return parseBoolExpr(ss);
    }

private:
    bool parseBoolExpr(stringstream &ss){
        char c = 0;
        while(ss.get(c)){
            switch (c)
            {
                case 't':
                    return true;
                case 'f':
                    return false;
                case '|':
                    return parseOrExpr(ss);
                case '&':
                    return parseAndExpr(ss);
                case '!':
                    return parseNotExpr(ss);
            }
        }
        return false;
    }

    bool parseNotExpr(stringstream &ss){
        char c = 0;
        bool result = false;
        int bracketCount = 0;
        while(ss.get(c)){
            switch(c){
                case '(':
                    bracketCount++;
                    result = !parseBoolExpr(ss);
                    break;
                case ')':
                    bracketCount--;
                    break;
            }
            if(bracketCount == 0)
                break;
        }
        return result;
    }

    bool parseAndExpr(stringstream &ss){
        char c = 0;
        bool result = true;
        int bracketCount = 0;
        while(ss.get(c)){
            switch(c){
                case '(':
                    bracketCount++;
                    result &= parseBoolExpr(ss);
                    break;
                case ',':
                    result &= parseBoolExpr(ss);
                    break;
                case ')':
                    bracketCount--;
                    break;
            }
            if(bracketCount == 0)
                break;
        }
        return result;
    }

    bool parseOrExpr(stringstream &ss){
        char c = 0;
        bool result = false;
        int bracketCount = 0;
        while(ss.get(c)){
            switch(c){
                case '(':
                    bracketCount++;
                    result |= parseBoolExpr(ss);
                    break;
                case ',':
                    result |= parseBoolExpr(ss);
                    break;
                case ')':
                    bracketCount--;
                    break;
            }
            if(bracketCount == 0)
                break;
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha;
    cout << s.parseBoolExpr("&(|(f))") << endl; //false
    cout << s.parseBoolExpr("|(f,f,f,t)") << endl; //true
    cout << s.parseBoolExpr("!(&(f,t))") << endl; //true
    cout << s.parseBoolExpr("&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f))") << endl; //false
    cout << s.parseBoolExpr("!(&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)))") << endl; //true
}