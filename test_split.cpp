/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
using namespace std;
void printList(Node* List) {
  if (List == NULL) {
    return;
  }
  cout << List->value << " ";
  printList(List->next);
}

int main(int argc, char* argv[])
{
  Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, NULL)))));
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(head, odds, evens);
  
  
  cout << "Odd list: ";
  printList(odds);
  cout << endl;
    
  cout << "Evens list: ";
  printList(evens);
  cout << endl;

  while (head != NULL) {
    Node *temp = head->next;
    delete head;
    head = temp;
  }
  while (odds != NULL) {
    Node *temp = odds->next;
    delete odds;
    odds = temp;
  }
  while (evens != NULL) {
    Node *temp = evens->next;
    delete evens;
    evens = temp;
  }
  return 0;
}
