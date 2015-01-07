//Describe how you could use a single array to implement three stacks.

#include <iostream>

using namespace std;

struct node
{
  int data, preIndex;
};

class stack3
{
  public:
    stack3(int totalSize = 1000)
    {
      buf = new node[1000];
      last[0] = last[1] = last[2] = -1;
      this->totalSize = totalSize;
      cur = 0;
    }
    ~stack3()
    {
      delete[] buf;
    }
    void push(int val, int stacknum)
    {
      if(cur >=  totalSize)
      {
        cout << "Stack is Full!" << endl;
        return;
      }
      buf[cur].data = val;
      buf[cur].preIndex = last[stacknum];
      last[stacknum] = cur;
      cur ++;
    }
    void pop(int stacknum)
    {
      if(last[stacknum] == -1)
      { 
        cout << "stack " << stacknum << " is EMPTY!" << endl;
      }
      else
      {
        last[stacknum] = buf[last[stacknum]].preIndex;
        
      }
    }
    int top(int stacknum)
    {
      return buf[last[stacknum]].data;
    }
    bool isEmpty(int stacknum)
    {
      return last[stacknum] == -1;
    }
  private:
    node* buf;
    int last[3];
    int totalSize;
    int cur;
};

int main()
{
  stack3 stack;
  for(int i = 0; i < 10; ++i)
  {
    stack.push(i, 0);
  }
  for(int i = 10; i < 20; ++i)
  {
    stack.push(i, 1);
  }
  for(int i = 100; i < 120; ++i)
  {
    stack.push(i, 2);
  }
  for(int i = 0; i < 3; ++i)
  {
    cout << stack.top(i) << endl;
  }
  for(int i = 0; i < 3; ++i)
  {
    stack.pop(i);
    cout << stack.top(i) << endl;
  }
  return 0;

}
