// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Concept used : Tree traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    map<int,vector<Node*>> m;
    
    void traverse(Node* node,int curr){
        if(node==NULL) return;
        m[curr].push_back(node);
        traverse(node->left,curr+1);
        traverse(node->right,curr+1);
    }
    
    Node* connect(Node* root) {
        traverse(root,1);
        for(auto itr:m){
            Node* tmp = NULL;
            for(int i = itr.second.size()-1;i>=0;i--){
                itr.second[i]->next = tmp;
                tmp = itr.second[i];
            }
        }
        
        return root;
    }
};
