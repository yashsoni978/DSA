class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        Node* temp = head;
        int cnt = 0;

        while(temp){
            if(cnt == p) break;
            cnt++;
            temp = temp -> next;
        }

        Node* newNode = new Node(x);

        newNode -> next = temp -> next;
        newNode -> prev = temp;

        if(temp -> next)
            temp -> next -> prev = newNode;

        temp -> next = newNode;

        return head;
    }
};