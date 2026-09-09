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
class myStack {
    Node* topNode;
    int cnt;
  public:
    myStack() {
        // Initialize your data members
        topNode = NULL;
        cnt = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return topNode == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        newNode -> next = topNode;
        topNode = newNode;
        cnt++;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty()) return;
        Node* temp = topNode;
        topNode = topNode -> next;
        delete temp;
        cnt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()) return -1;
        return topNode -> data;
        
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};