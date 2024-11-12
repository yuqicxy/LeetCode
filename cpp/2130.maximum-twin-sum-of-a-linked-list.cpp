/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

#include "common/ListNode.h"
#include <iostream>
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
    ListNode* reverseList(ListNode* curr, ListNode* prev = nullptr){
        while(curr){
            swap(curr->next, prev);
            swap(prev != nullptr ? prev->next : prev, curr);
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = reverseList(slow);
        ListNode *left = head;
        int maxSum = 0;
        while(left != nullptr && right != nullptr){
            maxSum = max(left->val + right->val, maxSum);
            left = left->next;
            right = right->next;
        }
        return maxSum;
    }
};
// @lc code=end

int main(){
    ListNode node{5,4,2,1};
    Solution s;
    cout << s.pairSum(&node) <<endl;
}