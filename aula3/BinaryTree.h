#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	int data;
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
};
