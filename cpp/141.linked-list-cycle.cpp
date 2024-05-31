/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
#include "common/ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /* my solution*/
    // bool hasCycle(ListNode *head) {
    //     if(head == nullptr || head->next == nullptr) return false;
    //     ListNode *singleStep = head;
    //     ListNode *doubleStep = head->next->next;
    //     while(singleStep != doubleStep){
    //         if(singleStep == nullptr 
    //             || doubleStep == nullptr
    //             || doubleStep->next == nullptr)  
    //             return false;
    //         singleStep = singleStep->next;
    //         doubleStep = doubleStep->next->next;
    //     }
    //     return true;
    // }
    /**
     * @brief other guys' solution
     * 
     * @param head 
     * @return true 
     * @return false 
     */
    bool hasCycle(ListNode *head) {
        ListNode *singleStep = head;
        ListNode *doubleStep = head;
        while(doubleStep != nullptr && doubleStep->next != nullptr){
            singleStep = singleStep->next;
            doubleStep = doubleStep->next->next;
            if(singleStep == doubleStep) return true;
        }
        return false;
    }
};
// @lc code=end

int main(){
    return 0;
}