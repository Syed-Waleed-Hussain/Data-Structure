#include <iostream>
using namespace std;

class LinearQueue {
    int *arr;
    int front, rear, capacity;

public:
    LinearQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~LinearQueue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (rear == capacity - 1) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << "Patron " << val << " added to the queue." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Patron " << arr[front++] << " removed from the queue." << endl;
    }

    void displayQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q1(5);
    q1.enqueue(101);
    q1.enqueue(102);
    q1.enqueue(103);
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    q1.enqueue(104);
    q1.enqueue(105);
    q1.enqueue(106);
    q1.displayQueue();
    q1.dequeue();
    q1.displayQueue();
    return 0;
}
