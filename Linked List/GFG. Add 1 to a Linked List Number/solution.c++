/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  private:
    Node* reverseList(Node* head) {
        if(!head || !head -> next) return head;
        Node* newHead = reverseList(head -> next);
        Node* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
  public:
    Node* addOne(Node* head) {
        // code here
        head = reverseList(head);
        Node* temp = head;
        int carry = 1;
        while(temp){
            temp -> data += carry;
            if(temp -> data < 10){
                carry = 0;
                break;
            }
            else{
                temp -> data = 0;
                carry = 1;
            }
            temp = temp -> next;
        }
        if(carry == 1){
            Node* newNode = new Node(1);
            head = reverseList(head);
            newNode -> next = head;
            return newNode;
        }
        head = reverseList(head);
        return head;
    }
};

//3n and 1


//Without reversing the code
/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  private:
    int helper(Node* temp){
        if(!temp) return 1;
        int carry = helper(temp -> next);
        temp -> data += carry;
        if(temp -> data < 10) return 0;
        temp -> data = 0;
        return 1;
    }
  public:
    Node* addOne(Node* head) {
        // code here
        int carry = helper(head);
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode -> next = head;
            return newNode;
        }
        return head;
    }
};
//n and n
