//
// Antonio Marbán Regalado - A01424831
// 11/10/2023
// 
//

#include <iostream>
#include <sstream>
using namespace std;
#include "Node.h"

// Clase lista que contiene los metodos para agregar, eliminar, buscar, reemplazar, etc. manipulando los nodos
// de la clase nodo para crear una lista ligada.

// Declaración de la lista
template <class T>
class List{
public:
    List(){first=NULL;}
    virtual ~List() {}
    virtual void add(T *value);
    virtual Node<T> *getFirst() const;
    virtual Node<T> *getLast();
    virtual void remove(T *value);
    virtual bool elementExist(T *value);
    virtual bool removeAt(int index);
    virtual void replace(int index, T *value);
    virtual bool isEmpty();
    string toString() const;
    virtual int getSize();
private:
    Node<T> *first;
};

template <class T>
void List<T>::add(T *value){ // Agrega un nuevo nodo a la lista que recibe cualquier valor (tipo T o sea culquier tipo de dato)
    Node<T> *node = new Node<T>(value);
    if (first == NULL)
    {
        first = node;
    }
    else
    {
        Node<T> *ultimateTeam=getLast();
        ultimateTeam -> setSig(node);
    }
}

template <class T>
Node<T> *List<T>::getFirst() const{ // Getter primer elemento de la lista (primer nodo)
    return first;
}

template <class T>
bool List<T>::isEmpty(){ // Devuelve true o false para saber si la lista contiene elementos (checa si el primer elemento es valido o null)
    return first==NULL;
}

template <class T>
Node<T> *List<T>::getLast() { // Getter que manda el ultimo elemento de la lista, primero checa que no este vacia y luego recorre la lista hasta que el getSig devuelva NULL, entonces sabe que es el ultimo elemento de la lista
    if (isEmpty()) return NULL;

    Node<T> *p = first;
    while (p->getSig()!=NULL){
        p = p->getSig();
    }
    return p;
}

template <class T>
void List<T>::remove(T *value){ // Quita un elemento de la lista y recibe de parametro el valor; recorre la lista hasta encontrar el nodo al que correspondan los datos indicados en el parametro (cualquiera porque es valor tipo T) y elimina ese nodo
    Node<T> *node = getFirst();
    Node<T> *previous = NULL;
    while (node != NULL) {
        if (node->getInfo() == value){
            if (previous == NULL){
                first = node->getSig();
            } else {
                previous->setSig(node->getSig());
            }
            delete node;
            return;
        }
        previous = node;
        node = node->getSig();
    }
}

template <class T>
bool List<T>::elementExist(T *value){ // Devuelve true o false para saber si existe un elemento, recibe de parametro un valor tipo T; recorre la lista hasta encontrarlo
    Node<T> *node = getFirst();
    while (node != NULL) {
        if (node->getInfo() == value){
            return true;
        }
        node = node->getSig();
    }
    return false;
}

template <class T>
bool List<T>::removeAt(int index){
    Node<T> *node = getFirst();
    Node<T> *previous = NULL;
    int contador = 0;
    while (node != NULL) {
        if (contador == index) {
            if (previous == NULL) {
                first = node->getSig();
            } else {
                previous->setSig(node->getSig());
            }
            delete node; // <-- Delete the current node, not the previous one
            return true;
        }

        contador++;
        previous = node;
        node = node->getSig();
    }
    return false;
}

template <class T>
void List<T>::replace(int index, T *value){ // Reemplaza un valor dentro de una posición indicada en parametro por un valor indicado tambien en los parametros
    Node<T> *node = getFirst();
    int contador = 0;
    while (node != NULL) {
        if (contador == index){
            node->setInfo(value);
            return;
        }
        contador ++;
        node = node->getSig();
    }
}

// Método que devuelve un valor entero del tamaño de la lista
template <class T>
int List<T>::getSize(){
    Node<T> *node = getFirst();
    int contador = 0;
    while (node != NULL) {
        contador ++;
        node = node->getSig();
    }
    return contador;
}

// Convierte la lista en un string para posteriormente poder utilizar esta funcion en la sobrecarga del operador <<
template <class T>
string List<T>::toString() const {
    Node<T> *p = getFirst();
    string outputStr="";
    while (p!=NULL)
    {
        stringstream ss;
        ss<<*(p->getInfo());
        outputStr+=ss.str()+" ";
        p=p->getSig();
    }
    return outputStr;
}
// Sobrecarga del operador << para poder imprimir la lista en un cout
template <class T>
ostream& operator<< ( ostream& outs, const List<T>* obj ) {
    return outs << obj->toString();
}