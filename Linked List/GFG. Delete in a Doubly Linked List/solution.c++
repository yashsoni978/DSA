/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  private:
    Node* deleteHead(Node* head){
        if(!head || !head -> next) return NULL;
        Node* prev = head;
        head = head -> next;
        head -> prev = NULL;
        prev -> next = NULL;
        delete(prev);
        return head;
    }
    Node* deleteTail(Node* head){
        if(!head || !head -> next) return NULL;
        Node* tail = head;
        while(tail -> next) tail = tail -> next;
        tail -> prev -> next = NULL;
        tail -> prev = NULL;
        delete(tail);
        return head;
    }
  public:
    Node* delPos(Node* head, int k) {
        // code here
        if(!head) return NULL;
        int cnt = 0;
        Node* temp = head;
        while(temp){
            cnt++;
            if(cnt == k) break;
            temp = temp -> next;
        }
        if(!temp) return head;
        Node* prev = temp -> prev;
        Node* front = temp -> next;
        if(!prev && !front) return NULL;
        else if(!prev) return deleteHead(head);
        else if(!front) return deleteTail(head);
        prev -> next = front;
        front -> prev = prev;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete(temp);
        return head;
    }
};