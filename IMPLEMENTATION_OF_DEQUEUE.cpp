#include <iostream>
using namespace std;

class deQueue
{

public:
    int *arr;
    int front;
    int rear;
    int size;

    deQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool pushFront(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            return false;
        }
        else if (front == -1)
        {
            /* first element */
            rear = front = 0;
        }
        else if (front == 0)
        {
            /* to maintain the cyclic nature of the queue */
            front = size - 1;
        }
        else
        {
            /* normal flow */
            front--;
        }
        arr[front] = data;
        return true;
    }

    bool pushRear(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            return false;
        }
        else if (front == -1)
        {
            /* first element */
            rear = front = 0;
        }
        else if (rear == size - 1 && front != 0)
        {

            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
        return 1;
    }

    int popRear()
    {

        if (front == -1)
        {
            /* code */
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {

            rear--;
        }
        return ans;
    }

    int popFront()
    {
        if (front == -1)
        {
            /* code */
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (front = size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    deQueue q(5);
    cout << "done";
    return 0;
}
