#include <vector>
#include <set>
#include <iostream>
#include "common/ListNode.h"
using namespace std;

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
// @lc code=start
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> numset(nums.begin(),nums.end());
        ListNode* root = nullptr;
        ListNode *pre = nullptr;
        while(head != nullptr){
            if(numset.find(head->val) == numset.end()){
                if(root == nullptr)
                    root = head;
                else
                    pre->next = head;
                pre = head;
                head = head->next;
                pre->next = nullptr;
                continue;
            }
            head = head->next;
        }
        return root;
    }
};
// @lc code=end

int main(){
    Solution s;

    ListNode *head = new ListNode({1,2,3,4,5});
    vector<int> nums{1,2,3};
    head = s.modifiedList(nums,head);
    cout<<head<<endl;

    head = new ListNode({1,2,1,2,1,2});
    nums = {1};
    head = s.modifiedList(nums,head);
    cout<<head<<endl;

    head = new ListNode({1,2,3,4});
    nums = {5};
    head = s.modifiedList(nums,head);
    cout<<head<<endl;


    head = new ListNode({2,10,9});
    nums = {9,2,5};
    head = s.modifiedList(nums,head);
    cout<<head<<endl;
}

