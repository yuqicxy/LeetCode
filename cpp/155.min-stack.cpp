/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(mMinSTK.empty())
            mMinSTK.push(val);
        else if(mMinSTK.top() >= val){
            mMinSTK.push(val);
        }
        mSTK.push(val);
    }
    
    void pop() {
        if(mMinSTK.top() >= mSTK.top())
            mMinSTK.pop();
        mSTK.pop();
    }
    
    int top() {
        return mSTK.top();
    }
    
    int getMin() {
        return mMinSTK.top();
    }
private:
    stack<int> mSTK;
    stack<int> mMinSTK;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}