#include <iostream>
#include <queue>
#include <array>
using namespace std;

class kQueue
{

public:
    int n, k;
    int freeSpot;
    int *arr;
    int *next;
    int *front;
    int *rear;

    kQueue(int n, int k)
    {
        freeSpot = 0;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    void enQueue(int data, int qn)
    {
        // Overflow check
        if (freeSpot == -1)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        // Find index to push element
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index];

        /* Insert the element into the queue */

        // If it is the first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {                               // It's not the first element
            next[rear[qn - 1]] = index; // Link the previous qn element to the next same qn element
        }

        // Update next
        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = data;
    }

    int deQueue(int qn)
    {
        // Underflow check
        if (front[qn - 1] == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        // Find index to pop
        int index = front[qn - 1];

        // Update front
        front[qn - 1] = next[index];

        // Manage free slot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()
{
    // Example usage
    int n = 10;      // Total number of elements
    int k = 3;       // Number of queues
    kQueue kq(n, k); // Create a kQueue object with n elements and k queues

    kq.enQueue(20, 2);  
    kq.enQueue(10, 1); 
    kq.enQueue(15, 1); 
    kq.enQueue(25, 1); 

    cout<<kq.deQueue(1)<<endl;
    cout<<kq.deQueue(2)<<endl;
    cout<<kq.deQueue(1)<<endl;
    cout<<kq.deQueue(1)<<endl;
    

    return 0;
}
