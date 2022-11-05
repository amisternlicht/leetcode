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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
       return generateBST(nums,0,nums.size()-1);
    }

    TreeNode* generateBST(std::vector<int>& nums,int start,int end){
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* to_add = new TreeNode(nums.at(mid));
        to_add->left = generateBST(nums, start, mid - 1);
        to_add->right = generateBST(nums, mid + 1, end);
        return to_add;
    }
};

int main(){
    std::vector<int> nums = {-3,0,5,6};
    Solution s;
    TreeNode* base = s.sortedArrayToBST(nums);
}