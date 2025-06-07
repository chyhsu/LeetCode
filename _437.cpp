#include <iostream>
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
        int count=0;
        vector<TreeNode*> result;
        traverse(root,&result);
        for(auto i:result){
            findPath(i,(long long)targetSum,&count);
        }
        return count;
    }
    void traverse(TreeNode* root, vector<TreeNode*> *result){
        if(root==nullptr){
            return;
        }
        result->push_back(root);
        traverse(root->left,result);
        traverse(root->right,result);
    }
    int findPath(TreeNode* root, long long targetSum, int *count){
        if(root==nullptr){
            return 0;
        }
        if(root->val==targetSum){
            (*count)++;
        }
        findPath(root->left,targetSum-root->val,count);
        findPath(root->right,targetSum-root->val,count); 
        return *count;
    }
};
//Reference Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==NULL){
//             return 0;
//         }
//         unordered_map<long long int,long long int>mp;
//         mp[0]=1;
//         int ans=0;
//         func(root,targetSum,mp,0,ans);
//         return ans;
//     }

//     void func(TreeNode* root, int targetSum, unordered_map<long long int,long long int>&mp,long long int sum,int &ans){
//         if(root==NULL){
//             return;
//         }
//         sum=sum+root->val;
//         if(mp[sum-targetSum]>0){
//             ans=ans+mp[sum-targetSum];
//         }
//         mp[sum]++;
//         func(root->left,targetSum,mp,sum,ans);
//         func(root->right,targetSum,mp,sum,ans);
//         mp[sum]--;
//         return;
//     }
// };