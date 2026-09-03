/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        Node* temp = head1;
        unordered_map<Node*,int>mp;
        while(temp){
            mp[temp] = 1;
            temp = temp -> next;
        }
        temp = head2;
        while(temp){
            if(mp.find(temp) != mp.end()) return temp;
            temp = temp -> next;
        }
        return temp;
    }
};

//n1 + n2 and n1

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  private:
    Node* helper(Node* t1, Node* t2, int d){
        while(d){
            d--;
            t2 = t2 -> next;
        }
        while(t1 != t2){
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return t1;
    }
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        Node* t1 = head1;
        int n1 = 0;
        while(t1){
            n1++;
            t1 = t1 -> next;
        }
        Node* t2 = head2;
        int n2 = 0;
        while(t2){
            n2++;
            t2 = t2 -> next;
        }
        if(n1 < n2) return helper(head1, head2, n2 - n1);
        return helper(head1, head2, n1 - n2);
    }
};
//n1 + 2n2 and 1

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != temp2){
            temp1 = (temp1 == NULL) ? head2 : temp1 -> next;
            temp2 = (temp2 == NULL) ? head1 : temp2 -> next;
        }
        return temp1;
    }
};
//n1 + n2