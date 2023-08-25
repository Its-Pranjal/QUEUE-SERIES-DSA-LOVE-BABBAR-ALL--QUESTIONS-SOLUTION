#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseQueue(queue<int> &q, stack<int> &s) {
        if (q.empty()) {
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }
            return;
        }

        int frontElement = q.front();
        q.pop();
        s.push(frontElement);

        reverseQueue(q, s);
    }

    queue<int> rev(queue<int> q) {
        stack<int> s;
        reverseQueue(q, s);
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
