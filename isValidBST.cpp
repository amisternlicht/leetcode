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
    bool isValidBST(TreeNode* root) {
        //given the left and right trees are valid BST's, check max_left < root < min right
        if(((root->left)&&!isValidBST(root->left)) ||((root->right)&&!isValidBST(root->right)) ){
            return false;
        }
        TreeNode* max_left = nullptr;
        TreeNode* min_right = nullptr;
        TreeNode* temp = root->left;
        //get max
        if(temp != nullptr){
            while(temp->right != nullptr){
                temp = temp->right;
            }
        }
        max_left = temp;
        //get max
        temp = root->right;
        if(temp != nullptr){
            while(temp->left != nullptr){
                temp = temp->left;
            }
        }
        min_right = temp;
        if(((max_left)&&(max_left->val < root->val)) && ((min_right)&&(min_right->val > root->val))){
            return true;
        }
        //only right
        else if((max_left == nullptr) && ((min_right)&&(min_right->val > root->val))){
            return true;
        }
        //only left
        else if((min_right == nullptr) && ((max_left)&&(max_left->val < root->val))){
            return true;
        }
        //none
        else if((min_right == nullptr) && (max_left == nullptr)){
            return true;
        }
        return false;
    }
};


int main(){
    TreeNode two(27);
    TreeNode one(19,nullptr,&two);
    TreeNode three(26,&one,nullptr);
    TreeNode six(56);
    TreeNode five(47,nullptr,&six);
    TreeNode four(32,&three,&five);
    Solution s;
    bool result = s.isValidBST(&four);
}