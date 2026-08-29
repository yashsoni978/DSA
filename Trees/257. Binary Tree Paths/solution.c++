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
    void solve(TreeNode* root, string curr, vector<string>& ans){
        if(!root) return;
        if(!curr.empty()) curr += "->";
        curr += to_string(root -> val);
        if(!root -> left && !root -> right){
            ans.push_back(curr);
            return;
        }
        solve(root -> left, curr, ans);
        solve(root -> right, curr, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root) return ans;
        solve(root, "", ans);
        return ans;
    }
};

/* TC: O(n * h)

Each node is visited once, but `curr` is copied at each recursive call and can
have up to O(h) length, where h is the tree height.

SC: O(h)

Recursion stack + current path string require O(h) auxiliary space.*/