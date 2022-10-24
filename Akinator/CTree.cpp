#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include "CNode.cpp"

using namespace std;

class Tree
{
public:
  Tree() {}
  ~Tree() {}

  Node *Insertar(int pDato, string pValue, Node *pNodo)
  {
    if (pNodo == NULL)
    {
      Node *Temp = new Node();
      Temp->mID = pDato;
      Temp->value = pValue;
      Temp->left = NULL;
      Temp->right = NULL;
      return Temp;
    }

    if (pNodo->mID > pDato)
      pNodo->left = Insertar(pDato, pValue, pNodo->left);
    if (pNodo->mID < pDato)
      pNodo->right = Insertar(pDato, pValue, pNodo->right);

    return pNodo;
  }
};