#include <iostream>
#include <stdlib.h>
#include "CTree.cpp"
#include "CASK.cpp"
#include <list>
using namespace std;

int main()
{
  Tree arbol = Tree();
  Node *raiz = nullptr;
  int dato, Altura;

  list<CAsk> a;
  //  a.push_back(ask1);
  a.push_back(CAsk(50, "Fue Villano?"));
  a.push_back(CAsk(42, "Tiene Sangre Saiyajin?"));
  a.push_back(CAsk(36, "Es calvo?"));
  a.push_back(CAsk(32, "Es Mujer?"));
  a.push_back(CAsk(31, "Tu Personaje es Yamcha"));
  a.push_back(CAsk(34, "Es Cientifica?"));
  a.push_back(CAsk(33, "Tu Personaje es Milk"));
  a.push_back(CAsk(35, "Tu Personaje es Bulma"));
  a.push_back(CAsk(40, "Es Maestro?"));
  a.push_back(CAsk(38, "Tiene 3 ojos?"));
  a.push_back(CAsk(37, "Tu Personaje es Krillin"));
  a.push_back(CAsk(39, "Tu Personaje es Ten Shin Han"));
  a.push_back(CAsk(41, "Tu Personaje es Roshi"));
  a.push_back(CAsk(48, "Es Saiyajin puro?"));
  a.push_back(CAsk(44, "Tiene un hermano?"));
  a.push_back(CAsk(43, "Tu Personaje es Trunks"));
  a.push_back(CAsk(46, "Es el hermano mayor?"));
  a.push_back(CAsk(45, "Tu Personaje es Goten"));
  a.push_back(CAsk(47, "Tu Personaje es Gohan"));
  a.push_back(CAsk(49, "Tu Personaje es Goku"));
  a.push_back(CAsk(60, "Fue Creado?"));
  a.push_back(CAsk(54, "Es saiyajin?"));
  a.push_back(CAsk(52, "Es verde?"));
  a.push_back(CAsk(51, "Tu Personaje es Frezzer?"));
  a.push_back(CAsk(53, "Tu Personaje es Picoro"));
  a.push_back(CAsk(56, "Tiene cabello?"));
  a.push_back(CAsk(55, "Tu Personaje es Napa"));
  a.push_back(CAsk(58, "Es un principe saijayin?"));
  a.push_back(CAsk(57, "Tu Personaje es Raditz"));
  a.push_back(CAsk(59, "Tu Personaje es Vegeta"));
  a.push_back(CAsk(62, "Es verde?"));
  a.push_back(CAsk(61, "Tu Personaje es Majin Buu"));
  a.push_back(CAsk(63, "Tu Personaje es Cell"));

  for (CAsk &as : a)
  {
    if (raiz == nullptr)
      raiz = arbol.Insertar(as.key, as.value, raiz);
    else
      arbol.Insertar(as.key, as.value, raiz);
  }

  /*raiz = arbol.cNode(60, "Es Heroe", raiz);

  // Izquierda
  arbol.iNode(50, "Utiliza el miedo?", raiz);

  // Derecha
  arbol.iNode(89, "Utiliza el miedo?", raiz);

  // Derecha Izquierda
  arbol.iNode(75, "Utiliza el miedo?", raiz);

  // Derecha Izquierda Derecha
  arbol.iNode(80, "Utiliza el miedo?", raiz);*/

  while (true)
  {
    system("cls");
    arbol.Mostrar(raiz);
    cout << endl;
    arbol.Game(raiz);
  }

  std::cout
      << '\n';

  system("pause");
  return 0;
}

//