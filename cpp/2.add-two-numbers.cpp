/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

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

