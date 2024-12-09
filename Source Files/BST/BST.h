#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "../Node/Node.h"
//TESTING git
template <class T>
class BST
{
public:
    BST();
        /**
         * @brief Equals operator
         * Provides a deep copy, copies root and all leaves of the bst
         * @post The BST and leaves are copies
         */
    BST<T> & operator = (const BST<T> & bst);
        /**
         * @brief Copy Operator
         * Provides a deep copy, copies root and all leaves of the bst
         * @param BST & bst - bst to be copied
         */
    BST(const BST & bst);
        /**
         * @brief destructor
         * Deletes all leaves and root
         * @post All leaves and roots are deleted
         */
    virtual ~BST();
        /**
         * @brief Inserting into the bst
         * @post Inserts a value into BST
         * @pre The value must not exist in the BST
         * @param T & t value to be stored
         */
    void Insert(const T & t);
        /**
         * @brief Post Order Traversal of the BST
         * @pre Must at least contain a root
         * @param void(*fp) - function pointer to call
         */
    void postorderTrav(void (*fp)(const T & data)) const;
        /**
         * @brief In Order Traversal of the BST
         * @pre Must at least contain a root
         * @param void(*fp) - function pointer to call
         */
    void inorderTrav(void (*fp)(const T & data))const;
        /**
         * @brief Pre Order Traversal of the BST
         * @pre Must at least contain a root
         * @param void(*fp) - function pointer to call
         */
    void preorderTrav(void (*fp)(const T & data)) const;

        /**
         * @brief smart Search of the BST
         * @pre Must at least contain a root
         * @param T & t varaible to find
         * @return const T * - points to the variable if found, nullptr if not
         */
    const T* smartSearch(const T & t) const;

    void deleteTree();

private:
    Node<T>* root;
        /**
         * @brief Private recursive insert
         * @pre Variable must not be inside the BST
         * @param Node parent previous node, Node child node to be inserted
         * @return bool - true if inserted, false if not
         */
    bool privInsert(Node<T>* parent, Node<T>* child);
        /**
         * @brief Recurse Pre In Traversal of the BST
         * @param Node node - current node, void(*fp) - function pointer to call
         */
    void privInorder(const Node<T>* node,void (*fp)(const T & data))const;
        /**
         * @brief Recursive Pre Order Traversal of the BST
         * @param Node node - current node, void(*fp) - function pointer to call
         */
    void privPreorderTrav(const Node<T>* node,void (*fp)(const T & data))const;
        /**
         * @brief Recursive Post Order Traversal of the BST
         * @param Node node - current node, void(*fp) - function pointer to call
         */
    void privPostorderTrav(const Node<T>* node,void (*fp)(const T & data))const;
        /**
         * @brief Recursive smart search of the BST
         * @param Node node - current node, void(*fp) - function pointer to call, T & t variable to find, T * Loc the pointer to be returned
         * @return const pointer to the data if found, nullptr if not
         */
    const T* privSmartSearch(const Node<T>* node,const T & t, const T * Loc)const;
        /**
         * @brief Recursive Deletion of the tree
         * @param Node node, the current node
         * @post all leaves and root and deleted
         */
    void privDeleteTree(Node<T>* node);
        /**
         * @brief Recursive copying of the tree
         * @param Node* CopyTo the node to copy to, Node* CopyFrom the node to copy from
         * @post Copies from one node to another.
         */
    void CopyTree(Node<T>* CopyTo, const Node<T>* CopyFrom);
};

template <class T>
BST<T> & BST<T>::operator = (const BST<T> & bst)
{
    if (bst.root == nullptr)
    {
        return *this;
    }
    if (this->root != nullptr)
    {
        deleteTree(this->root);
    }
    Node<T>* temp = new Node<T>(*bst.root);
    this->root = temp;
    CopyTree(this->root, bst.root);
    return *this;
}

template <class T>
BST<T>::BST()
{
    root = nullptr;
}
template <class T>
BST<T>::BST(const BST & bst)
{
    Node<T>* Temp;
    if (bst.root == nullptr)
    {
        this->root = nullptr;
        return;
    }
    Temp = new Node<T>(*bst.root);
    this->root = Temp;
    CopyTree(this->root, bst.root);
}
template <class T>
void BST<T>::CopyTree(Node<T>* CopyTo, const Node<T>* CopyFrom)
{
Node<T>* Temp;
    if (CopyFrom->lLink != nullptr)
    {
        Temp = new Node<T>(*CopyFrom->lLink);
        CopyTo->lLink = Temp;
        CopyTree(CopyTo->lLink, CopyFrom->lLink);
    }
    if (CopyFrom->rLink != nullptr)
    {
        Temp = new Node<T>(*CopyFrom->rLink);
        CopyTo->rLink = Temp;
        CopyTree(CopyTo->rLink, CopyFrom->rLink);
    }
}

template <class T>
void BST<T>::Insert(const T & t)
{
    Node<T> *node = new Node<T>(t);
    if (root == nullptr)
    {
        root = node;
    }
    else
        if (!privInsert(root, node))
        {
            std::cout<<"deleted" << std::endl;
            delete node;
        }
}
template <class T> //only inserts if non dupe.
bool BST<T>::privInsert(Node<T>* parent, Node<T>* child)
{
    if (child->Data == parent->Data)
        return false;

    bool inserted = true;
    if (child->Data < parent->Data)
    {
       if (parent->lLink == nullptr)
       {
           parent->lLink = child;
       }
       else
        inserted = privInsert(parent->lLink, child);
    }
    if (child->Data > parent->Data)
    {
       if (parent->rLink == nullptr)
       {
           parent->rLink = child;
       }
       else
        inserted = privInsert(parent->rLink, child);
    }
    return inserted;
}

template <class T>
void BST<T>::inorderTrav(void (*fp)(const T & data)) const
{
    if (root == nullptr)
        return;
    if (root->lLink!=nullptr)
    {
       privInorder(root->lLink, fp);
    }
    fp(root->Data);

    if (root->rLink !=nullptr)
    {
         privInorder(root->rLink, fp);
    }
}
template <class T>
void BST<T>::privInorder(const Node<T>* node, void (*fp)(const T & data)) const
{
    if (node->lLink !=nullptr )
    {
        privInorder(node->lLink, fp);
    }
    fp(node->Data);
    if (node->rLink != nullptr)
    {
        privInorder(node->rLink, fp);
    }
}

template <class T>
void BST<T>::postorderTrav(void (*fp)(const T & data)) const
{
        if (root == nullptr)
        return;
    if (root->lLink!=nullptr)
        privPostorderTrav(root->lLink, fp);
    if (root ->rLink!=nullptr)
        privPostorderTrav(root->rLink, fp);
    fp(root->Data);
}
template <class T>
void BST<T>::privPostorderTrav(const Node<T>* node,void (*fp)(const T & data))const
{
    if(node->lLink !=nullptr)
        privPostorderTrav(node->lLink, fp);
    if (node->rLink !=nullptr)
        privPostorderTrav(node->rLink, fp);
    fp(node->Data);
}

template <class T>
void BST<T>::preorderTrav(void (*fp)(const T & data)) const
{
        if (root == nullptr)
        return;
    fp(root->Data);
    if (root->lLink !=nullptr)
        privPreorderTrav(root->lLink, fp);
    if (root->rLink !=nullptr)
        privPreorderTrav(root->rLink, fp);
}
template <class T>
void BST<T>::privPreorderTrav(const Node<T>* node,void (*fp)(const T & data))const
{
    fp(node->Data);
    if (node->lLink != nullptr)
        privPreorderTrav(node->lLink, fp);
    if (node ->rLink !=nullptr)
        privPreorderTrav(node->rLink, fp);
}

template <class T>
const T* BST<T>::smartSearch(const T & t) const
{
    const T* Loc = nullptr;
    if (root == nullptr)
        return Loc;

    if (root->Data == t)
        Loc = &root->Data;
    if (Loc == nullptr)
    {
        if (t < root->Data)
        {
            if (root->lLink !=nullptr)
                Loc = privSmartSearch(root->lLink, t, Loc);
        }
        if (t > root->Data)
        {
              if (root->rLink !=nullptr)
                Loc = privSmartSearch(root->rLink, t, Loc);
        }

    }
    return Loc;
}

template <class T>
const T* BST<T>::privSmartSearch(const Node<T>* node, const T & t, const T * Loc) const
{
    if (node->Data == t)
        Loc = &node->Data;
    if (Loc == nullptr)
    {
        if (t < node->Data)
        {
            if (node->lLink !=nullptr)
            {
                Loc = privSmartSearch(node->lLink,t, Loc);
            }
        }
        if (t > node->Data)
        {
              if (node->rLink !=nullptr)
            {
                Loc = privSmartSearch(node->rLink,t, Loc);
            }
        }
    }
    return Loc;
}

template <class T>
void BST<T>::deleteTree()
{
    if (this->root != nullptr)
        privDeleteTree(this->root);
    this->root = nullptr;
}

template <class T>
void BST<T>::privDeleteTree(Node<T>* node)
{
    if (node->lLink !=nullptr)
        privDeleteTree(node->lLink);
    if (node->rLink !=nullptr)
        privDeleteTree(node->rLink);

    node->lLink = nullptr;
    node->rLink = nullptr;
    delete node;
}
template <class T>
BST<T>::~BST()
{
    deleteTree();
}

#endif // BST_H_INCLUDED
