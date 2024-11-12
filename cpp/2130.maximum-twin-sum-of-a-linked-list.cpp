/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

#include "common/ListNode.h"

#include <deque>

using namespace std;

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
    int pairSum(ListNode* head) {
        deque<ListNode*> dq;
        while(head != nullptr){
            dq.push_back(head);
            head = head->next;
        }
        int maxSum = 0;
        while(!dq.empty()){
            ListNode *left = dq.front(), *right = dq.back(); 
            maxSum = max(maxSum, left->val + right->val);
            dq.pop_front();
            dq.pop_back();
        }
        return maxSum;
    }
};
// @lc code=end

