/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  private:
    bool isLeaf(Node* root){
        if(!root -> left && !root -> right) return true;
        return false;
    }
    void addLeftB(Node* root, vector<int>& res){
        Node* curr = root -> left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr -> data);
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;
        }
    }
    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root -> data);
            return;//I found a leaf, added it, and there is nothing more to traverse from this node.
        }
        if(root -> left) addLeaves(root -> left, res);
        if(root -> right) addLeaves(root -> right, res);
    }
    void addRightB(Node* root, vector<int>& res){
        Node* curr = root -> right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr -> data);
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }
        for(int i=temp.size()-1; i>=0; i--) res.push_back(temp[i]);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root -> data);
        addLeftB(root, res);
        addLeaves(root, res);
        addRightB(root, res);
        return res;
    }
};

/*TC: O(n)

Every node is visited at most a constant number of times
while finding the left boundary, leaves, and right boundary.

SC: O(h)

O(h) recursion stack for addLeaves() + O(h) temporary
space for the right boundary, where h is the height of the tree.*/