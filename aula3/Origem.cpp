#include <cstdio>

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree arvore;
	
	arvore.insert(2);
	arvore.insert(4);
	arvore.insert(6);
	arvore.insert(8);
  arvore.insert(10);
  arvore.insert(12);
  arvore.insert(14);
  arvore.insert(16);
	arvore.insert(18);
  arvore.insert(20);

	cout << "Caminhamento pre-ordem: ";
	arvore.preOrder();
	cout << "\n--------------------------\n";

  cout << "menor value: " << arvore.getLowerNode()->data << "\n";

	cout << "Caminhamento central: ";
	arvore.inOrder();
	cout << "\n--------------------------\n";

	cout << "Caminhamento pos-ordem: ";
	arvore.posOrder();
	cout << "\n--------------------------\n";

	// arvore.remove(6);
  // arvore.remove(4);
  // arvore.remove(2);
  arvore.remove(8);

	arvore.generateDotFile();

	system("pause");

	return 0;
}