/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include "common/ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultHeadNode =  new ListNode();
        ListNode *x = l1;
        ListNode *y = l2;
        ListNode *curr = resultHeadNode;
        int carry = 0;
        while(x!=nullptr || y!=nullptr){
            int p = x!=nullptr ? x->val : 0;
            int q = y!=nullptr ? y->val : 0;
            int result = p+q+carry;
            curr->next = new ListNode((result)%10);
            carry = result/10;
            x = x!= nullptr ? x->next : nullptr;
            y = y!= nullptr ? y->next : nullptr;
            curr = curr->next;
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return resultHeadNode->next;
    }
};
// @lc code=end
#include <vector>
#include <iostream>

int main(){
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.
    auto l2 = new ListNode({5,6,4});
    auto l1 = new ListNode({2,4,3});

    Solution s;
    std::cout<<s.addTwoNumbers(l1,l2);
}