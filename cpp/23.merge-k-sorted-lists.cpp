/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start

#include "common/ListNode.h"

#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * @brief divide and conquer
     * 
     * @param lists 
     * @return ListNode* 
     */
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.empty()) return nullptr;
    //     while(lists.size() > 1){
    //         lists.push_back(mergeTwoSortList(lists[0],lists[1]));
    //         lists.erase(lists.begin());
    //         lists.erase(lists.begin());
    //     }
    //     return lists.front();
    // }

    // ListNode* mergeTwoSortList(ListNode* left,ListNode *right){
    //     if(left == nullptr)
    //         return right;
    //     if(right == nullptr)
    //         return left;
    //     if(left->val <= right->val){
    //         left->next = mergeTwoSortList(left->next,right);
    //         return left;
    //     }
    //     else{
    //         right->next = mergeTwoSortList(left,right->next);
    //         return right;
    //     }
    // }

    /**
     * @brief priority queue method
     * 
     * @param lists 
     * @return ListNode* 
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](const ListNode* left,const ListNode* right){
            return left->val > right->val;
        };
        priority_queue<ListNode*,std::vector<ListNode*>,decltype(compare)> queue(compare);
        for(auto node : lists){
            if(node != nullptr)
                queue.push(node);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(!queue.empty())
        {
            tail->next = queue.top();
            tail = tail->next;
            queue.pop();
            if(tail->next)
                queue.push(tail->next);
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};
// @lc code=end

int main(){
    vector<vector<int>> input = {{1,4,5},{1,3,4},{2,6}};
    std::vector<ListNode*> lists;
    for (auto &&linkList : input)
    {
        if(linkList.empty()) continue;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        for(auto && val : linkList){
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        lists.push_back(dummy->next);
        delete dummy;
    }
    
    Solution s;
    ListNode* node = s.mergeKLists(lists);
    while(node != nullptr){
        cout<<node->val<<"  ";
        node = node->next;
    }

    return 1;
}