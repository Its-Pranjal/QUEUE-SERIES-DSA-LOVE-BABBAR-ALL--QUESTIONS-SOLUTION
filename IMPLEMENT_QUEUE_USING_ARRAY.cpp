#include <iostream>
using namespace std;

class Queue {

public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size) {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void elementPush(int data) {
        if (rear == size - 1) {  // Corrected condition for overflow
            cout << "Queue is overflow" << endl;
        } else {
            rear++;
            arr[rear] = data;
        }
    }

    int elementPop() {
        if (front == rear) {  // Corrected condition for underflow
            cout << "Queue is underflow" << endl;
            return -1;  // Return some default value in case of underflow
        } else {
            front++;
            int ans = arr[front];
            arr[front] = -1;
            return ans;
        }
    }

    int frontElement() {
        if (front == rear) {
            cout << "Queue is in underflow" << endl;
            return -1;  // Return some default value in case of underflow
        } else {
            return arr[front + 1];
        }
    }

    bool isEmpty() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return true;
        } else {
            cout << "Queue is not empty" << endl;
            return false;
        }
    }
};

int main() {
    int size = 5;
    Queue q(size);

    q.elementPush(1);
    q.elementPush(2);
    q.elementPush(3);
    q.elementPush(4);
    q.elementPush(5);

    cout << "front element of queue: " << q.frontElement() << endl;

    cout << q.elementPop() << endl;
    cout << "front element of queue: " << q.frontElement() << endl;
    q.isEmpty();  // No need to print the result of isEmpty()
    
    cout << "done" << endl;
    return 0;
}
