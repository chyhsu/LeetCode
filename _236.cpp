/*
LeetCode 236 – Lowest Common Ancestor of a Binary Tree
-----------------------------------------------------
Problem (re-phrased):
Given a binary tree and two nodes p and q, find their lowest common
ancestor (LCA) – the deepest node that has both p and q as descendants
(where a node can be a descendant of itself).

Input
 • TreeNode* root – root of the binary tree.
 • TreeNode* p    – first node.
 • TreeNode* q    – second node.

Output
 • TreeNode* – lowest common ancestor of p and q.
-----------------------------------------------------
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        
        
            
        int i = 0;
        while(i < path_p.size() && i < path_q.size() && path_p[i] == path_q[i]){
            i++;
        }
        return path_p[i-1];
    }
    
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(root == nullptr) return false;
        
        path.push_back(root);
        
        if(root == target) return true;
        
        if(findPath(root->left, target, path) || findPath(root->right, target, path)){
            return true;
        }
        
        path.pop_back(); // Backtrack
        return false;
    }
};
/*

 
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l!=nullptr && r!=nullptr){
            return root;
        }
        if(l==nullptr)return r;
        else if(r==nullptr)return l;
        else return root;
    }
};
*/