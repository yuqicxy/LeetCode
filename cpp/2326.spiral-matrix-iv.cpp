/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */
#include "common/ListNode.h"
#include <vector>
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m,vector<int>(n,-1));
        ListNode *curr = head;
        int index = 0;
        int row = m;
        int col = n;
        result[0][0] = 1;
        vector<int> anchor{0,0};
        while(curr != nullptr){
            if(index < col){
                size_t row_id = anchor[0];
                size_t col_id = anchor[1] + index;
                result[row_id][col_id] = curr->val;
            }else if(index < col - 1 + row - 1){
                size_t row_id = anchor[0] + index - (col - 1);
                size_t col_id = anchor[1] + col - 1;
                result[row_id][col_id] = curr->val;
            }else if(index < col - 1 + row - 1 + col - 1){
                size_t row_id = anchor[0] + row - 1;
                size_t col_id = anchor[1] + col - 1 - (index - (col - 1 + row - 1));
                result[row_id][col_id] = curr->val;
            }else if(index < col - 1 + row - 1 + col - 1 + row - 1){
                size_t row_id = anchor[0] + row - 1 - (index - (col - 1 + row - 1 + col - 1));
                size_t col_id = anchor[1];
                result[row_id][col_id] = curr->val;
            }
            index++;
            if(index == row - 1 + col - 1 + row - 1 + col - 1){
                index = 0;
                for(auto &a : anchor){
                    a += 1;
                }
                row -= 2;
                col -= 2;
            }
            curr = curr->next;
        }
        return result;
    }
};
// @lc code=end

void main(){
    ListNode *node = new ListNode({0});
    Solution s;
    s.spiralMatrix(1,1,node);
    ListNode *node2 = new ListNode({3,0,2,6,8,1,7,9,4,2,5,5,0});
    s.spiralMatrix(3,5,node2);
}