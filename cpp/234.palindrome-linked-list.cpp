/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    /**
     * @brief O(N) space complexity O(N) time complexity
     * 
     * @param head 
     * @return true 
     * @return false 
     */
    // bool isPalindrome(ListNode* head) {
    //     ListNode *left = head;
    //     ListNode *right = head;
    //     std::stack<ListNode*> stk;
    //     while(right){
    //         stk.push(right);
    //         right = right->next;
    //     }
    //     right = stk.top();
    //     stk.pop();
    //     while(left != nullptr && right!= nullptr && left->val == right->val ){
    //         if(left == right)
    //             return true;
    //         left = left->next;
    //         if(left == right)
    //             return true;
    //         right = stk.top();
    //         stk.pop();
    //     }
    //     return false;
    // }

    /**
     * @brief O(1) space O(N) time complexity
     * 
     * @param head 
     * @return true 
     * @return false 
     */
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        // slow and fast are used to find middle node
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast != nullptr){
            slow = slow->next;
        }

        slow = reverseList(slow);

        while(slow != nullptr && head != nullptr){
            if(slow->val == head->val){
                slow = slow->next;
                head = head->next;
                continue;
            }
            return false;
        }
        return true;
    }
    /**
     * @brief reverse the link node
     * 
     * @param node 
     * @return ListNode* 
     */
    ListNode* reverseList(ListNode *node){
        ListNode *head = node;
        ListNode* newNext = nullptr; 
        while(head){
            ListNode* oldNext = head->next;
            head->next = newNext;
            newNext = head;
            head = oldNext;
        }
        return newNext;
    }
};
// @lc code=end