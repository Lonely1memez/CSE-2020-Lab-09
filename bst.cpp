// bst.cpp
#ifndef BST_H
#define BST_H

#include <iostream>
#include <cassert>
using namespace std;

// Template class for the Binary Search Tree
template <typename C>
class BinarySearchTree 
{
public:
    // Constructor
    BinarySearchTree() : root(nullptr) { }

    // Destructor
    ~BinarySearchTree() 
    {
        makeEmpty();
    }

    // Find the minimum element in the BST
    const C& findMin() const 
    {
        assert(!isEmpty());
        return findMin(root)->element;
    }

    // Find the maximum element in the BST
    const C& findMax() const 
    {
        assert(!isEmpty());
        return findMax(root)->element;
    }

    // Check if the tree contains a specific element
    bool contains(const C& x) const 
    {
        return contains(x, root);
    }

    // Check if the tree is empty
    bool isEmpty() const 
    {
        return root == nullptr;
    }

    // Print the BST in order
    void printBST() const 
    {
        if (isEmpty()) cout << "Empty tree" << endl;
        else printBST(root);
    }

    // Make the tree empty
    void makeEmpty() 
    {
        makeEmpty(root);
    }

    // Insert an element into the BST
    void insert(const C& x) 
    {
        insert(x, root);
    }

    // Remove an element from the BST
    void remove(const C& x) 
    {
        remove(x, root);
    }

    // Print elements in the range [k1, k2]
    void printRange(const C& k1, const C& k2) const 
    {
        printRange(k1, k2, root);
    }

private:
    // Node structure for the BST
    struct BinaryNode 
    {
        C element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const C& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt) { }
    };

    BinaryNode* root; // Root of the tree

    // Internal method to find the smallest item in a subtree
    BinaryNode* findMin(BinaryNode* t) const 
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    // Internal method to find the largest item in a subtree
    BinaryNode* findMax(BinaryNode* t) const 
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }

    // Internal method to test if an item is in a subtree
    bool contains(const C& x, BinaryNode* t) const 
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (t->element < x)
            return contains(x, t->right);
        else
            return true; // Match
    }

    // Internal method to print a subtree in order
    void printBST(BinaryNode* t) const  
    {
        if (t != nullptr) 
        {
            printBST(t->left);
            cout << t->element << "-";
            printBST(t->right);
        }
    }

    // Internal method to make a subtree empty
    void makeEmpty(BinaryNode*& t) 
    {
        if (t != nullptr) 
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    // Internal method to insert into a subtree
    void insert(const C& x, BinaryNode*& t) 
    {
        if (t == nullptr)
            t = new BinaryNode(x, nullptr, nullptr);
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);
        else
            ; // Duplicate; do nothing
    }

    // Internal method to remove from a subtree
    void remove(const C& x, BinaryNode*& t) 
    {
        if (t == nullptr)
            return; // Item not found; do nothing
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) 
        { // Two children
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else 
        {
            BinaryNode* oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    // Internal method to print elements in a range
    void printRange(const C& k1, const C& k2, BinaryNode* t) const 
    {
        if (t == nullptr)
            return;
        if (k1 < t->element)
            printRange(k1, k2, t->left);
        if (k1 <= t->element && k2 >= t->element)
            cout << t->element << "-";
        if (k2 > t->element)
            printRange(k1, k2, t->right);
    }
};

#endif