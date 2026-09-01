//using validate bst code
class Solution {
private:
    int maxi = 0;

    pair<bool, int> solve(Node* root, long minVal, long maxVal) {
        if(!root)
            return {true, 0};

        auto left = solve(root->left, minVal, root->data);
        auto right = solve(root->right, root->data, maxVal);

        // Current subtree is a BST
        if(left.first && right.first &&
           root->data > minVal &&
           root->data < maxVal) {

            int size = 1 + left.second + right.second;

            maxi = max(maxi, size);

            return {true, size};
        }

        // Current subtree is NOT a BST.
        // Return false, but keep searching through children.
        return {false, 0};
    }

public:
    int largestBst(Node *root) {
        maxi = 0;

        solve(root, LONG_MIN, LONG_MAX);

        return maxi;
    }
};

//n^2

class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int maxNode, int minNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue largest(Node* root) {

        if(!root)
            return NodeValue(INT_MIN, INT_MAX, 0);

        auto left = largest(root->left);
        auto right = largest(root->right);

        if(left.maxNode < root->data &&
           root->data < right.minNode) {

            return NodeValue(
                max(root->data, right.maxNode),
                min(root->data, left.minNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(
            INT_MAX,
            INT_MIN,
            max(left.maxSize, right.maxSize)
        );
    }

    int largestBst(Node* root) {
        return largest(root).maxSize;
    }
};

//n and 1(postorder traversal)