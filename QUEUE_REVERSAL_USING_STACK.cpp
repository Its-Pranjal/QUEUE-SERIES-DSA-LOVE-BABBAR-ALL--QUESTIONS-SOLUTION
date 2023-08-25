#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    queue<int> rev(queue<int> q) {
        stack<int> s;

        // Pop out elements from the queue and store in the stack
        while (!q.empty()) {
            int value = q.front();
            q.pop();
            s.push(value);
        }

        // Pop elements from the stack and push to the queue to reverse the order
        while (!s.empty()) {
            int value = s.top();
            s.pop();
            q.push(value);
        }

        return q;
    }
};

int main() {
    Solution solution;

    // Create a queue with elements
    queue<int> inputQueue;
    inputQueue.push(4);
    inputQueue.push(5);
    inputQueue.push(6);

    // Reverse the order of elements using the Solution class
    queue<int> outputQueue = solution.rev(inputQueue);

    // Print the reversed queue
    while (!outputQueue.empty()) {
        cout << outputQueue.front() << " ";
        outputQueue.pop();
    }
    cout << endl;

    return 0;
}
