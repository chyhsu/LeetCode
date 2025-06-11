/*
LeetCode 104 – Maximum Depth of Binary Tree
------------------------------------------
Problem (re-phrased):
Given the root of a binary tree, compute the length of the longest path
from the root down to any leaf (i.e. the tree's height counted in
nodes).

Input
 • TreeNode* root – root of the binary tree (may be nullptr).

Output
 • int – maximum depth (0 if the tree is empty).
------------------------------------------
*/
#include <iostream>
using namespace std;


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
    int maxDepth(TreeNode* root) {
        return findDepth(root);
    }

    int findDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int max_left = findDepth(root->left);
        int max_right = findDepth(root->right);
        return max(max_left, max_right) + 1;
    }
};

