/*
LeetCode 437 – Path Sum III
--------------------------
Problem (re-worded):
Given the root of a binary tree and an integer targetSum, count the total
number of paths that start at *any* node, move downward (parent → child),
and whose node values sum up exactly to targetSum.
The path does not need to reach a leaf and must follow the parent/child
links.

Input
 • TreeNode* root      – root of the binary tree.
 • int targetSum       – target value (could be negative).

Output
 • int – number of valid downward paths whose values sum to targetSum.
--------------------------
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
    int pathSum(TreeNode* root, int targetSum) {
        
    }
    int checkSum(vector<int> &path, int targetSum) {
        int count=0;
        int r=0;
        int l=0;
        int sum=path[0];
        while(r<path.size()){
            if(sum==targetSum){
                count++;
            }
            if(sum<targetSum){
                r++;
                if(r<path.size()){
                    sum+=path[r];
                }
            }
            if(sum>targetSum){
                sum-=path[l];
                ++l;
                if(l==r){
                    ++r;
                    if(r<path.size()){
                        sum=path[r];
                    }
                }
            }
        }
        return count;
    }

};