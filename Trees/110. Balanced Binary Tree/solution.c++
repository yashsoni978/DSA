class Solution {
private:
    int findLH(TreeNode* root){
        if(!root) return 0;

        int lh = findLH(root->left);
        int rh = findLH(root->right);

        return 1 + max(lh, rh);
    }

    int findRH(TreeNode* root){
        if(!root) return 0;

        int lh = findRH(root->left);
        int rh = findRH(root->right);

        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lh = findLH(root->left);
        int rh = findRH(root->right);

        if(abs(rh - lh) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};

//n^2

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
    int dfsHeight(TreeNode* root){
        if(!root) return 0;
        int lh = dfsHeight(root -> left);
        int rh = dfsHeight(root -> right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};

/*TC: O(n) — Every node is visited once.

SC: O(h) — Recursion stack, where h is the height of the tree.*/