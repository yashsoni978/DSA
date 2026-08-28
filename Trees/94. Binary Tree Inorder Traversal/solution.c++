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
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        inorder(root, ans);
        return ans;
    }
};


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(true){//while(node != NULL || !st.empty())
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                ans.push_back(node -> val);
                node = node -> right;
            }
        }
        return ans;
    }
};
