/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int K) {
        // code here
        if(!head) return head;
        if(K == 1){
            Node* temp = head;
            head = head -> next;
            delete(temp);
            return head;
        }
        Node* temp = head;
        int cnt = 0;
        Node* prev = NULL;
        while(temp){
            cnt++;
            if(cnt == K){
                prev -> next = prev -> next -> next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};

//n and 1