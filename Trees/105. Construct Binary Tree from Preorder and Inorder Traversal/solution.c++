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
    TreeNode* buildTreeHelper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& inMap){
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - is;
        root -> left = buildTreeHelper(preorder, ps + 1, ps + numsLeft, inorder, is, inRoot - 1, inMap);
        root -> right = buildTreeHelper(preorder, ps + numsLeft + 1, pe, inorder, inRoot + 1, ie, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};

/*TC: O(n log n)

We use a map to find each root's position in inorder in O(log n),
and each node is processed once.

SC: O(n)

The map stores O(n) elements, and the recursion stack can take O(n)
space in the worst case (skewed tree).*/