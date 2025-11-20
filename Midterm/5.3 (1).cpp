#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int* data;
    int maxSize;
    int frontIndex;
    int rearIndex;
    int count;

public:
    SimpleQueue(int cap) {
        maxSize = cap;
        data = new int[maxSize];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~SimpleQueue() {
        delete[] data;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rearIndex = (rearIndex + 1) % maxSize;
        data[rearIndex] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << data[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % maxSize;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << data[(frontIndex + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleQueue q(5);

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(20);
    q.display();

    return 0;
}
