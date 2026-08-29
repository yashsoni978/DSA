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
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);
        return 1 + max(lh, rh);
    }
    void findDiameter(TreeNode* root, int &maxi){
        if(!root) return;
        int lh = height(root -> left);
        int rh = height(root -> right);
        maxi = max(maxi, lh + rh);
        findDiameter(root -> left, maxi);
        findDiameter(root -> right, maxi);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findDiameter(root, maxi);
        return maxi;
    }
};

/*TC: O(n²) — height can be calculated repeatedly for many nodes.

SC: O(h) — recursion stack, where h is the height of the tree.*/

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
    int findDiameter(TreeNode* root, int &maxi){
        if(!root) return 0;
        int lh = findDiameter(root -> left, maxi);
        int rh = findDiameter(root -> right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findDiameter(root, maxi);
        return maxi;
    }
};

//n and n

