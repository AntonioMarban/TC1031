#include <iostream>
#include "List.h"

using namespace std;
#ifndef __TSTACK_H__
#define __TSTACK_H__

template <class T>
class TStack { 
  private:
  	List<T> *lista;
    int size;		
  public:
  	TStack() { lista = new List<T>(); size = 0; }
    virtual ~TStack() {}
    virtual bool empty();
  	virtual T *pop();
    virtual void push(T *val);
    virtual T *stacktop();
};

template <class T>
bool TStack<T>::empty() {
	return lista->isEmpty();
}

template <class T>                          
T *TStack<T>::pop(){						
	if (lista->isEmpty()) {
    cout << "\nStack Underflow" << endl;
    return NULL;
  }     
  T *elem = lista->getLast()->getInfo();				
  lista->removeAt(--size);
  cout << "\nElement popped. New Size: " << size << endl;
  return elem;
}

template <class T>
void TStack<T>::push(T *val) {
	lista->add(val);
  size++;
  cout << "\nElement pushed. New Size: " << size << endl;
  cout << "\nThis is at the top of the stack now: " << lista->getLast()->getInfo() << endl;
}

template <class T>
T *TStack<T>::stacktop() {
	if (lista->isEmpty()) {
    cout << "\nStack Underflow" << endl;
    return NULL;
  }
  return lista->getLast()->getInfo();
}

#endif