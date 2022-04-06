// https://leetcode.com/problems/path-sum-ii/
// Concept used : Tree traversal
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
    
    vector<vector<int>> ans;
    
    void solve(TreeNode* tmp,int curr,int target,vector<int> v){
        // if(curr==target and tmp==NULL){
        //     ans.push_back(v);
        //     return;
        // }
        if(tmp==NULL) return;
        if(tmp->left==NULL and tmp->right==NULL and target==curr){
            ans.push_back(v);
            return;
        }
        v.push_back(tmp->val);
        solve(tmp->left,curr+tmp->val,target,v);
        solve(tmp->right,curr+tmp->val,target,v);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        solve(root,0,targetSum,tmp);
        return ans;
    }
};
