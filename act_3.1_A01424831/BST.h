#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include "TreeNode.h"
#include "List.h"
#include "Queue.h"
using namespace std;

template <class T>
class BST
{
private:
    TreeNode<T> *rootNode;
    List<T> *markedNodes;
    Queue<TreeNode<T>> *queue;
    void privBFS(TreeNode<T> *node); // Breadth-First Search
    int height(TreeNode<T> *node);
    void InOrder(TreeNode<T> *node);
    void PreOrder(TreeNode<T> *node);
    void PostOrder(TreeNode<T> *node);
    int countNodes(TreeNode<T>* node);
    bool ancestors(TreeNode<T> *node, T value);
    int whatLevelAmI(TreeNode<T>* node, T value, int level);

public:
    BST<T>() { rootNode = NULL; }
    bool addValue(T *value);
    bool findValue(T *value);
    bool removeValue(T *value);
    int compareNodeValues(T *v1, T *v2);
    void display();
    int countNodes();
    void visit(int);
    void BFS();
    int height();
    void ancestors(T value);
    int whatLevelAmI(T value);
};

template <class T>
int BST<T>::compareNodeValues(T *v1, T *v2)
{
    if (*v1 == *v2)
    {
        return 0;
    }
    if (*v1 > *v2)
    {
        return 1;
    }
    else
        return -1;
}

template <class T>
bool BST<T>::addValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return false;
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    // si llego aqui se inserta
    newNode = new TreeNode<T>(value);
    if (prevNode == NULL)
        rootNode = newNode;
    else
    {
        if (compareNodeValues(value, prevNode->getValue()) == 1)
            prevNode->setRightNode(newNode);
        else
            prevNode->setLeftNode(newNode);
    }
    return true;
}

template <class T>
bool BST<T>::findValue(T *value)
{
    TreeNode<T> *newNode, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return true;
        currentNode = (compareNodeValues(value, currentNode) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
void BST<T>::display()
{
    InOrder(rootNode);
}

template <class T>
void BST<T>::InOrder(TreeNode<T> *node) // Prints our binary tree in order
{
    if (node == NULL)
        return;
    InOrder(node->getLeftNode()); // Prints the subtree corresponding to the left node
    cout << *(node->getValue()) << " "; // Prints the current node
    InOrder(node->getRightNode()); // Prints the subtree corresponding to the right node
}

template <class T>
void BST<T>::PreOrder(TreeNode<T> *node) // Prints our binary tree in order
{
    if (node == NULL)
        return;
    cout << *(node->getValue()) << " "; // Prints the current node
    PreOrder(node->getLeftNode()); // Prints the subtree corresponding to the left node
    PreOrder(node->getRightNode()); // Prints the subtree corresponding to the right node
}

template <class T>
void BST<T>::PostOrder(TreeNode<T> *node) // Prints our binary tree in order
{
    if (node == NULL)
        return;
    PostOrder(node->getLeftNode()); // Prints the subtree corresponding to the left node
    PostOrder(node->getRightNode()); // Prints the subtree corresponding to the right node
    cout << *(node->getValue()) << " "; // Prints the current node
}

template <class T>
bool BST<T>::removeValue(T *value)
{
    TreeNode<T> *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
        {   // ya lo encontramos
            // es un nodo hoja
            if (currentNode->getLeftNode() == NULL && currentNode->getRightNode() == NULL)
            {
                if (prevNode != NULL)
                { // No es el nodo raiz
                    if (currentNode == prevNode->getLeftNode())
                        prevNode->setLeftNode(NULL);
                    if (currentNode == prevNode->getRightNode())
                        prevNode->setRightNode(NULL);
                }
                else // es el nodo raiz
                    rootNode = NULL;
                delete currentNode;
                return true;
            }
            // es un nodo con dos hijos
            if (currentNode->getLeftNode() != NULL && currentNode->getRightNode() != NULL) {
                TreeNode<T> *p = currentNode->getLeftNode();
                TreeNode<T> *prevP = NULL;
                if (currentNode->getLeftNode() != NULL) {
                    prevP = currentNode; 
                    p = currentNode->getLeftNode(); 
                    while (p->getRightNode() != NULL) { 
                        prevP = p; 
                        p = p->getRightNode();
                    }
                }
                if (p->getLeftNode() != NULL) { // tiene un hijo a la izq
                    if (prevP != NULL)
                    {
                        if (p == prevP->getLeftNode())
                            prevP->setLeftNode(currentNode->getLeftNode());
                        else
                            prevP->setRightNode(currentNode->getLeftNode());
                    }
                }
                else{ // se trata de un nodo hoja
                    if (p == prevP->getLeftNode())
                        prevP->setLeftNode(NULL);
                    else
                        prevP->setRightNode(NULL);
                }
                delete p;
                return true;
            }
            else { // tiene un solo hijo
                if (prevNode != NULL)
                {
                    if (prevNode->getLeftNode() == currentNode)
                    {
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setLeftNode(currentNode->getLeftNode());
                        else
                            prevNode->setLeftNode(currentNode->getRightNode());
                    }
                    else
                    { // se encuentra a la derecha
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setRightNode(currentNode->getLeftNode());
                        else
                            prevNode->setRightNode(currentNode->getRightNode());
                    }
                }
                else { // se trata del nodo raiz
                    if (currentNode->getLeftNode() != NULL)
                        rootNode = currentNode->getLeftNode();
                    else
                        rootNode = currentNode->getRightNode();
                }
                delete currentNode;
                return true;
            }
        }
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
int BST<T>::countNodes() {
    return countNodes(rootNode); 
}

template <class T>
int BST<T>::countNodes(TreeNode<T>* node) {
    if (node == NULL) return 0; // Adds 0 if the node is empty
    return 1 + countNodes(node->getLeftNode()) + countNodes(node->getRightNode()); // Adds 1 for this node + children node's value
}

template <class T>
void BST<T>::visit(int order) {
    switch(order) {
        case 1:
            PreOrder(rootNode);
            break;
        case 2:
            InOrder(rootNode);
            break;
        case 3:
            PostOrder(rootNode);
            break;
        case 4:
            BFS();
            break;
        default:
            cout << "\nLa funcion visit() solo acepta un entero del 1 al 4 como parametro.\n";
    }
}

template <class T>
void BST<T>::privBFS(TreeNode<T> *node) {
  markedNodes->add(node->getValue());
  cout << *(node->getValue()) << " ";
  queue->enqueue(node);
  while (!queue->isEmpty()) {
  	TreeNode<T> *unqueuedNode=queue->unqueue();
    if ( unqueuedNode->getLeftNode()!=NULL && markedNodes->find(unqueuedNode->getLeftNode()->getValue())==false ) {
        markedNodes->add(unqueuedNode->getLeftNode()->getValue());
        cout << *(unqueuedNode->getLeftNode()->getValue()) << " ";
        queue->enqueue(unqueuedNode->getLeftNode());
    }
	if ( unqueuedNode->getRightNode()!=NULL && markedNodes->find(unqueuedNode->getRightNode()->getValue())==false ) {
        markedNodes->add(unqueuedNode->getRightNode()->getValue());
        cout << *(unqueuedNode->getRightNode()->getValue()) << " ";
        queue->enqueue(unqueuedNode->getRightNode());
    }
  }
}

template <class T>
void BST<T>::BFS() {
    markedNodes = new List<T>();
    queue = new Queue<TreeNode<T>> ();
    privBFS(rootNode);
}


template <class T>
int BST<T>::height() {
    return height(rootNode);
}

template <class T>
int BST<T>::height(TreeNode<T> *node) {
    if (node == NULL) {
        return 0; // Returns 0 if the tree is empty
    } else {
        int leftHeight = height(node->getLeftNode()); // 
        int rightHeight = height(node->getRightNode());
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // Returns the highest subtree's height + 1
    }
}

template <class T>
bool BST<T>::ancestors(TreeNode<T>* node, T value) {
    if (node == NULL) {
        return false;
    }
    if (*(node->getValue()) == value) {
        return true;
    }
    if (value < *(node->getValue())) {
        if (ancestors(node->getLeftNode(), value)) {
            cout << *(node->getValue()) << " "; // Print the ancestor's value.
            return true;
        }
    } else {
        if (ancestors(node->getRightNode(), value)) {
            cout << *(node->getValue()) << " "; // Print the ancestor's value.
            return true;
        }
    }
    return false;
}
template <class T>
void BST<T>::ancestors(T value) {
    if (rootNode == NULL) {
        cout << "The tree is empty." << endl;
        return;
    }
    if (!ancestors(rootNode, value)) {
        cout << "No ancestors found for the value: " << value << ". It may not be in the tree." << endl;
    }
}


template <class T>
int BST<T>::whatLevelAmI(TreeNode<T>* node, T value, int level) {
    if (node == NULL) {
        return -1;
    }
    if (*(node->getValue()) == value) {
        return level;
    } else if (value < *(node->getValue())) {
        return whatLevelAmI(node->getLeftNode(), value, level + 1);
    } else {
        return whatLevelAmI(node->getRightNode(), value, level + 1);
    }
}

template <class T>
int BST<T>::whatLevelAmI(T value) {
    // The root node is at level 0.
    return whatLevelAmI(rootNode, value, 0);
}

#endif