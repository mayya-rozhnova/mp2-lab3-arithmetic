#include "list.h"

template <class Type>
list<Type>::list() {
  pFirst = 0;
}

template <class Type>
list<Type>::list(list<Type> &a) {
  pFirst = 0;
  node<Type>* b = a.pFirst;
  while (b != 0) {
    insertL(b->val);
    b = b->next;
  }
}

template <class Type>
list<Type>::~list() {
  node<Type> *b = pFirst;
  while (pFirst != 0) {
    pFirst = pFirst->next;
    delete b;
    b = pFirst;
  }
}

template <class Type>
node<Type>* list<Type>::search(Type _val) {
  if (pFirst == 0)
    throw std::exception("Empty list");
  node<Type> *tmp = pFirst;
  while ((tmp != 0) && (tmp->val != _val))
    tmp = tmp->next;
  if (tmp == 0)
    return 0;
  return tmp;
}

template <class Type>
node<Type>* list<Type>::del(Type _val) {
  if (pFirst == 0)
    throw std::exception("Empty list");
  node<Type> *tmp = pFirst;
  if (tmp->val == _val) {
    pFirst = tmp->next;
    tmp->next = 0;
    return tmp;
  }
  while ((tmp->next != 0) && (tmp->next->val != _val))
    tmp = tmp->next;
  if (tmp->next == 0)
    return 0;
  node<T> *a = tmp->next;
  tmp->next = a->next;
  a->next = 0;
  return a;
}

template <class Type>
void list<Type>::print() {
  if (pFirst == 0) {
    cout << "Empty list" << endl;
    return;
  }

  node<Type> *tmp = pFirst;
  while (tmp != 0) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

template <class Type>
void list<Type>::insertF(Type _val) {
  node<Type> *tmp = new node<Type>();
  tmp->val = _val;
  tmp->next = pFirst;
  pFirst = tmp;
}

template <class Type>
void list<Type>::insertL(Type _val) {
  node<Type> *tmp = pFirst;
  if (pFirst == 0) {
    insertF(_val);
    return;
  }
  while (tmp->next != 0)
    tmp = tmp->next;
  node<Type> *tmp1 = new node<Type>();
  tmp1->val = _val;
  tmp1->next = 0;
  tmp->next = tmp1;
}

template <class Type>
void list<Type>::insertA(Type _val, node<Type> *a) {
  if (pFirst == 0)
    throw std::exception("Empty list");
  node<Type> *point = search(_val);
  if (point == 0)
    throw std::exception("Dont find");
  a->next = point->next;
  point->next = a;
}

template <class Type>
node<Type>* list<Type>::GetFirst() {
  return pFirst;
}
