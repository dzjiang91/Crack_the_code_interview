//animal shelter
//LinkedList way or queue way

#include <iostream>
#include <queue>

#define DOG 0
#define CAT 1
using namespace std;

class Shelter
{
  public:
    Shelter()
    {
      order = 1;
    }
    ~Shelter()
    {
    }
    void enqueue(int animal)
    {
      if(animal == CAT)
      {
        cat.push(order);
      }
      else
      {
        dog.push(order);
      }
      order++;
    }
    int dequeueAny()
    {
      int result;
      if(dog.front() > cat.front())
      {
        result = cat.front();
        cat.pop();
      }
      else
      {
        result = dog.front();
        dog.pop();
      }
      return result;
    }
    int dequeueDog()
    {
      int result = dog.front();
      dog.pop();
      return result;
    }
    int dequeueCat()
    {
      int result = cat.front();
      cat.pop();
      return result;
    }
  private:
    queue<int> cat, dog;
    int order;
};

int main()
{
  Shelter shelter;
  shelter.enqueue(DOG);
  shelter.enqueue(CAT);
  shelter.enqueue(CAT);
  shelter.enqueue(DOG);
  shelter.enqueue(CAT);
  shelter.enqueue(CAT);
  cout << shelter.dequeueCat() << endl;
  cout << shelter.dequeueAny() << endl;
  cout << shelter.dequeueDog() << endl;
  return 0;
}
