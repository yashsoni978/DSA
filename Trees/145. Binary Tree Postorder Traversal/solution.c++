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
    void postorder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        postorder(root -> left, ans);
        postorder(root -> right, ans);
        ans.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        postorder(root, ans);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root -> left) st1.push(root -> left);
            if(root -> right) st1.push(root -> right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr -> left;
            }
            else{
                TreeNode* temp = st.top() -> right;
                if(!temp){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);
                    while(!st.empty() && temp == st.top() -> right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp -> val);
                    }
                }
                else curr = temp;
            }
        }
        return ans;
    }
};
/*tc :- 2n one for storing and then again checking it and sc :- o(n)*/
