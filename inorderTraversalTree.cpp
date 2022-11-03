#include <iostream>
#include <vector>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //recursive
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> inorderLeft;
        if(root->left != nullptr){
            inorderLeft = inorderTraversal(root->left);
        }
        inorderLeft.emplace_back(root->val);
        if(root->right != nullptr){
            std::vector<int> inorderRight = inorderTraversal(root->right);
            inorderLeft = combine(inorderLeft, inorderRight);
        }
        return inorderLeft;
    }
    
    std::vector<int> combine(const std::vector<int>& a, const std::vector<int>& b){
        std::vector<int> vec(a);
        for(int i = 0; i<b.size(); i++){
            vec.emplace_back(b[i]);
        }
        return vec;
    }
};


int main(){
    TreeNode left(2);
    TreeNode right(3,&left,nullptr);
    TreeNode root(1,nullptr,&right);
    Solution s;
    std::vector<int> vec = s.inorderTraversal(&root);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl; 
    }
}