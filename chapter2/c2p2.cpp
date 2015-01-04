//Implement an algorithm to find the kth to last element of a singly linked list

#include "LinkedList.h"
#include <iostream>
using namespace std;

void findkToLast(Node* head, int k);

int main(){
  int k = 5;
  LinkedList list1;
  list1.insert(10);
  list1.insert(12);
  list1.insert(7);
  list1.insert(30);
  list1.insert(12);
  list1.insert(19);
  list1.insert(70);
  list1.insert(1);
  list1.insert(102);
  list1.insert(47);
  cout << "The origin singly linked list:" << endl;
  list1.display();
  cout << endl;
  //cout << "k is " << k << endl;
  findkToLast(list1.head, k);
  return 0;
}

void findkToLast(Node* head, int k){
  int count = 1;
  if(head == NULL){
    cout << "Empty List" << endl;
  }
  Node* current = head;
  LinkedList list;
  while(current->next != NULL){
    current = current->next;
    if(++count >= k){
       break;
    }
  }
  if(count != k){
     cout << "Length is less than k" << endl;
  }
  else{
     list.head = current;
     cout << "kth to last element are: " << endl;
     list.display();
     cout << endl;
  }
  list.head = NULL;
}


