#include <iostream>
#include <queue>
using namespace std;

class stackUsingQueue
{

public:
    queue<int> q1;
    queue<int> q2;

    void pushElement(int data)
    {

        if (q1.empty())
        {
            q1.push(data);
        }
        else
        {
            q2.push(data); 
            q2.push(q1.front());
            q1.pop();
            
        }
        
    }

    void print(queue<int> q1)
    {

        while (!q1.empty())
        {
            /* code */

            cout << q1.front() << endl;
            q1.pop();
        }
    }


    int pop(){

        if(!q1.empty()){
            while (!q1.empty())
            {
                /* code */
                int ele =  q1.front();
                q1.pop();
                return ele;
            }
            
        }
        else{
            while (!q2.empty())
            {
                /* code */
                int ele =  q2.front();
                q2.pop();
                return ele;
            }
            
        }

    }

    bool isEmpty(){

        if(q1.empty() && q2.empty()){
            
            cout<<"Stack is in underflow "<<endl;
            return true;
        }
        else{
            cout<<"Stack in not empty"<<endl;
            return false;
        }
    }
};

int main()
{
    stackUsingQueue s;
    s.pushElement(5);
    s.pushElement(10);
    s.pushElement(15);
    
    s.print(s.q1);
    cout<<"q2 "<<endl;
    s.print(s.q2);

    cout<<"afet pop "<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.isEmpty();

return 0;
}