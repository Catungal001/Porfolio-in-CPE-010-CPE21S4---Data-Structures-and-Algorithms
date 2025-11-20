#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* q_array;   
    int capacity;  
    int front;     
    int back;      
    int size;      

public:
    CircularQueue(int cap) {
        capacity = cap;
        q_array = new int[capacity];
        front = 0;
        back = capacity - 1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] q_array;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! " << value << endl;
            return;
        }
        back = (back + 1) % capacity;
        q_array[back] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! " << endl;
            return;
        }
        cout << "Dequeued: " << q_array[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < size; i++) {
            cout << q_array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); 
    q.display();

    return 0;
}