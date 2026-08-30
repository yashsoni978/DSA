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
    void inorder(TreeNode* root, int &cnt){
        if(!root) return;
        cnt++;
        inorder(root -> left, cnt);
        inorder(root -> right, cnt);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};
//n and h

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
    int findLH(TreeNode* node){
        int lh = 0;
        while(node){
            lh++;
            node = node -> left;
        }
        return lh;
    }
    int findRH(TreeNode* node){
        int rh = 0;
        while(node){
            rh++;
            node = node -> right;
        }
        return rh;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLH(root);
        int rh = findRH(root);
        if(lh == rh) return (1 << lh) - 1; //2^lh - 1
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
/*TC: O(log² n)

At each recursive level, findLH() and findRH() take O(log n),
and there are O(log n) recursive levels.

SC: O(log n)

Due to recursion. The tree is complete, so its height is O(log n).*/

//Note : here finding LH and RH means height of the leftmost part and rightmost part respectively it doesnt mean finding the general height of BT