/*
LeetCode 700 – Search in a Binary Search Tree
-------------------------------------------
Problem (re-phrased):
Given the root of a Binary Search Tree (BST) and an integer val, return
the node in the BST whose value equals val.  If such a node does not
exist, return nullptr.

Input
 • TreeNode* root – root of the BST (may be nullptr).
 • int val        – value to search for.

Output
 • TreeNode* – pointer to the node whose value is val, or nullptr if not
   found.
-------------------------------------------
*/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==val){
            return root;
        }else if(root->val>val){
            return searchBST(root->left, val);
        }else {
            return searchBST(root->right,val);
        }

    }
};