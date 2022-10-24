#include "CTree.cpp"
#include "CASK.cpp"
#include <list>

class Game
{
private:
  Tree arbol = Tree();
  Node *raiz = nullptr;
  short nivel;
  char a;

  void GameLoop(Node *pNodo)
  {
    if (pNodo->left && pNodo->right)
    {
      cout << "\n";
      cout << pNodo->value << endl;
      cout << "\nRespuesta [ n / s ]: ";
      cin >> a;

      (a == 's') ? Move(pNodo->right) : Move(pNodo->left);
    }
    else
    {
      cout << pNodo->value << endl;

      cout << "\nEs el que estabas pensando?" << endl;
      cout << "\nRespuesta [ n / s ]: ";
      cin >> a;

      if (a != 's')
        CreateNode(pNodo);

      system("cls");
    }
  }

  void Move(Node *pNodo)
  {
    nivel++;
    GameLoop(pNodo);
    nivel--;
  }

  void CreateNode(Node *pNodo)
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
    cout << "[ 1 ] Respuesta Si" << endl;
    cout << "Opcion: ";
    cin >> position;
    cout << endl;

    (position == 0)
        ? insert(pNodo, answer, pNodo->value)
        : insert(pNodo, pNodo->value, answer);

    pNodo->value = ask;
  }

  void insert(Node *pNodo, string value1, string value2)
  {
    pNodo->left = arbol.Insertar(pNodo->mID - 1, value1, pNodo->left);
    pNodo->right = arbol.Insertar(pNodo->mID + 1, value2, pNodo->right);
  }

public:
  Game() {}

  void Create()
  {

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

    std::cout
        << '\n';
  }

  void Run()
  {
    while (true)
    {
      GameLoop(raiz);
    }
  }
};