class Solution {
private:
    void inorder(Node* root, vector<Node*>& arr) {
        if(!root) return;

        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }

public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> arr;
        inorder(root, arr);

        int n = arr.size();

        // Find first node >= key
        int low = 0, high = n - 1;
        int pos = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid]->data >= key) {
                pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        Node* pred = NULL;
        Node* succ = NULL;

        if(pos < n && arr[pos]->data == key) {
            // Key exists
            if(pos > 0)
                pred = arr[pos - 1];

            if(pos + 1 < n)
                succ = arr[pos + 1];
        }
        else {
            // Key does not exist
            // pos = first element greater than key

            if(pos > 0)
                pred = arr[pos - 1];

            if(pos < n)
                succ = arr[pos];
        }

        return {pred, succ};
    }
};

//n + n log n and n

/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void inorder(Node* root, vector<int>& arr){
        if(!root) return;
        inorder(root -> left, arr);
        arr.push_back(root -> data);
        inorder(root -> right, arr);
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<int>arr;
        inorder(root, arr);
        Node* pre = NULL;
        Node* succ = NULL;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < key) pre = new Node(arr[i]);
            if(arr[i] > key){
                succ = new Node(arr[i]);
                break;
            }
        }
        return {pre, succ};
    }
};

//n and 1

/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* succ = NULL;
        while(root){
            if(root -> data > key){
                succ = root;
                root = root -> left;//But there might be a smaller greater value in the left subtree, so move left
            }
            else if(root -> data < key){
                pre = root;
                root = root -> right;
            }
            else{//we are at the key
                //Find pre
                Node* temp = root -> left;//move to left subtree
                while(temp){
                    pre = temp;
                    temp = temp -> right;//then keep going right as the The rightmost node in the left subtree is the predecessor
                }
                temp = root -> right;
                while(temp){
                    succ = temp;
                    temp = temp -> left;
                }
                break;
            }
        }
        return {pre,succ};
    }
};