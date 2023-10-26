//
// Antonio Marbán Regalado - A01424831
// 11/10/2023
// 
//

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <sstream>
using namespace std;

// Clase de objetos tipo nodos que utiliza templates para sobreescribir el datatype que se guarda en cada nodo

template <class T>
class Node {
public:
    Node(T *info, Node<T> *sig, Node<T> *ant);
    Node(T *info);
    ~Node() {};
    virtual void setSig(Node<T> *sig);
    virtual void setAnt(Node<T> *ant);
    virtual void setInfo(T *info);
    virtual Node<T> *getSig();
    virtual Node<T> *getAnt();
    virtual T *getInfo();
private:
    Node<T> *Sig;
    Node<T> *Ant;
    T *Info;
};

template <class T>
Node<T>::Node(T *info, Node<T> *sig, Node<T> *ant):Info(info), Sig(sig), Ant(ant) {} // Recibe de parámetros un apuntador a un objeto tipo T y un apuntador a un objeto nodo tipo T (el siguiente nodo de la lista)

template <class T>
Node<T>::Node(T *info) { Sig=NULL; Ant=NULL; Info=info; } // Recibe unicamente de parametro el apuntador objeto tipo T, el otro se define por default como NULL

template <class T>
void Node<T>::setSig(Node<T> *sig){Sig=sig;}; // Setter siguiente nodo

template <class T>
void Node<T>::setAnt(Node<T> *ant){Ant=ant;}; // Setter nodo anterior

template <class T>
void Node<T>::setInfo(T *info) {Info=info; }; // Setter apuntador objeto tipo T

template <class T>
Node<T> *Node<T>::getSig(){return Sig;}; // Getter siguiente nodo

template <class T>
Node<T> *Node<T>::getAnt(){return Ant;} // Getter nodo anterior

template <class T>
T *Node<T>::getInfo(){return Info;}; // Setter apuntador objeto tipo T

#endif
