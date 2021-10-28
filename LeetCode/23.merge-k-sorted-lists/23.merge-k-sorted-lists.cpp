#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main(){
    vector<vector<int>> input = {{1,4,5},{1,3,4},{2,6}};
    std::vector<ListNode*> lists;
    for (auto &&linkList : input)
    {
        if(linkList.empty()) continue;
        ListNode *tail = new ListNode(linkList.at(0));
        ListNode *dummy = new ListNode(0,tail);
        for(int i = 1; i < linkList.size(); ++i){
            tail->next = new ListNode(linkList.at(i));
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