/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */
#include<vector>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        ListNode *curr = head;
        while(curr != nullptr){
            result.push_back(curr);
            curr = curr->next;
        }

        int residue =  result.size() % k;
        int multiple = result.size() / k;

        vector<ListNode*> resultRet(k,nullptr);
        int pos = 0;
        resultRet[0] = head;
        for(auto i = 1; i < k; ++i){
            pos += multiple;
            if(residue > 0){
                pos++;
                residue--;
            }
            if(pos < result.size()){
                result[pos - 1]->next = nullptr;
                resultRet[i] = result[pos];
            }
            else
                resultRet[i] = nullptr;
        }

        return resultRet;
    }
};
// @lc code=end

void main(){
    ListNode *node = new ListNode({1,2,3});
    Solution s;
    s.splitListToParts(node,5);
    node = new ListNode({1,2,3,4,5,6,7,8,9,10});
    s.splitListToParts(node, 3);
}

