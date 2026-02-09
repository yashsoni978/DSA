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

//n and n(array + recursion)
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
    TreeNode* build(vector<int>& arr, int left, int right){
        if(left > right) return NULL;
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = build(arr, left, mid-1);
        root -> right = build(arr, mid+1, right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root, arr);
        return build(arr, 0, arr.size()-1);
    }
};

