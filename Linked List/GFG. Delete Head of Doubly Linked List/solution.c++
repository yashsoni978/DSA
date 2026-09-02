/* Structure of doubly linked list Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    Node* deleteHead(Node* head) {
        // code here
        if(!head || !head -> next) return NULL;
        Node* prev = head;
        head = head -> next;
        head -> prev = NULL;
        prev -> next = NULL;
        delete(prev);
        return head;
    }
};
