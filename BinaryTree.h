/************************************************************
	Filename:      BinaryTree.h
	Author:        Mohammed Alturki
	Date Created:  4/1/2021
	Purpose:       Binary Search Tree class 
*************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Stack template
template <typename T>
class BinaryTree
{
    private:
        struct TreeNode
        {
            T value;           // The value in the node
            TreeNode *left;    // Pointer to left child node
            TreeNode *right;   // Pointer to right child node
        };

    TreeNode *root;       // Pointer to the root node
   
    // Private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void displayInOrder(TreeNode *) const;
    

    public:
        // Constructor
        BinaryTree()
        { 
            root = NULL;
        }
            
        // Destructor
        ~BinaryTree()
        { 
            destroySubTree(root); 
        }
            
        // Binary tree operations
        void insertNode(T);
        bool searchNode(T);
        
        void displayInOrder() const
        {  
            displayInOrder(root);
        }
};

//This function is called recursively
template <typename T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == NULL)
        nodePtr = newNode;                  // Insert the node.
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     // Search the left branch
    else 
        insert(nodePtr->right, newNode);    // Search the right branch
}

//insertNode creates a new node to hold item as its value, 
// and passes it to the insert function.  
template <typename T>
void BinaryTree<T>::insertNode(T item)
{
    TreeNode *newNode = NULL;	// Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = NULL;
    
    // Insert the node.
    insert(root, newNode);
    cout << "Inserting Pokemon with index " << item.getID() << " into the Pokedex\n";
}

//deleting all the nodes in the tree
//called by the destructor
template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//searchNode determines if a value is present in   
// the tree. If so, the function returns true.      
// Otherwise, it returns false. 
template <typename T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//in order traversal = LNR (Left, Node, Right)
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

#endif