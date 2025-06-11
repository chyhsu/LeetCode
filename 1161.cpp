/*
LeetCode 1161 – Maximum Level Sum of a Binary Tree
-------------------------------------------------
Problem (re-phrased):
For each level of a binary tree, compute the sum of the node values on
that level.  Return the level (1-indexed) that has the maximum sum; if
multiple levels share the same largest sum, return the smallest level
number.

Input
 • TreeNode* root – root of the binary tree (may be nullptr).

Output
 • int – 1-based level index with the maximum sum.
-------------------------------------------------
*/
#include <queue>
#include <climits>
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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = INT_MIN;
        int max_level = 0;
        int level = 0;
        while (!q.empty()) {
            
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_level = level;
            }
            level++;
        }
        return max_level + 1;
    }
};