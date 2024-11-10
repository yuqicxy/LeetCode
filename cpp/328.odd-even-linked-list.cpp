/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */
#include "common/ListNode.h"
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        auto curr = head;
        int i = 1;
        while(curr->next){
            ListNode* parentOfCandidate = curr;
            ListNode* candidate = curr->next;
            auto j = i;
            while(candidate && j--){
                parentOfCandidate = candidate;
                candidate = candidate->next;
            }

            //exchange next and candidate
            if(candidate == nullptr) break;

            ListNode *tmp  = curr->next;
            curr->next = candidate;
            parentOfCandidate->next = candidate->next;
            candidate->next = tmp;
            curr = candidate;
            ++i;
        }
        return head;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    ListNode head{1,2,3,4,5};
    cout << s.oddEvenList(&head) << endl;
    ListNode head2{2,1,3,5,6,4,7};
    cout << s.oddEvenList(&head2) << endl;


}