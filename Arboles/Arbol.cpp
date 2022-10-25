#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo
{
  int Dato;
  Nodo *Izq;
  Nodo *Der;
  int Nivel;
};

Nodo *Insertar(int, Nodo *);
void Mostrar(Nodo *);
Nodo *BuscarNodoMinimo(Nodo *);
Nodo *BuscarNodoMaximo(Nodo *);
Nodo *BuscarPadre(int, Nodo *, Nodo *);
Nodo *Eliminar(int, Nodo *, Nodo *);
void PreOrder(Nodo *);
void InOrder(Nodo *);
void PosOrder(Nodo *);
int AlturaNivel(int, int, Nodo *);
int LCI(int, int, Nodo *);
void BuscarNodo(int, Nodo *);
Nodo *EliminarRaiz(Nodo *);

int i = 0;

int main()
{
  Nodo *raiz = NULL;
  int r = 1, opcion = 0, dato = 0;
  int Altura = 0;
  int vLCI = 0, SLCI = 0;
  do
  {
    cout << "\n-------------------------------  Arbol Binario  ---------------------------\n";
    cout << "\n\t\t[ 1 ] Insertar" << endl;
    cout << "\n\t\t[ 2 ] Mostrar Order" << endl;
    cout << "\n\t\t[ 3 ] Eliminar" << endl;
    cout << "\n\t\t[ 4 ] LCI" << endl;
    cout << "\n\t\t[ 5 ] MLCI" << endl;
    cout << "\n\t\t[ 6 ] Buscar Nodo" << endl;
    cout << "\n\t\t[ 7 ] Salir" << endl;
    cout << "\n\n\t\tOpcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      cout << "\n\t\tDigite un Dato: ";
      cin >> dato;
      if (raiz == NULL)
        raiz = Insertar(dato, raiz);
      else
        Insertar(dato, raiz);
      Altura = AlturaNivel(1, 1, raiz);
      system("cls");
      cout << "\nAltura: " << Altura << endl
           << endl;
      Mostrar(raiz);
      break;
    case 2:
      system("cls");
      cout << "\nAltura: " << Altura << endl
           << endl;
      Mostrar(raiz);
      cout << "\nPreOrder: ";
      PreOrder(raiz);
      cout << "\nInOrder: ";
      InOrder(raiz);
      cout << "\nPosOrder: ";
      PosOrder(raiz);
      cout << endl;
      break;
    case 3:
      if (raiz != NULL)
      {
        cout << "\n\t\tDigite un Dato: ";
        cin >> dato;
        if (dato == raiz->Dato)
          raiz = Eliminar(dato, raiz, raiz);
        else
          Eliminar(dato, raiz, raiz);

        Altura = AlturaNivel(1, 1, raiz);
        system("cls");
        cout << "\nAltura: " << Altura << endl
             << endl;
        if (raiz != NULL)
          Mostrar(raiz);
        else
          cout << "\n\nArbol Vacio";
      }
      else
        cout << "\n\nArbol Vacio";
      break;
    case 4:
      system("cls");
      cout << "\nAltura: " << Altura << endl
           << endl;
      Mostrar(raiz);
      for (int n = 0; n < Altura; n++)
      {
        vLCI = LCI(n + 1, 0, raiz);
        cout << n + 1 << " * " << vLCI << " + ";
        SLCI += (n + 1) * vLCI;
      }
      cout << "\nLCI: " << SLCI << endl;
      break;
    case 5:
      system("cls");
      cout << "\nAltura: " << Altura << endl
           << endl;
      Mostrar(raiz);
      for (int n = 0; n < Altura; n++)
      {
        vLCI = LCI(n + 1, 0, raiz);
        SLCI += (n + 1) * vLCI;
      }
      cout << "\n\nMLCI:" << endl;
      for (int n = 0; n < Altura; n++)
      {
        vLCI = LCI(n + 1, 0, raiz);
        cout << "Nivel " << n + 1 << ": " << SLCI / (vLCI) << endl;
      }
      break;
    case 6:
      system("cls");
      cout << "\nAltura: " << Altura << endl
           << endl;
      Mostrar(raiz);
      cout << "\n\nDigite un Dato: ";
      cin >> dato;
      BuscarNodo(dato, raiz);
      break;
    case 7:
      r = 0;
      break;
    default:
      system("cls");
      cout << "\n\n\t\tOpcion No Valida" << endl;
    }

    SLCI = 0;
    vLCI = 0;
  } while (r == 1);
  system("pause");
  return 0;
}

Nodo *Insertar(int pDato, Nodo *pNodo)
{
  if (pNodo == NULL)
  {
    Nodo *Temp = new Nodo();
    Temp->Dato = pDato;
    Temp->Izq = NULL;
    Temp->Der = NULL;
    return Temp;
  }

  if (pNodo->Dato > pDato)
    pNodo->Izq = Insertar(pDato, pNodo->Izq);
  if (pNodo->Dato < pDato)
    pNodo->Der = Insertar(pDato, pNodo->Der);

  return pNodo;
}

void Mostrar(Nodo *pNodo)
{
  if (pNodo == NULL)
    return;

  cout << pNodo->Nivel << "| ";
  for (int n = 0; n < i; n++)
  {
    cout << "    ";
  }
  cout << pNodo->Dato << endl;

  if (pNodo->Izq != NULL)
  {
    i++;
    Mostrar(pNodo->Izq);
    i--;
  }

  if (pNodo->Der != NULL)
  {
    i++;
    Mostrar(pNodo->Der);
    i--;
  }
}

Nodo *BuscarNodoMinimo(Nodo *pNodo)
{
  if (pNodo == NULL)
    return NULL;

  if (pNodo->Izq == NULL)
    return pNodo;

  return BuscarNodoMinimo(pNodo->Izq);
}

Nodo *BuscarNodoMaximo(Nodo *pNodo)
{
  if (pNodo == NULL)
    return NULL;

  if (pNodo->Der == NULL)
    return pNodo;

  return BuscarNodoMaximo(pNodo->Der);
}

Nodo *BuscarPadre(int pDato, Nodo *pNodo, Nodo *Temp)
{
  if (pNodo == NULL)
    return NULL;

  if (pDato == pNodo->Izq->Dato)
    return pNodo;

  if (pDato == pNodo->Der->Dato)
    return pNodo;

  if (pDato < pNodo->Dato)
    Temp = BuscarPadre(pDato, pNodo->Izq, Temp);

  if (pDato > pNodo->Dato)
    Temp = BuscarPadre(pDato, pNodo->Der, Temp);

  return Temp;
}

int AlturaNivel(int pAltura, int pNivel, Nodo *pNodo)
{

  if (pNodo == NULL)
    return 0;

  pNodo->Nivel = pNivel;

  if (pAltura < pNivel)
    pAltura = pNivel;

  if (pNodo->Izq != NULL)
  {
    pNivel++;
    pAltura = AlturaNivel(pAltura, pNivel, pNodo->Izq);
    pNivel--;
  }

  if (pNodo->Der != NULL)
  {
    pNivel++;
    pAltura = AlturaNivel(pAltura, pNivel, pNodo->Der);
    pNivel--;
  }

  return pAltura;
}

Nodo *Eliminar(int pDato, Nodo *pNodo, Nodo *Buscador)
{
  if (pNodo == NULL)
    return NULL;

  if (pDato < pNodo->Dato)
    pNodo->Izq = Eliminar(pDato, pNodo->Izq, Buscador);
  if (pDato > pNodo->Dato)
    pNodo->Der = Eliminar(pDato, pNodo->Der, Buscador);

  if (pDato == pNodo->Dato)
  {
    if ((pNodo->Izq == NULL) && (pNodo->Der == NULL))
    {
      return NULL;
    }

    if (pNodo->Izq == NULL)
    {
      Nodo *Temp = pNodo->Der;
      pNodo = NULL;
      return Temp;
    }
    if (pNodo->Der == NULL)
    {
      Nodo *Temp = pNodo->Izq;
      pNodo = NULL;
      return Temp;
    }
    if (pNodo->Izq != NULL && pNodo->Der != NULL)
    {
      Nodo *Minimo = BuscarNodoMinimo(pNodo->Der);
      Nodo *Padre = BuscarPadre(Minimo->Dato, Buscador, NULL);

      if (Minimo->Der != NULL && pNodo != Padre)
      {
        Padre->Izq = Minimo->Der;
        Minimo->Der = pNodo->Der;
      }
      else if (pNodo != Padre)
      {
        Padre->Izq = NULL;
        Minimo->Der = pNodo->Der;
      }
      Minimo->Izq = pNodo->Izq;
      pNodo = NULL;
      return Minimo;
    }
  }
  return pNodo;
}

void PreOrder(Nodo *pNodo)
{
  if (pNodo == NULL)
    return;

  cout << pNodo->Dato << ", ";

  if (pNodo->Izq != NULL)
  {
    i++;
    PreOrder(pNodo->Izq);
    i--;
  }

  if (pNodo->Der != NULL)
  {
    i++;
    PreOrder(pNodo->Der);
    i--;
  }
}

void InOrder(Nodo *pNodo)
{
  if (pNodo == NULL)
    return;

  if (pNodo->Izq != NULL)
  {
    i++;
    InOrder(pNodo->Izq);
    i--;
  }

  cout << pNodo->Dato << ", ";

  if (pNodo->Der != NULL)
  {
    i++;
    InOrder(pNodo->Der);
    i--;
  }
}

void PosOrder(Nodo *pNodo)
{
  if (pNodo == NULL)
    return;

  if (pNodo->Izq != NULL)
  {
    i++;
    PosOrder(pNodo->Izq);
    i--;
  }

  if (pNodo->Der != NULL)
  {
    i++;
    PosOrder(pNodo->Der);
    i--;
  }

  cout << pNodo->Dato << ", ";
}

int LCI(int pDato, int vLCI, Nodo *pNodo)
{
  if (pDato == pNodo->Nivel)
  {
    vLCI++;
    return vLCI;
  }

  if (pNodo->Nivel < pDato)
  {
    if (pNodo->Izq != NULL)
      vLCI = LCI(pDato, vLCI, pNodo->Izq);
    if (pNodo->Der != NULL)
      vLCI = LCI(pDato, vLCI, pNodo->Der);
  }

  return vLCI;
}

void BuscarNodo(int pDato, Nodo *pNodo)
{
  if (pNodo == NULL)
    return;

  if (pNodo->Dato > pDato)
    BuscarNodo(pDato, pNodo->Izq);
  if (pNodo->Dato < pDato)
    BuscarNodo(pDato, pNodo->Der);

  if (pNodo->Dato == pDato)
  {
    cout << "\n\nDato: " << pNodo->Dato;
    cout << "\n\nNivel: " << pNodo->Nivel;
    cout << "\n\nGrado: ";
    if (pNodo->Izq != NULL)
    {
      if (pNodo->Der != NULL)
        cout << "2" << endl
             << endl;
      else
        cout << "1" << endl
             << endl;
      return;
    }
    if (pNodo->Der != NULL)
    {
      cout << "1" << endl
           << endl;
      return;
    }
    cout << "0" << endl
         << endl;
    return;
  }
}