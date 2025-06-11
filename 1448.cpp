
 
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
    int goodNodes(TreeNode* root) {
        int count=0;
        findGoodNode(root, &count, root->val);
        return count;
    }
    void findGoodNode(TreeNode* n, int* count, int max){
        if(n->val >= max){
            ++(*count);
            max=n->val;
        }
        if(n->right != nullptr) {
            findGoodNode(n->right, count, max);
        }
        if(n->left != nullptr) {
            findGoodNode(n->left, count, max);
        }
    }


};