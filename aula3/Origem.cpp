#include <cstdio>

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int generateRandomNumber(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

int main()
{
	BinaryTree arvore;

  for (int i = 0; i < 100; i++)
  {
    arvore.insert(generateRandomNumber(1, 100));
  }
	

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

	arvore.generateDotFile();

	system("pause");

	return 0;
}