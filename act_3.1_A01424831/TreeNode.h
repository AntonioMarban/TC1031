#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
private:
    T *value;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;

public:
    TreeNode<T>()
    {
        leftNode = NULL;
        rightNode = NULL;
    }
    TreeNode<T>(T *pValue)
    {
        value = pValue;
        leftNode = NULL;
        rightNode = NULL;
    }
    TreeNode<T>(T *pValue, TreeNode<T> *pLeftNode, TreeNode<T> *pRightNode)
    {
        value = pValue;
        leftNode = pLeftNode;
        rightNode = pRightNode;
    }
    TreeNode<T> *getLeftNode() { return leftNode; }
    TreeNode<T> *getRightNode() { return rightNode; }
    void setLeftNode(TreeNode<T> *pLeftNode) { leftNode = pLeftNode; }
    void setRightNode(TreeNode<T> *pRightNode) { rightNode = pRightNode; }
    T *getValue() { return value; }
    void setValue(T *pValue) { value = pValue; }
};

#endif