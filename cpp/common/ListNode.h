#include <initializer_list>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
   
    ListNode(int x, ListNode *next) : val(x), next(next) {}
   
    ListNode(int x) : val(x), next(nullptr) {}
   
    ListNode(const std::initializer_list<int> &list){
        val = *list.begin();
        auto pre = this;
        for(auto itr = list.begin()+1; itr < list.end(); ++itr){
            auto node = new ListNode(*itr);
            pre->next = node;
            pre = node;
        }
    }

    // ~ListNode(){
    //     if(next != nullptr)
    //         delete next;
    // }

    friend std::ostream& operator<<(std::ostream& os, const ListNode* node){
        os<<"[";
        while (node != nullptr)
        {
            os << node->val << ",";
            node = node->next;
        }
        os<<'\b'<<"]"<<std::endl;
        return os;
    }
};