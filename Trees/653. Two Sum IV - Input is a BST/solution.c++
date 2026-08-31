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
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root, arr);
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum == k) return true;
            if(sum < k) l++;
            else r--;
        }
        return false;
    }
};

/*TC: O(n)

Inorder = O(n)
Two pointers = O(n)

SC: O(n)

Array = O(n)
Recursion = O(h)*/

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

class BSTIterator {
private: 
    stack<TreeNode*>myStack;
    bool reverse = true;

    void pushAll(TreeNode* node){
        for(; node != NULL;){
            myStack.push(node);
            if(reverse) node = node -> right;
            else node = node -> left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode -> right);
        else pushAll(tmpNode -> left);
        return tmpNode -> val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next(), j = r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

//n and h * 2