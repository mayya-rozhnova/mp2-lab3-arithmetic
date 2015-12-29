#pragma once
#include <iostream>

template <class Type>
class node {
  public:
  Type val;
  node *next;
};

template <class Type>
class list {
  protected:
    node<Type>* pFirst;
  public:
    list();
    list(list &a);
    ~list();

    node<Type>* search(Type _val);
    node<Type>* del(Type _val);
    void insertF(Type _val);
    void insertL(Type _val);
    void insertA(Type _val, node<Type>* a);
    void print();
    node<Type>* GetFirst();
};
