#include <iostream>
#include <vector>
#include <queue>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//using BFS type algorithm
class Solution {

public:

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> arr;
        if(root == nullptr){
            return arr;
        }
        //init queue with root
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            std::vector<int> ans;
            //process all nodes in queue (all these nodes are in the same level!)  
            int n = q.size(); //save the size of the queue before start processing
            for(int i=0; i < n ;i++){
                TreeNode* cur = q.front();
                q.pop();
                //1.add value of node to ans
                ans.push_back(cur->val);
                //2. add all children to queue, push left son first because print order is left->right
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            //add level to final vector 
            arr.push_back(ans);
        }
        return arr;
    }
    
};


int main(){
    TreeNode one(1);
    TreeNode two(2,&one,nullptr);
    TreeNode four(4);
    TreeNode six(6);
    TreeNode five(5,&four,&six);
    TreeNode root(3,&two,&five);
    //      3
    //     / \
    //    2   5
    //   /   / \
    //  1   4   6
    Solution s;
    std::vector<std::vector<int>> vec = s.levelOrder(&root);
    for (int i = 0; i < vec.size(); i++){
        std::cout << "level " << i << ":" << std::endl;
        for (int j = 0; j < vec[i].size(); j++){
            std::cout << vec[i][j] << " "; 
        }
        std::cout  << std::endl;
    }
}