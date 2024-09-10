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

#include <numeric>
#include <iostream>
#include "common/ListNode.h"

// @lc code=start

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;

        while(curr && curr->next){
            ListNode *next = curr->next;
            int val = std::gcd(curr->val,next->val);
            ListNode *mid = new ListNode(val);
            curr->next = mid;
            mid->next = next;
            curr = next;
        }

        return head;
    }
};
// @lc code=end

void main(){
    ListNode * root = new ListNode({18,6,10,3});
    Solution s;
    s.insertGreatestCommonDivisors(root);
    std::cout<<root<<std::endl;
}

