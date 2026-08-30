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
    TreeNode* buildTreeHelper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int>& inMap){
        if(is > ie || ps > pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - is;
        root -> left = buildTreeHelper(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, inMap);
        root -> right = buildTreeHelper(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        map<int,int>inMap;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }
};

/*TC: O(n log n)

We use a map to find each root's position in inorder in O(log n),
and each node is processed once.

SC: O(n)

The map stores O(n) elements, and the recursion stack can take O(n)
space in the worst case (skewed tree).*/