#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  if(head_ == NULL) { //base case if head is NULL
    head_ = new Item();
    head_->first = 0;
    head_->last = 0;
    tail_ = head_;
    head_->last++;
    size_ = 1;
    head_->val[head_->first] = val;
    return;
  }
  else if(tail_->last != ARRSIZE){ //case if tail isn't full
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
    return;
  }
  else if (tail_->last == ARRSIZE) { //case if tail is full, creates new Item
      Item* newTail = new Item();
      tail_->next = newTail;
      newTail->prev = tail_;
      tail_ = newTail;
      tail_->first = 0;
      tail_->last = 0;   
      tail_->val[tail_->last] = val;
      tail_->last++;
      size_++;
      return;
  }
}

void ULListStr::pop_back() {
  if (head_ == NULL) { //Returns if there's nothing to pop
    return;
  }
  else { //Pops last and returns
    tail_->last--;
    tail_->val[tail_->last] = "\0";
    size_--;
    if (tail_->val[tail_->first] == "\0") {
        if (tail_->prev == NULL) {
            delete tail_;
            tail_ = NULL;
            head_ = NULL;
        }
        else {
            tail_ = tail_->prev;
            delete tail_->next;
            tail_->next = NULL;
        }
    }
  }
}

void ULListStr::push_front(const std::string& val) {
  if(head_ == NULL) { //Base case if head is NULL
    head_ = new Item();
    tail_ = head_;
    head_->val[head_->first] = val;
    head_->last++;
    size_++;
  }
  else if(head_->val[head_->first] == "\0") { //Case if the first value is empty
      head_->val[head_->first] = val;
      head_->last++;
      size_++;
  }
  else if (head_->first != 0) { //Case if head_->first is not 0
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
  }
  else if(head_->val[head_->first] != "\0") {//Case if the first value isn't empty, creates new Item
    Item* newHead = new Item();
    head_->prev = newHead;
    newHead->next = head_;
    head_ = newHead;
    head_->first = 0;
    head_->last = 0;
    head_->last++;
    head_->val[head_->first] = val;
    size_++;
  }
}

void ULListStr::pop_front() {
    if (head_ == NULL) {
        return;
    }
    head_->first++; //Adjust size and position
    size_--;
    if (head_->first == head_->last) { //Case if it's the last item on the list
        Item* temp = head_;
        head_ = head_->next;
        if (head_ != NULL) {
          head_->prev = NULL;
        }
        else {
          tail_ = NULL;
        }
        delete temp;
    }
}
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(head_ == NULL || loc >= size_) {
    return NULL;
  }
  Item* curr = head_;
  while (curr != nullptr) {
    if (loc < (curr->last - curr->first)) {
      return &curr->val[curr->first + loc];
    }
    loc = loc - (curr->last - curr->first);
    curr = curr->next;
  }
  return NULL;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
