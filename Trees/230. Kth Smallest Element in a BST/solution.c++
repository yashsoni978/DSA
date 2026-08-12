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
    void inorder(TreeNode* root, vector<int>& inorderArr){
        if(!root) return;
        inorder(root -> left, inorderArr);
        inorderArr.push_back(root -> val);
        inorder(root -> right, inorderArr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorderArr;
        inorder(root, inorderArr);
        return inorderArr[k-1];
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
private:
    void inorder(TreeNode* root, int &cnt, int &ans, int k){
        if(!root) return;
        inorder(root -> left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root -> val;
            return;
        }
        inorder(root -> right, cnt, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, cnt = 0;
        inorder(root, cnt, ans, k);
        return ans;
    }
};