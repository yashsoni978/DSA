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
private:
    int maxPathDown(TreeNode* root, int &maxi){
        if(!root) return 0;
        int lSum = max(0, maxPathDown(root -> left, maxi));
        int rSum = max(0, maxPathDown(root -> right, maxi));
        maxi = max(maxi, root -> val + lSum + rSum);
        return root -> val + max(lSum, rSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};
//n and h