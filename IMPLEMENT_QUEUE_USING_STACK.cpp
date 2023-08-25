#include<iostream>
#include<stack>
using namespace std;

class queueUsingStack {

public:

    stack<int> input;
    stack<int> output;

    void pushElement(int data) {
        input.push(data);
    }

    int pop() {
        if (output.empty() == true) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int frontElement = output.top();
        output.pop();
        return frontElement;
    }
};

int main() {
    queueUsingStack q;
    q.pushElement(5);
    q.pushElement(10);
    
    cout << q.pop() << endl; // Output: 5
    cout << q.pop() << endl; // Output: 10
    
    return 0;
}
