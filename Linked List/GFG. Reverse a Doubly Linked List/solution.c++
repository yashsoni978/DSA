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
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head || !head -> next) return head;
        stack<int>st;
        Node* temp = head;
        while(temp){
            st.push(temp -> data);
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            temp -> data = st.top();
            st.pop();
            temp = temp -> next;
        }
        return head;
    }
};

//2n and n

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
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head || !head -> next) return head;
        Node* prev = NULL;
        Node* curr = head;
        while(curr){
            prev = curr -> prev;
            curr -> prev = curr -> next;
            curr -> next = prev;
            curr = curr -> prev;
        }
        return prev -> prev;
    }
};
//n and 1