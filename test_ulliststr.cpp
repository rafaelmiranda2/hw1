#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr* dat = new ULListStr();
  dat->push_back("1");
  dat->push_back("2");
  dat->push_back("3");
  dat->push_back("4");
  dat->push_back("5");
  dat->push_back("6");
  dat->push_back("7");
  dat->push_back("8");
  dat->push_back("9");
  dat->push_back("10");
  dat->push_back("11");
  cout << dat->front() << endl;
  cout << dat->back() << endl;
  cout << "size of list: " << dat->size() << endl; //Should show 10

  /*dat->push_back("0"); //Test push back when empty
  cout << dat->front() << endl; //Test front and back when only one thing in one list
  cout << dat->back() << endl; //Just like above, should return 0
  dat->pop_back(); //Test pop back when only one in list
  dat->push_front("0"); //Test push front when empty 
  cout << dat->get(0) << endl; //Test get
  dat->pop_front();
  
  //Tests push back and push front
  dat->push_back("9");
  dat->push_back("8");
  dat->push_back("7");
  dat->push_back("6");
  dat->push_back("5");
  dat->push_front("0");
  dat->push_front("1");
  dat->push_front("2");
  dat->push_front("3");
  dat->push_front("4");
  cout << dat->front() << endl; //Should show 4
  cout << dat->back() << endl; //Should show 5
  cout << "size of list: " << dat->size() << endl; //Should show 10

  //Tests that a new array is created when push front is called when one array is full
  dat->push_front("10");
  cout << dat->front() << endl; //Should show 10
  cout << "size of list: " << dat->size() << endl; //Should show that size of list is 11
  dat->pop_front(); //Moves head back to old head
  cout << dat->front() << endl; //Should show old front (4)

  //Tests that a new array is created when push back is called when array is full
  dat->push_back("11");
  cout << dat->back() << endl; //Should show 11
  cout << "size of list: " << dat->size() << endl; //Should show that size of list is 11
  dat->pop_back(); //Moves tail back to new tail
  cout << dat->back() << endl; //Should show old back (5) */


  delete dat;
  return 0;
}
