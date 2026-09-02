/* Linked List Node Structure
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover -> next = temp;
            mover = temp;
        }
        return head;
    }
};

//n and n