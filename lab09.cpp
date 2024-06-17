// lab 09.cpp
//Antonio Mora
//6/17/2024
//Description: This program is a binary search tree that can insert, remove, and print elements in a range.
#include "bst.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
      
    BinarySearchTree<int> bst; // Declare an instance of BST for integers
    int x = 0;
    string input;

    // Prompt user to enter integers and add to BST
    cout << "Enter the elements to be added (stop when entering '0'): ";
    while (cin >> input && input != "0") 
    {
        x = stoi(input);
        bst.insert(x);
    }
      
    bst.printBST(); // Print the BST
    cout << endl;

    // Prompt user to enter integers to remove from BST
    cout << "Enter elements to be removed (stop when entering '0'): ";
    while (cin >> input && input != "0") 
    {
        x = stoi(input);
        bst.remove(x);
    }
      
    bst.printBST(); // Print the BST after removal
    cout << endl;

    // Prompt user to enter a range and print elements within the range
    int k1, k2;
    cout << "Please enter the range: ";
    cin >> k1 >> k2;
    bst.printRange(k1, k2);
    cout << endl;

    BinarySearchTree<string> bststr; // Declare an instance of BST for strings
    string s;
    // Prompt user to enter strings and add to BST
    cout << "Enter the strings to be added (stop when entering 'exit'): ";
    while (cin >> s && s != "exit") 
    {
        bststr.insert(s);
    }
      
    bststr.printBST(); // Print the BST
    cout << endl;

    return 0;
}