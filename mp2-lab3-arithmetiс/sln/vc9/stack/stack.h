#pragma once

#include "list.h"

template <class Type>
class stack {
  private:
    list<Type>* List;
  public:
    stack();
    stack(stack<Type> &a);
    ~stack();

    bool stack<Type>::operator == (const stack<Type>& a);
    int isFull() const;
    int isEmpty() const;
    void push(Type _val);
    Type pop();
    Type GetFirst();
    void print();
};
