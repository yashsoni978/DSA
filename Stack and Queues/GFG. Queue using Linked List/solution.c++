class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node* front;
    Node* rear;
    int cnt;
  public:
    myQueue() {
        // Initialize your data members
        front = NULL;
        rear = NULL;
        cnt = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x);
        if(isEmpty()) front = rear = newNode;
        else{
            rear -> next = newNode;
            rear = newNode;
        }
        cnt++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        Node* temp = front;
        front = front -> next;
        delete temp;
        cnt--;
        if(front == NULL) rear = NULL;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return front -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return cnt;
    }
};