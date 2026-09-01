/*For the brute-force approach, use the BST property:

Store all node values using inorder traversal.
Sort the values.
Compare the original inorder values with the sorted values.
The two positions where they differ are the swapped nodes.
Swap their values in the tree.*/

class Solution {
private:
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if(!root) return;

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;

        // Store nodes in inorder
        inorder(root, nodes);

        // Store their values
        vector<int> values;

        for(TreeNode* node : nodes)
            values.push_back(node->val);

        // Correct inorder of a BST should be sorted
        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());

        // Find the two incorrect nodes
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i = 0; i < values.size(); i++) {
            if(values[i] != sorted[i]) {
                if(!first)
                    first = nodes[i];
                else
                    second = nodes[i];
            }
        }

        // Swap their values
        swap(first->val, second->val);
    }
};

/*Inorder traversal → O(n)
Copy + sort       → O(n log n)
Comparison        → O(n)

TC: O(n log n)

SC: O(n)*/

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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        if(prev && (prev -> val > root -> val)){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }
};


/*n and 1*/