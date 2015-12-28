#include "stack.h"
#include "list.h"
#include "list.cpp"


template <class Type>
stack<Type>::stack() {
  List = new list<Type>();
}

template <class Type>
stack<Type>::stack(stack<Type> &a) {
  this->List = new list<Type>(*(a.List));
}

template <class Type>
stack<Type>::~stack() {
  delete this->List;
}

template <class Type>
int stack<Type>::isEmpty() const {
  return (List->GetFirst() == 0);
}

template <class Type>
int stack<Type>::isFull() const {
  node<Type> *tmp;
  try {
    tmp = new node<Type>;
  }
  catch (...) {
    return 1;
  }
  delete tmp;
  return 0;
}

template <class Type>
void stack<Type>::push(Type _val) {
  if (isFull())
    throw std::exception("Full stack");
  List->insertF(_val);
}

template <class Type>
Type stack<Type>::pop() {
  if (isEmpty())
    throw std::exception("Empty stack");
  Type result = List->GetFirst()->val;
  node<Type> *f = List->del(result);
  delete f;
  return result;
}

template <class Type>
bool stack<Type>::operator == (const stack<Type> &a) {
  if (List->GetFirst() == 0 && a.List->GetFirst() == 0)
    return true;
  if (List->GetFirst() == 0 || a.List->GetFirst() == 0)
    return false;
  node<Type> *f1 = List->GetFirst();
  node<Type> *f2 = a.List->GetFirst();
  while (f1->next != 0) {
    if (f1->val != f2->val)
      return false;
    f1 = f1->next;
    f2 = f2->next;
  }
  return true;
}

template <class Type>
void stack<Type>::print() {
  List->print();
}

template <class Type>
Type stack<Type>::GetFirst() {
  if (isEmpty()) 
    throw std::exception("Empty stack");
  return List->GetFirst()->val;
}
