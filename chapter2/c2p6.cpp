//Given a circular linked list, implement an algorithm which returns the node at the beginning of the loop.

#include <iostream>
#include "LinkedList.h"
#include <unordered_map>

using namespace std;

Node* findLoop(Node* head);

int main(){
  LinkedList list;
  list.insert(11);
  list.insert(84);
  list.insert(73);
  list.insert(5);
  list.insert(15);
  list.insert(101); 
  list.createCycle();

  Node* result = findLoop(list.head);
  if(result == NULL){
    cout << "No Loop or Null List" << endl;
    return 0;
  }
  cout << "The begin of the loop is: " << result->data << endl;
  list.endCycle();
  return 0;
}

Node* findLoop(Node* head){
  if(head == NULL) return NULL;
  unordered_map<long int, bool> map;
  Node* current = head;
  while(current){
    if(map[(long int) current] == 0 ){
       map[(long int) current] = 1;
       current = current->next;
    }
    else{
      return current;
    }
  }
  return NULL;
}

