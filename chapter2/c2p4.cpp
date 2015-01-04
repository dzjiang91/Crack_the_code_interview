//Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.

#include "LinkedList.h"
#include <iostream>

using namespace std;

void partition(int x, Node* &head);

int main(){
  int x = 50;
  LinkedList list;
  list.insert(71);
  list.insert(54);
  list.insert(3);
  list.insert(48);
  list.insert(101);
  list.insert(25);
  list.insert(17);
  cout << "origin: " << endl;
  list.display();
  cout << "x = " << x << endl;
  partition(x, list.head);
  cout << "result: " << endl;
  list.display();
}

//Note that head must pass by reference
void partition(int x, Node* &head){
  if(head == NULL) return;
  Node* current = head;
  Node* headNext;
  Node* temp;
  //switch the node that node->data < x to head
  while(current->next != NULL){
    if(current->next->data < x){
      temp = current->next->next;
      //headNext = current->next;
      current->next->next = head;
      head = current->next;
      current->next = temp;
    }
    else{
      current = current->next;
    }
  }
  
}
