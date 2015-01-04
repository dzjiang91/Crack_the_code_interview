//Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?
#include <iostream>
#include "LinkedList.h"
#include <unordered_map>
using namespace std;

//without using buffer
void removeDuplicates(Node* head);
//using buffer
void removeDuplicates2(Node* head);

int main(){
  LinkedList list;
  list.insert(10);
  list.insert(5);
  list.insert(13);
  list.insert(70);
  list.insert(38);
  list.insert(29);
  list.insert(15);
  list.insert(38);
  list.insert(5);
  list.insert(101);
  list.insert(38);
  cout << "Origin List: " << endl;
  list.display();
  cout << endl;
  removeDuplicates2(list.head);
  cout<< "Result List: " << endl;
  list.display();
  cout << endl;
  return 0;
}

void removeDuplicates(Node* head){
  Node* outer = head;
  Node* inner;
  Node* temp;
  if(outer == NULL) return;
  while(outer->next != NULL){
    inner = outer;
    while(inner->next != NULL){
      temp = inner->next;
      if(temp->data == outer->data){
        inner->next = temp->next;
        delete temp;
      }
      else
        inner = inner->next;
    }   
    outer = outer->next;
  }
}

void removeDuplicates2(Node* head){
  unordered_map<int,bool> map;
  Node* current = head;
  Node* temp;
  map[current->data] = 1;
  while(current->next != NULL){
    if(map[current->next->data] == 0){
      map[current->next->data] = 1;
      current = current->next;
    }
    else{
      temp = current->next;
      current->next = temp->next;
      delete temp;
    }    
  }

}
