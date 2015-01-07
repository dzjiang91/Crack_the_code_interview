//a stack of several stacks

#include <iostream>
#include <vector>

using namespace std;

#define N 5

struct Node
{
  int data;
  int preIndex;
};

class SetOfStacks
{
  public:
    SetOfStacks(int stackSize = N)
    {
      this->stackSize = stackSize;
      buf.resize(10);
      cur.resize(10);
      buf[0] = new Node[stackSize];
      cur[0] = -1;
      stackTotalNum = 1;
      resizeFactor = 1;
    }
    ~SetOfStacks()
    {
      for(int i = 0; i < stackTotalNum; ++i)
      {
        delete[] buf[i];
      }
    }
    void push(int value)
    {
      if(cur[stackTotalNum - 1] >= stackSize - 1)
      {
        if(stackTotalNum >= resizeFactor * 10)
        {
          ++resizeFactor;
          buf.resize(resizeFactor * 10);
          cur.resize(resizeFactor * 10);
        } 
        stackTotalNum++;
        buf[stackTotalNum - 1] = new Node[stackSize];
        cur[stackTotalNum - 1] = -1;
      }
      buf[stackTotalNum - 1][++cur[stackTotalNum - 1]].data = value; 
    }
    void pop()
    {
      while(cur[stackTotalNum -1] < 0)
      {
        if(stackTotalNum == 1)
        {
          cout << "SetOfStacks is EMPTY!" << endl;
          return;
        }
        delete buf[stackTotalNum -1];
        stackTotalNum--;
      }
      cur[stackTotalNum - 1]--;
    }
    void popAt(int stackNum)
    {
      if(stackNum >= stackTotalNum)
      {
         cout << "Stack not exists!" << endl;
         return;
      }
      else if(cur[stackNum] < 0)
      {
         cout << "Stack " << stackNum << " is Empty" << endl;
         return;
      }
      cur[stackNum]--;
    }
    bool top(int &result)
    {
      bool status = true;
      while(cur[stackTotalNum - 1] < 0){
        if(stackTotalNum <= 1) return false;
        delete[] buf[stackTotalNum - 1];
        stackTotalNum--;
      }
      result = buf[stackTotalNum - 1][cur[stackTotalNum - 1]].data;
      return status;
    }
   
  private:
    vector<Node*> buf;
    vector<int> cur;
    int stackTotalNum;
    int stackSize;
    int resizeFactor;
};

int main()
{
  SetOfStacks Stacks;
  for(int i = 0; i < 10; ++i)
  {
    Stacks.push(i);
  } 
  int result;
  bool status = Stacks.top(result);
  if(!status) cout << "Top NOT available" << endl;
  else cout << result << endl;
  for(int i = 0; i < 11; ++i)
  {
    Stacks.pop();
    status = Stacks.top(result);
    if(!status) cout << "Top NOT available" << endl;
    else cout << result << endl;
  }
  return 0;
}

