//Implement a MyQueue class which implements a queue using two stacks

#include <stack>
#include <iostream>

using namespace std;

class MyQueue
{
  public:
    MyQueue()
    {
    }
    ~MyQueue()
    {
    }
    void push(int value)
    {
      if(!squeue.empty()) flush(squeue, sbuff);
      sbuff.push(value);
      flush(sbuff, squeue);
    }
    void pop()
    {
      squeue.pop();
    }
    int top()
    {
      return squeue.top();
    }
  private:
    stack<int> squeue;
    stack<int> sbuff;
    void flush(stack<int> &origin, stack<int> &dest)
    {
      while(!origin.empty())
      {
        dest.push(origin.top());
        origin.pop();
      }
    }
};

int main()
{
  MyQueue myqueue;
  for(int i = 0; i < 10; i++)
  {
    myqueue.push(i);
  }
  for(int i = 0; i < 10; i++)
  {
    cout << myqueue.top() << " ";
    myqueue.pop();
  }
  cout << endl;
  return 0;
}
