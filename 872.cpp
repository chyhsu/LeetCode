
#include<vector>
#include<algorithm>
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
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leaf;
        vector<int> root2_leaf;
        findLeaf(root1, &root1_leaf);
        findLeaf(root2, &root2_leaf);
        
        
        
        // Compare the sorted vectors
        return root1_leaf == root2_leaf;
    }
    void findLeaf(TreeNode* head, vector<int>* Leaf){
        
        if(head==nullptr) return;
        if(head->right==nullptr && head->left==nullptr){
            Leaf->push_back(head->val);
            return;
        }
        findLeaf(head->right, Leaf);
        findLeaf(head->left, Leaf);
    }
};
