class myQueue {
    int *arr;
    int front, rear, size, cnt;

public:
    myQueue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        cnt = 0;
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == size;
    }

    void enqueue(int x) {
        if (isFull()) return;

        rear = (rear + 1) % size;
        arr[rear] = x;
        cnt++;
    }

    void dequeue() {
        if (isEmpty()) return;

        front = (front + 1) % size;
        cnt--;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }
};