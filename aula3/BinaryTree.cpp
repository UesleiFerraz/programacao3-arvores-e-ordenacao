#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int value)
{
	
	root = insert(value, root);
}

void BinaryTree::preOrder()
{
	preOrder(root);
}

void BinaryTree::inOrder()
{
	inOrder(root);
}

void BinaryTree::posOrder()
{
	posOrder(root);
}

Node * BinaryTree::getByValue(int value)
{
	return getByValueAndRoot(value, root);
}

Node * BinaryTree::getLowerNode()
{
  return getLowerNode(root);
}

Node * BinaryTree::getHigherNode()
{
  return getHigherNode(root);
}

Node * BinaryTree::createNode(int value)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* BinaryTree::insert(int value, Node *root)
{
  if (root == NULL) {
    return createNode(value);
  }

  if (value < root->data)
  {
    Node* newNode = insert(value, root->left);
    root->left = newNode;
    newNode->father = root;
  }
  else if (value > root->data)
  {
    Node* newNode = insert(value, root->right);
    root->right = newNode;
    newNode->father = root;
  }

  return root;
}

void BinaryTree::preOrder(Node * root)
{
  if (root != NULL)
  {
    cout << root->data << " "; 
    preOrder(root->left);
    preOrder(root->right);
  }
}

void BinaryTree::inOrder(Node * root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

void BinaryTree::posOrder(Node * root)
{
	if (root != NULL)
  {
    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << " ";
  }
}

Node * BinaryTree::getByValueAndRoot(int value, Node * root)
{
  if (root == NULL)
  {
    return NULL;
  }
  else if (value == root->data)
  {
    return root;
  }
  else if (value > root->data)
  {
    return getByValueAndRoot(value, root->right);
  }
  else
  {
    return getByValueAndRoot(value, root->left);
  }
}

Node * BinaryTree::getLowerNode(Node * root)
{
  if (root->left == NULL)
  {
    return root;
  }else
  {
    return getLowerNode(root->left);
  }
}

Node * BinaryTree::getHigherNode(Node * root) 
{
  if (root->right == NULL)
  {
    return root;
  }
  else
  {
    return getHigherNode(root->right);
  }
}

void BinaryTree::writePreOrderInDotFile(Node * root, ofstream &arqSaida)
{
	if (root != NULL)
	{
		if (root->left)
			arqSaida << root->data << " -> " << root->left->data << ";" << endl;
		if (root->right)
			arqSaida << root->data << " -> " << root->right->data << ";" << endl;
		writePreOrderInDotFile(root->left, arqSaida);
		writePreOrderInDotFile(root->right, arqSaida);
	}

}


void BinaryTree::generateDotFile(string filename)
{
	ofstream arqSaida(filename,ios::out);
	if (arqSaida.is_open()) {
        cout << "Arquivo aberto com sucesso!\n";
        
        // Escreve no arquivo
        
		arqSaida << "digraph ArvoreBinaria {" << endl;
		arqSaida << "node [shape=circle, style=filled, color=black, fillcolor=\"#9370DB\"];" << endl;
		arqSaida << "edge [color=black];" << endl;
		writePreOrderInDotFile(root,arqSaida);

		arqSaida << "}" << endl;

        
        // Fecha o arquivo
        arqSaida.close();
		 cout << "Arquivo salvo com sucesso!\n";
    } else {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

void BinaryTree::remove(Node* root, int value)
{
  Node* nodeToRemove = getByValueAndRoot(value, root);

  if (nodeToRemove == NULL) return;
  
  if (nodeToRemove == getRoot())
  {
    root = NULL;
    delete nodeToRemove;
  }
  else if (isALeaf(nodeToRemove))
  {
    if (nodeToRemove->father->left == nodeToRemove) 
    {
      nodeToRemove->father->left = NULL;
    }
    else 
    {
      nodeToRemove->father->right = NULL;
    }
    delete nodeToRemove;
  }
  else if (hasOneChild(nodeToRemove))
  {
    bool isNodeToRemoveInLeftOfFather = nodeToRemove->father->left == nodeToRemove;
    Node* tempNode = NULL;
    if (nodeToRemove->left != NULL)
    {
      tempNode = nodeToRemove->left; 
    }
    else
    {
      tempNode = nodeToRemove->right;
    }
    
    if (isNodeToRemoveInLeftOfFather)
    {
      nodeToRemove->father->left = tempNode;
    }
    else
    {
      nodeToRemove->father->right = tempNode;
    }

    tempNode->father = nodeToRemove->father;
    delete nodeToRemove;
  }
  else 
  {
    Node* maxNodeSubTree = getHigherNode(nodeToRemove->left);
    nodeToRemove->data = maxNodeSubTree->data;
    remove(nodeToRemove->left, maxNodeSubTree->data);
  }
}

void BinaryTree::remove(int value)
{
  remove(this->root, value);
}
