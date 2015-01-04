//Implement a function to check if a linked list is a palindrome.

#include <iostream>
#include "LinkedList.h"

using namespace std;

//using O(n) space

bool checkPalindrome(Node* head);

void reverse(Node* &head);

int main()
{
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(5);
  list.insert(-2);
  list.insert(2);
  list.insert(1);
  cout << "Linked List is:" << endl;
  list.display();
  cout << endl;
  if(checkPalindrome(list.head))
  {
    cout << "Yeah! Palindrome! " << endl;
  }
  else
    cout << "NOT Palindrome! " << endl;
  return 0;
}

bool checkPalindrome(Node* head)
{
  bool result = true;
  LinkedList list;
  Node* temp = head;
  int len = 0;
  while(temp)
  {
    list.insert(temp->data);
    temp = temp->next;
    len++;
  }
  reverse(list.head);
  
  //compare half
  Node* temp1 = head;
  Node* temp2 = list.head; 
  for(int i = 0; i < len/2; i++)
  {
    if(temp1->data != temp2->data) 
    {
      result = false;
      break;
    }
    temp1 = temp1->next; temp2 = temp2->next;
  }
  return result;
}

void reverse(Node* &head)
{
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




