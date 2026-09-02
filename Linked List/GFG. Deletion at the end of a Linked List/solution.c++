/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        // code here
        if(!head || !head -> next) return NULL;
        Node* temp = head;
        while(temp -> next -> next) temp = temp -> next;
        delete(temp -> next);
        temp -> next = NULL;
        return head;
    }
};