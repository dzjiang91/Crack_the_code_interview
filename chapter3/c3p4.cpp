//Tower of Hanoi

#include <iostream>
#include <stack>
using namespace std;

void towerOfHanoi(stack<int> *origin, stack<int> *buff, stack<int> *dest, int n)
{
  if(n == 0) return;
  towerOfHanoi(origin, dest, buff, n - 1);
  (*dest).push((*origin).top());
  (*origin).pop();
  towerOfHanoi(buff, origin, dest, n - 1);
}

int main()
{
  stack<int> primary, buff, destination;
  int n = 10;
  for(int i = n; i > 0; i --) primary.push(i);
  towerOfHanoi(&primary, &buff, &destination, n);
  while(!destination.empty())
  {
    cout << destination.top() << "  ";
    destination.pop();
  }

}
