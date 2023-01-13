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
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> merge(vector<int> &arr1, vector<int> &arr2){
        int n = arr1.size(), m = arr2.size();
        vector<int> res;
        int i = 0, j = 0;
        while(i<n and j<m){
            if(arr1[i] <= arr2[j]) res.push_back(arr1[i]), i++;
            else res.push_back(arr2[j]), j++;
        }
        while(i < n) res.push_back(arr1[i]), i++;
        while(j < m) res.push_back(arr2[j]), j++;
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        return merge(arr1, arr2);
    }
};
