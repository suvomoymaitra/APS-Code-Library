// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Concept used : Lowest common ancestor
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
    TreeNode* LCA;
    void find_addr(TreeNode* root,int target){
        if(root==NULL) return;
        if(root->val==target){
            LCA = root;
            return;
        }
        find_addr(root->left,target);
        find_addr(root->right,target);
    }
    
    bool findPath(TreeNode *root, vector<int> &path, int k){
        // base case
        if (root == NULL) return false;
 
        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root->val);
 
        // See if the k is same as root's key
        if (root->val == k)
            return true;
 
        // Check if k is found in left or right sub-tree
        if ( (root->left && findPath(root->left, path, k)) ||
             (root->right && findPath(root->right, path, k)) )
            return true;
 
        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
            return false;
    }
 
    // Returns LCA if node n1, n2 are present in the given binary tree,
    // otherwise return -1
    int findLCA(TreeNode *root, int n1, int n2){
        // to store paths to n1 and n2 from the root
        vector<int> path1, path2;
 
        // Find paths from root to n1 and root to n1. If either n1 or n2
        // is not present, return -1
        if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
              return -1;
 
        /* Compare the paths to get the first different value */
        int i;
        for (i = 0; i < path1.size() && i < path2.size() ; i++)
            if (path1[i] != path2[i])
                break;
        return path1[i-1];
    }
    
    
    string c;
    string d;
    void traverse1(TreeNode* root,int target,int curr){
        if(root==NULL){
            return;
        }
        curr++;
        if(root->val==target){
            for(int i=0;i<curr-1;i++){
               c = std::move(c)+'U'; 
            }
            return;
        }
        traverse1(root->left,target,curr);
        traverse1(root->right,target,curr);
    }
    
    bool traverse2(TreeNode* root,int target){
        if(root==NULL) return false;
        if(root->val == target) return true;
        bool res1 = traverse2(root->left,target);
        bool res2 = traverse2(root->right,target);
        if(res1){
            d = std::move(d)+'L';
            // return true;
        }
        if(res2){
            d = std::move(d)+'R';
            // return true;
        }
        if(!res1 and !res2) return false;
        else return true;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int tmp = findLCA(root,startValue,destValue);
        find_addr(root,tmp);
        root = LCA;
        traverse1(root,startValue,0);
        traverse2(root,destValue);
        reverse(d.begin(),d.end());
        return c+d;
    }
};
