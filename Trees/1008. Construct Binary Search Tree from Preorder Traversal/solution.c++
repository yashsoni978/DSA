/*preorder[ps] = root

Find the first element > root->val
        ↓
Everything before it  → LEFT subtree
Everything after it   → RIGHT subtree*/

class Solution {
private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if(start > end) return NULL;

        // First element is the root
        TreeNode* root = new TreeNode(preorder[start]);

        // Find first element greater than root
        int i = start + 1;

        while(i <= end && preorder[i] < root->val) {
            i++;
        }

        // [start + 1 ... i - 1] → Left subtree
        root->left = build(preorder, start + 1, i - 1);

        // [i ... end] → Right subtree
        root->right = build(preorder, i, end);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};

//n^2 


//sorting the preorder array which gives inorder and create unique bt which is bst
class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder,
                        int ps, int pe,
                        vector<int>& inorder,
                        int is, int ie,
                        map<int, int>& inMap) {

        if(ps > pe || is > ie)
            return NULL;

        // First element of preorder = root
        TreeNode* root = new TreeNode(preorder[ps]);

        // Find root position in inorder
        int inRoot = inMap[root->val];

        // Number of elements in left subtree
        int numsLeft = inRoot - is;

        // Build left subtree
        root->left = buildTree(
            preorder,
            ps + 1,
            ps + numsLeft,
            inorder,
            is,
            inRoot - 1,
            inMap
        );

        // Build right subtree
        root->right = buildTree(
            preorder,
            ps + numsLeft + 1,
            pe,
            inorder,
            inRoot + 1,
            ie,
            inMap
        );

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // BST inorder = sorted order
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        // Store inorder indices
        map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree(
            preorder,
            0,
            preorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1,
            inMap
        );
    }
};
//n log n + n and n

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
    TreeNode* build(vector<int>& preorder, int &i, int bound){
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = build(preorder, i, root -> val);
        root -> right = build(preorder, i, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vQector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
//3n and 1


