/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief divide and conquer
     * 
     * @param lists 
     * @return ListNode* 
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1){
            lists.push_back(mergeTwoSortList(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    ListNode* mergeTwoSortList(ListNode* left,ListNode *right){
        if(left == nullptr)
            return right;
        if(right == nullptr)
            return left;
        if(left->val <= right->val){
            left->next = mergeTwoSortList(left->next,right);
            return left;
        }
        else{
            right->next = mergeTwoSortList(left,right->next);
            return right;
        }
    }
};
// @lc code=end

