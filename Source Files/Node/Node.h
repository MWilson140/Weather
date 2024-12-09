#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
/*

how to put into BST. ask anna
make all public
make all private and friend the s

*/
template <class T>
struct Node
{
    Node & operator = (const Node & temp) //go deeper for copy,recursive?
    {
        this->Data = temp.Data;
        this->lLink = temp.lLink; //copies memory address
        this->rLink = temp.rLink; //copies memory address
        return *this;
    }
    Node(const Node & node);
    Node();
    Node(T t);
    ~Node(){}; //could not use = delete.
    T Data;
    Node* lLink;
    Node* rLink;
};
template <class T>
Node<T>::Node()
{
    lLink = nullptr;
    rLink = nullptr;

}
template <class T>
Node<T>::Node(const Node & node) //copies the memory, or copies the contents?
{
    this->Data = node.Data;
    this->lLink = node.lLink;
    this->rLink = node.rLink;
}
template <class T>
Node<T>::Node(T t)
{
    Data = t;
    lLink = nullptr;
    rLink = nullptr;
}

#endif // NODE_H_INCLUDED
