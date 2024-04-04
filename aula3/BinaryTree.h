#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	int data, height;
	Node *left, *right, *father;
};


class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int value);
	void preOrder();
	void inOrder();
	void posOrder();
	void remove(int value);

	Node* getByValue(int value);
	Node* getRoot() { return root; }
	Node* createNode(int value);
  Node* getLowerNode();
  Node* getHigherNode();

	void generateDotFile(string filename = "arvoreBinGerado.dot");
	void writePreOrderInDotFile(Node * root, ofstream &arqSaida);

protected:
	Node *root;

	Node* insert(int value, Node *root);
	void preOrder(Node *root);
	void inOrder(Node *root);
	void posOrder(Node *root);
	Node* getByValueAndRoot(int value, Node *root);
	Node* getLowerNode(Node *root);
  Node* getHigherNode(Node* root);
  void remove(Node* root, int value);
  bool isALeaf(Node* root)
  {
    return root->right == NULL && root->left == NULL;
  }
  bool hasOneChild (Node* root)
  {
    return ((root->right == NULL && root->left != NULL) || (root->left == NULL && root->right != NULL));
  }

  
private: 
  int balanceFactor(Node* root)
  {
    int leftHeight = root->left == NULL ? 0 : root->left->height;
    int rightHeight = root->right == NULL ? 0 : root->right->height;

    return leftHeight - rightHeight;
  }
  bool isBalanced(Node* root)
  {
    return balanceFactor(root) >= -1 && balanceFactor(root) <= 1;
  }
  bool hasAnyChild(Node* root)
  {
    return root->left != NULL || root->right != NULL;
  }
  bool hasBothChildren(Node* root)
  {
    return root->left != NULL && root->right != NULL;
  }

  void updateHeight(Node* root)
  {
    if (!hasAnyChild(root))
    {
      root->height = 0;
    }
    else
    {
      int leftHeight = root->left == NULL ? 0 : root->left->height;
      int rightHeight = root->right == NULL ? 0 : root->right->height;
      root->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
  }

  Node* simpleRotation(Node* root)
  {
    Node* tempRoot = NULL;
    Node* originalParent = root->father;

    if (balanceFactor(root) > 0)
    {
      tempRoot = root->left;
      root->left = tempRoot->right;
      if (root->left != NULL) root->left->father = root;
      tempRoot->right = root;
    }
    else
    {
      tempRoot = root->right;
      root->right = tempRoot->left;
      if (root->right != NULL) root->right->father = root;
      tempRoot->left = root;
    }

    root->father = tempRoot;
    tempRoot->father = originalParent;

    updateHeight(root);
    updateHeight(tempRoot);

    return tempRoot;
  }

  Node* doubleRotation(Node* root)
  {
    if (balanceFactor(root) > 0)
    {
      simpleRotation(root->left);
      return simpleRotation(root);
    }
    else
    {
      simpleRotation(root->right);
      return simpleRotation(root);
    }
  }

  Node* balance(Node* root)
  {
    if (!isBalanced(root))
    {
      if (balanceFactor(root) > 0)
      {
        if (balanceFactor(root->left) < 0)
        {
          return doubleRotation(root);
        }
        else
        {
          return simpleRotation(root);
        }
      }
      else
      {
        if (balanceFactor(root->right) > 0)
        {
          return doubleRotation(root);
        }
        else
        {
          return simpleRotation(root);
        }
      }
    }
  }
};
