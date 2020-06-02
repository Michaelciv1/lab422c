/*
  CIS 22C
    Lab3: Simulates a BST and various functions to traverse through it
  Author: Michael Wallerius
  Date: 5/31/2020
*/

#include "IntBinaryTree.h"
#include <iostream>

using namespace std;

//This function destroys subtrees using postorder traversal. There is no return.
void IntBinaryTree::destroySubTree(TreeNode* node)
{
    if (node != nullptr)
    {
        destroySubTree(node->left);
        destroySubTree(node->right);
        delete node;
    }
}

// Given a binary tree, this function inserts a given value into the BST. There is no return.
void IntBinaryTree::insertNode(int value)
{
   TreeNode *newNode = new TreeNode;
   newNode->value = value;
   newNode->left = newNode->right = nullptr;
   if (root == nullptr)
       root = newNode;  // first node
   else {
      TreeNode *current = root; // start at the root and move down
      while (current != nullptr) {
         if (newNode->value < current->value) {  // must go left
            if (current->left == nullptr) {
               current->left = newNode;
               current = nullptr;
            }
            else
               current = current->left; // move to left child
         } // end of must go left
         else { // must go right
            if (current->right == nullptr) {
               current->right = newNode;
               current = nullptr;
            }
            else
               current = current->right;  // move to right child
         }  // end of must go right
      } // end of while
   } // end of else
} // end of function

// Given a binary tree, this function searches for a given value. The return is either true or false.
bool IntBinaryTree::searchNode(int value)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == value)
         return true;
      else if (value < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// Given a binary tree, this function prints its nodes according to postorder traversal. There is no return
void IntBinaryTree::BSTPrintPostorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    BSTPrintPostorder(node->left);

    BSTPrintPostorder(node->right);

    cout << node->value << " ";
}

// Given a binary tree, this function prints its nodes according to inorder traversal. There is no return
void IntBinaryTree::BSTPrintInorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    BSTPrintInorder(node->left);

    cout << node->value << " ";

    BSTPrintInorder(node->right);
}

// Given a binary tree, this function prints its nodes according to preorder traversal. There is no return
void IntBinaryTree::BSTPrintPreorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    cout << node->value << " ";

    BSTPrintPreorder(node->left);

    BSTPrintPreorder(node->right);
}

//Passes the root node to the in order function. No return
void IntBinaryTree::BSTPrintInorder()
{
    BSTPrintInorder(root);
}

//Passes the root node to the preorder function. No return
void IntBinaryTree::BSTPrintPreorder()
{
    BSTPrintPreorder(root);
}

//Passes the root node to the in postorder function. No return
void IntBinaryTree::BSTPrintPostorder()
{
    BSTPrintPostorder(root);
}
