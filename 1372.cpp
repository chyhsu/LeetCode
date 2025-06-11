/*
LeetCode 1372 – Longest ZigZag Path in a Binary Tree
---------------------------------------------------
Problem (re-phrased):
A ZigZag path starts at any node and alternates between moving to a left
child and a right child with each step.  Given the root of a binary tree,
return the length (number of edges) of the longest ZigZag path in the
tree.

Input
 • TreeNode* root – root of the binary tree.

Output
 • int – maximum ZigZag path length (edges count; 0 if root is nullptr).
---------------------------------------------------
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int max_count=0;
        int count=0;   
        dfs(root->left,count,&max_count,'N','l');
        dfs(root->right,count,&max_count,'N','r');
        
        return max_count;
    }
    void dfs(TreeNode* node, int count, int* max_count, char pre, char cur){
        if(node==nullptr){
            return;
        }
        
        if(pre!=cur){
            count++;
        }else{
            count=0;
        }
        *max_count=std::max(*max_count,count);
        cout<<pre<<" "<<cur<<" "<<count<<endl;
        dfs(node->left,count,max_count,cur,'l');
        dfs(node->right,count,max_count,cur,'r');
        
    }
};
/* Reference Solution

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int f, int l){
        if(root == nullptr) return;
        ans = max(l,ans);
        if(f != -1){
            dfs(root->left,-1,l+1);
        }else{
            dfs(root->left,-1,1);
        }
        if(f != 1){
            dfs(root->right,1,l+1);
        }
        else{
            dfs(root->right,1,1);
        }

    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        return ans ;
    }
};
*/