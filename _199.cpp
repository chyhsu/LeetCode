/*
LeetCode 199 – Binary Tree Right Side View
----------------------------------------
Problem (re-phrased):
Given the root of a binary tree, imagine standing on its right side and
observing the nodes you can see from top to bottom.  Return the list of
their values.

Input
 • TreeNode* root – root of the binary tree (may be nullptr).

Output
 • vector<int> – values of nodes visible from the right side.
----------------------------------------
*/
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<TreeNode*>> level;
        traverse(root, 0, level);
        vector<int> result;
        for (int i = 0; i < level.size(); i++) {
            result.push_back(level[i].back()->val);
        }
        return result;
    }
    void traverse(TreeNode* root, int level, vector<vector<TreeNode*>>& level_nodes) {
        if (root == nullptr) {
            return;
        }
        if (level_nodes.size() == level) {
            level_nodes.push_back(vector<TreeNode*>());
        }
        level_nodes[level].push_back(root);
        traverse(root->left, level + 1, level_nodes);
        traverse(root->right, level + 1, level_nodes);
    }
};

/* Reference Solution

class Solution {
public:
 vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    if (root == NULL)
    {
         return {};
    }
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() != 0)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *currNode = q.front();
            q.pop();
            if(i==size-1){
                  ans.push_back(currNode->val);
            }
          
            if (currNode->left)
            {
                q.push(currNode->left);
            }
            if (currNode->right)
            {
                q.push(currNode->right);
            }
        }
    }
    return ans;
}
};

*/