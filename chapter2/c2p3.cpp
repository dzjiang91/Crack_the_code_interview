//Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
//EXAMPLE
//input: the node c from the linked list a->b->c->d->e
//result: nothing is returned, but the new linked list looks like a->b->d->e

#include "LinkedList.h"
#include <iostream>

using namespace std;

void deleteNode(Node* c);

int main(){
  LinkedList list;
  list.insert(10);
  list.insert(5);
  list.insert(-2);
  list.insert(101);
  list.insert(73);
  Node* c;
  c = list.head->next->next;
  cout << "origin list:" << endl;
  list.display();
  cout << "input: " << c->data << endl;
  deleteNode(c);
  cout << "result list: " << endl;
  list.display();
  return 0;
}

void deleteNode(Node* c){
  Node* temp;
  temp = c->next;
  c->data = temp->data;
  c->next = temp->next;
  delete temp;
}
