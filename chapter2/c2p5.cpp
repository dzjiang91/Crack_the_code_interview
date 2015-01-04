//You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

//FOLLOW UP
//Suppose the digits are stored in forward order. Repeat the above problem.

#include "LinkedList.h"
#include <iostream>

using namespace std;

void addition(Node* input1, Node* input2, Node* &result);
void reverse(Node* &head);
int main(){
  LinkedList list1;
  LinkedList list2;
  LinkedList result;
  list1.insert(7);
  list1.insert(1);
  list1.insert(6);
  list2.insert(5);
  list2.insert(9);
  list2.insert(3);
  addition(list1.head, list2.head, result.head);
  cout << "input1: ";
  list1.display();
  cout << endl;
  cout << "input2: ";
  list2.display();
  cout << endl;
  cout << "result: ";
  result.display();
  cout << endl;
  cout << endl;
  cout << "forward" << endl;
  reverse(list1.head);
  reverse(list2.head);
  addition(list1.head, list2.head, result.head);
  reverse(result.head);
  cout << "result: ";
  result.display();
  cout << endl;
  return 0;
  
}

void addition(Node* input1, Node* input2, Node* &result){
  int temp = 0;
  Node* current1 = input1;
  Node* current2 = input2;
  LinkedList list;
  while(current1 != NULL && current2 != NULL){
    list.insert((current1->data + current2->data + temp) % 10);
    temp = (current1->data + current2->data + temp)/10;
    current1 = current1->next; current2 = current2->next;
  }
  if(temp != 0) list.insert(temp);
  result = list.head;
  list.head = NULL;
}

void reverse(Node* &head){
  if(head == NULL) return;
  Node* current = head->next;
  Node* previous = head;
  Node* temp;
  while(current != NULL){
    previous->next = current->next;
    current->next = head;
    head = current;
    current =previous->next;
  }  
}
