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
  int i = 0;
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

  void Mostrar(Node *pNodo)
  {
    if (pNodo == NULL)
      return;

    cout << pNodo->Nivel << "| ";
    for (int n = 0; n < i; n++)
    {
      cout << "    ";
    }
    cout << pNodo->mID << endl;

    if (pNodo->left != NULL)
    {
      i++;
      Mostrar(pNodo->left);
      i--;
    }

    if (pNodo->right != NULL)
    {
      i++;
      Mostrar(pNodo->right);
      i--;
    }
  }

  void Game(Node *pNodo)
  {
    if (pNodo == NULL)
      return;

    if ((pNodo->left != NULL) && (pNodo->right != NULL))
    {
      cout << pNodo->value << endl;
      cin >> filter;

      if (filter == 1)
      {
        i++;
        Game(pNodo->right);
        i--;
      }
      else
      {
        i++;
        Game(pNodo->left);
        i--;
      }
    }
    else
    {
      cout << pNodo->value << endl;

      char a;
      cout << "Es el que estabas pensando?";
      cin >> a;

      if (a != 's')
      {
        string ask, answer;
        short position;

        cout << "Ingrese la pregunta: ";
        cin.ignore();
        getline(std::cin, ask);
        cout << endl;
        cout << "Ingrese el personaje: ";
        getline(cin, answer);

        cout << endl;
        cout << "[ 0 ] Respuesta No" << endl;
        cout << "[ 1 ]Respuesta Si" << endl;
        cout << "Opcion: ";
        cin >> position;
        cout << endl;

        if (position == 0)
        {
          pNodo->left = Insertar(pNodo->mID - 1, answer, pNodo->left);
          pNodo->right = Insertar(pNodo->mID + 1, pNodo->value, pNodo->right);
        }
        else
        {
          pNodo->left = Insertar(pNodo->mID - 1, pNodo->value, pNodo->left);
          pNodo->right = Insertar(pNodo->mID + 1, answer, pNodo->right);
        }

        pNodo->value = ask;
      }
    }
  }

private:
  short filter;
};