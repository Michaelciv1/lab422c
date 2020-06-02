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
      IntBinaryTree() { root = nullptr; }
      ~IntBinaryTree() { destroySubTree(root); }
      void insertNode(int);
      void removeNode(int);
      bool searchNode(int);
      void BSTPrintInorder(struct TreeNode* node);
      void BSTPrintPreorder(struct TreeNode* node);
      void BSTPrintPostorder(struct TreeNode* node);
      void BSTPrintInorder();
      void BSTPrintPostorder();
      void BSTPrintPreorder();
};

#endif // INTBINARYTREE_H
