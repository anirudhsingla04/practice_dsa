class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enQueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false; // full
        }
        else if (front == -1) { // first element
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) { // wrap around
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (front == -1) return false; // empty

        arr[front] = -1;
        if (front == rear) { // only one element
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0; // wrap
        }
        else {
            front++;
        }
        return true;
    }

    int Front() {
        if (front == -1) return -1;
        return arr[front];
    }

    int Rear() {
        if (rear == -1) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size));
    }
};
