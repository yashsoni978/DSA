/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertPos(Node* head, int k, int el) {
        // code here
        if(!head){
            if(k == 1) return new Node(el);
            else return head;
        }
        if(k == 1){
            Node* newNode = new Node(el);
            newNode -> next = head;
            head = newNode;
            return head;
        }
        int cnt = 0;
        Node* temp = head;
        while(temp){
            cnt++;
            if(cnt == k-1){
                Node* x = new Node(el);
                x -> next = temp -> next;
                temp -> next = x;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};