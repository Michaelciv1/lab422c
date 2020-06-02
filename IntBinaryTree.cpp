#include "IntBinaryTree.h"
#include <iostream>

using namespace std;

void IntBinaryTree::destroySubTree(TreeNode* node)
{
    if (node != nullptr)
    {
        destroySubTree(node->left);
        destroySubTree(node->right);
        delete node;
    }
}

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

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void IntBinaryTree::BSTPrintPostorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    BSTPrintPostorder(node->left);

    BSTPrintPostorder(node->right);

    cout << node->value << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void IntBinaryTree::BSTPrintInorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    BSTPrintInorder(node->left);

    cout << node->value << " ";

    BSTPrintInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void IntBinaryTree::BSTPrintPreorder(struct TreeNode* node)
{
    if (node == nullptr)
        return;

    cout << node->value << " ";

    BSTPrintPreorder(node->left);

    BSTPrintPreorder(node->right);
}

void IntBinaryTree::BSTPrintInorder()
{
    BSTPrintInorder(root);
}

void IntBinaryTree::BSTPrintPreorder()
{
    BSTPrintPreorder(root);
}

void IntBinaryTree::BSTPrintPostorder()
{
    BSTPrintPostorder(root);
}
