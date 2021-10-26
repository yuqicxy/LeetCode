/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
#include <stack>
class Solution {
public:
    // **************************
    // Iterative
    // **************************
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *curr = nullptr,*prev = nullptr,*next = nullptr;
    //     while(head != nullptr && head->next != nullptr){
    //         curr = head;
    //         next = head->next;
    //         curr->next = prev;
    //         head = next;
    //         prev = curr;
    //     }

    //     if(head != nullptr)
    //     {
    //         curr = head;
    //         curr->next = prev;
    //     }
    //     return curr;
    // }
    //
    // ****************************
    // Recursive
    // ****************************
    ListNode* reverseList(ListNode* head) {
        return recursive(nullptr,head);
    }

    ListNode* recursive(ListNode *prev,ListNode *curr){
        ListNode *newHead = nullptr;
        if(curr != nullptr)
        {
            if(curr->next != nullptr)
            {
                newHead = recursive(curr,curr->next);
                curr->next = prev;
            }
            else
            {
                newHead = curr;
                newHead->next = prev;
            }
        }
        return newHead;
    }
};
// @lc code=end

