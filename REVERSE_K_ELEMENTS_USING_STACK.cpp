// #include<iostream>
// #include<stack>
// #include<queue>
// using namespace std;

// queue<int> modifyQueue(queue<int> q , int K){

//     stack<int> s;

// /* Here we pop  the k-size of element from the queue & store to the stack. */
//     for (int i = 0; i < K; i++)
//     {
//         /* code */
//         int value = q.front();
//         q.pop();
//         s.push(value);
//     }

//     /* Now we pop the elements from the stack & store the que so we get the k size elements in reverse oreder.*/

//     while (!s.empty())
//     {
//         /* code */
//         int value = s.top();
//         s.pop();
//         q.push(value);
//     }
    
//     int t = q.size() - K; // here we get the remaining element except K element which need to add to last position.

//     while (t--)
//     {
//         /* code */
//         int value = q.front();
//         q.pop();
//         q.push(value);
//     }
    
//     return q;
// }
// int main()
// {
//      return 0;
// }

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    // Pop the first K elements from the queue and store them in the stack
    for (int i = 0; i < k; i++) {
        int value = q.front();
        q.pop();
        s.push(value);
    }

    // Reverse the first K elements by popping from the stack and pushing back to the queue
    while (!s.empty()) {
        int value = s.top();
        s.pop();
        q.push(value);
    }

    // Get the remaining elements count (size - K)
    int remaining = q.size() - k;

    // Rotate the remaining elements to the end of the queue
    while (remaining--) {
        int value = q.front();
        q.pop();
        q.push(value);
    }

    return q;
}
