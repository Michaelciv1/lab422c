/*
  CIS 22C
    Lab3: Simulates a BST and various functions to traverse through it
  Author: Michael Wallerius
  Date: 5/31/2020
*/

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H


class IntBinaryTree
{
   private:
      struct TreeNode
      {
         int value;
         TreeNode *left;
         TreeNode *right;
      };
      TreeNode *root;

      void destroySubTree(TreeNode* node);

   public:
      IntBinaryTree() { root = nullptr; } // Sets the root node to nullptr
      ~IntBinaryTree() { destroySubTree(root); } // Deletes the BST
      void insertNode(int);
      bool searchNode(int);
      void BSTPrintInorder(struct TreeNode* node);
      void BSTPrintPreorder(struct TreeNode* node);
      void BSTPrintPostorder(struct TreeNode* node);
      void BSTPrintInorder();
      void BSTPrintPostorder();
      void BSTPrintPreorder();
};

#endif // INTBINARYTREE_H
