/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        Node* temp1 = head;
        vector<vector<int>>ds;
        while(temp1){
            Node* temp2 = temp1 -> next;
            while(temp2 && temp1 -> data + temp2 -> data <= target){
                if(temp1 -> data + temp2 -> data == target) ds.push_back({temp1 -> data, temp2 -> data});
                temp2 = temp2 -> next;
            }
            temp1 = temp1 -> next;
        }
        return ds;
    }
};

//n^2 and 1

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  private:
    Node* findTail(Node* head){
        Node* tail = head;
        while(tail -> next) tail = tail -> next;
        return tail;
    }
  public:
    vector<vector<int>> givenSumPairs(Node* head, int k) {
        // code here
        vector<vector<int>>ans;
        if(!head) return ans;
        Node* left = head;
        Node* right = findTail(head);
        while(left -> data < right -> data){
            if(left -> data + right -> data == k){
                ans.push_back({left -> data, right -> data});
                left = left -> next;
                right = right -> prev;
            }
            else if(left -> data + right -> data < k) left = left -> next;
            else right = right -> prev;
        }
        return ans;
    }
};

/*TC: O(n)

findTail() → O(n)
Two-pointer traversal → O(n)
Overall → O(n)

SC: O(1) auxiliary space

Only pointers are used.
But ans stores the output pairs, so including output space: O(p), where p = number of pairs.*/