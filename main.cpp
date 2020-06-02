/*
  CIS 22B
    Lab3: Simulates a BST and various functions to traverse through it
  Author: Michael Wallerius
  Date: 5/31/2020
*/

#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

int main()
{
    IntBinaryTree* tree = new IntBinaryTree;
    cout << "You will enter ten different values." << endl;
    for (int x = 0; x < 10; x++){
        int value;
        cout << "Enter a value: ";
        cin >> value;
        tree->insertNode(value);
    }
    cout << "In Order: ";
    tree->BSTPrintInorder();
    cout << endl;
    cout << "Post Order: ";
    tree->BSTPrintPostorder();
    cout << endl;
    cout << "Pre Order: ";
    tree->BSTPrintPreorder();
    cout << endl;
}
