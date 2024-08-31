#include <initializer_list>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(const std::initializer_list<int> &list):TreeNode()
    {
        std::deque<TreeNode*> queue;
        std::initializer_list<int>::iterator itr = list.begin();
        this->val = *(itr++);
        queue.push_back(this);
        while(!queue.empty()){
            auto currNode = queue.front();
            queue.pop_front();
            if(itr < list.end())
            {
                auto node = new TreeNode(*(itr++));
                queue.push_back(node);
                currNode->left=node;
            }
            if(itr < list.end())
            {
                auto node = new TreeNode(*(itr++));
                queue.push_back(node);
                currNode->right=node;
            }
        }
    }

private:
    TreeNode* constructTree(const std::initializer_list<int> &list){
    }

    ~TreeNode(){
        if(this->left != nullptr)
            delete this->left;
        if(this->right != nullptr)
            delete this->right;
    }
};