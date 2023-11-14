#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    List<T> *list;
public:
    Queue() { list = new List<T>(); };
    ~Queue() { delete list; };
    void enqueue(T *value) { list->add(value); };
    T * unqueue()
    {
        if (list->isEmpty())
        {
            return NULL;
        }
        T *value = list->getFirst()->getInfo();
        list->removeAt(0);
        return value;
    };
    bool isEmpty() { return list->isEmpty(); };
};

#endif