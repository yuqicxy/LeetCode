/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = nullptr;
//         random = nullptr;
//     }
// };

class Solution {
public:
    // O(N) space O(N) time
    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*,Node*> sets;
    //     Node *dummyNode = new Node(0);
    //     Node *curr = dummyNode;
    //     while(head){
    //         auto itr = sets.find(head);
    //         if(itr != sets.end())
    //             curr->next = itr->second;
    //         else{
    //             curr->next = new Node(head->val);
    //             sets[head] = curr->next;
    //         }
    //         if(head->random){
    //             auto itr = sets.find(head->random);
    //             if(itr != sets.end())
    //                 curr->next->random = itr->second;
    //             else{
    //                 curr->next->random = new Node(head->random->val);
    //                 sets[head->random] = curr->next->random;
    //             }
    //         }
    //         curr = curr->next;
    //         head = head->next;
    //     }
    //     Node *result = dummyNode->next;
    //     delete dummyNode;
    //     return result;
    // }

    /**
     * @brief O(1) space (don't need to keep so much pointer +_+) O(3N) time
     * 
     * https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)
     * 
     * @param head 
     * @return Node* 
     */
    Node* copyRandomList(Node* head) {
        Node* newHead = head;
        while(head){
            Node *newNode = new Node(head->val);
            newNode->next = head->next;
            head->next = newNode;
            head = newNode->next;
        }

        head = newHead;
        while(head){
            if(head->random){
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }

        head = newHead;
        if(head)
            newHead = head->next;
        while(head){
            Node *next = head->next;
            if(next)
                head->next = head->next->next;
            head = next;
        }
        return newHead;
    }
};
// @lc code=end

