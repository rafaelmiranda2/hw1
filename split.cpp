/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in != nullptr) {
        checkIfEven(in, odds, evens);
        split(in->next, odds, evens);
        clearInput(in);
  }
}

/* If you needed a helper function, write it here */
void checkIfEven(Node*& in, Node*& odds, Node*& evens) {
    if(in->value % 2 == 0) {
        append(evens, in);
    }
    else {
        append(odds, in);
    }
}

void append(Node*& List, Node*& in) {
    if (List == nullptr) {
        List = new Node(in->value, nullptr);
        return;
    }
    if (List->next == nullptr) {
        List->next = new Node(in->value, nullptr);
    }
    else {
        append(List->next, in);
    }
}
void clearInput(Node*& in) {
  if (in != nullptr) {
    Node* temp = in;
    in = in->next;
    delete temp;
    clearInput(in);
  }
}
