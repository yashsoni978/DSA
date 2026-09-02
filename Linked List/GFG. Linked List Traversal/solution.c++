/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void printList(Node* head) {
        // code here
        Node* temp = head;
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
};