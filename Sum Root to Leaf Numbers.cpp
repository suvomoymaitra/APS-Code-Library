// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Concept used : tree traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans;
    
    Solution(){
        ans = 0;
    }
    
    void traverse(TreeNode* root,int curr){
        if(root==NULL){
            // ans+=curr;
            return;
        }
        curr*=10;
        curr+=root->val;
        if(root->left==NULL and root->right==NULL){
            ans+=curr;
            return;
        }
        traverse(root->left,curr);
        traverse(root->right,curr);
    }
    
    int sumNumbers(TreeNode* root) {
        traverse(root,0);
        return ans;
    }
};
