/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <string>
#include <sstream>
#include <functional>
#include <algorithm>
#include <stack>

using namespace std;

// class NestedInteger {
// public:
//     // Constructor initializes an empty nested list.
//     NestedInteger();

//     // Constructor initializes a single integer.
//     NestedInteger(int value);

//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;

//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;

//     // Set this NestedInteger to hold a single integer.
//     void setInteger(int value);

//     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//     void add(const NestedInteger &ni);

//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

class Solution {
public:
    NestedInteger deserialize(string s) {
        auto isNumber = [](char s){return s == '-' || isdigit(s);};
        stack<NestedInteger> stk;
        stk.push(NestedInteger());
        for(auto itr = s.begin(); itr != s.end(); ){
            if(isNumber(*itr)){
                auto last = find_if_not(itr,s.end(),isNumber);
                int val = stoi(string(itr,last));
                stk.top().add(NestedInteger(val));
                itr = last;
            }else{
                if(*itr == '['){
                    stk.push(NestedInteger());
                }else if(*itr == ']'){
                    NestedInteger interger = stk.top();
                    stk.pop();
                    stk.top().add(interger);
                }
                ++itr;
            }
        }
        return stk.top().getList().front();
    }
};
// @lc code=end

