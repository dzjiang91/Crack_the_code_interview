//Write a stack to sort a stack in ascending order(with biggest item on top);

#include <stack>
#include <iostream>

using namespace std;

void sortStack(stack<int> &ss);

int main()
{
  stack<int> ss;
  ss.push(5);
  ss.push(25);
  ss.push(8);
  ss.push(17);
  ss.push(79);
  ss.push(180);
  ss.push(36);
  sortStack(ss);
  while(!ss.empty())
  {
    cout << ss.top() << " ";
    ss.pop();
  }
  cout << endl;
  return 0;
}

void sortStack(stack<int> &ss)
{
  stack<int> buff;
  int size = 0;
  if(ss.empty()) return;
  while(!ss.empty())
  {
    buff.push(ss.top());
    ss.pop();
    size++;
  }
  while(!buff.empty())
  {
    ss.push(buff.top());
    buff.pop();
  }
  
  for(int i = 0; i < size; i++)
  {
    int temp = ss.top();
    ss.pop();
    for(int j = i + 1; j < size; j++)
    {
      if(ss.top() < temp)
      {
        buff.push(temp);
        temp = ss.top();
        ss.pop();
      }
      else
      {
        buff.push(ss.top());
        ss.pop();
      }
    }
    ss.push(temp);
    while(!buff.empty())
    {
      ss.push(buff.top());
      buff.pop();
    }
  }
}
