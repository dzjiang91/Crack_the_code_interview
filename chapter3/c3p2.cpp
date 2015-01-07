//Design a stack with function min()

#include <iostream>

using namespace std;

struct Node
{
  int data, curMin;
};

class myStack
{
  public:
    myStack(int arraySize = 900)
    {
      buf = new Node[arraySize];
      cur = -1;
      min = -1;
    }
    ~myStack()
    {
      delete[] buf;
    }
    void push(int val)
    {
      buf[++cur].data = val;
      if(min < 0) min = 0;
      else
      {
        if(buf[min].data > val) min = cur;
      }
      buf[cur].curMin = min;
    }
    void pop()
    {
      if(cur >= 0) cur--;
      if(cur < 0) {
        cout << "Stack is Empty!" << endl;
        min = -1;
        return;
      }
      min = buf[cur].curMin;
    }
    int top()
    {
      if(cur < 0) return 0;
      return buf[cur].data;
    }
    bool findMin(int &result)
    {
      bool status = true;
      if(min >= 0){
        result = buf[min].data;
      }
      else
        status = false;
      return status;
    }
  private:
    Node* buf;
    int cur;
    int min;
};

int main()
{
  bool status;
  int min;
  myStack stack;
  for(int i = -5; i < 2; i++){
    stack.push(i * i);
  }
  status = stack.findMin(min);
  if(!status) cout << "stack is empty" << endl;
  else{
    cout << "Min is " << min  <<endl;
  }
  for(int i = 0; i< 2; i++)
    stack.pop();
  status = stack.findMin(min);
  if(!status) cout << "stack is empty" << endl;
  else
  {
    cout << "Min is " << min << endl;
  }
  return 0;
}
