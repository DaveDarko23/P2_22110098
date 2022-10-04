#include <iostream>
#include <stdlib.h>
#include "CConvert.cpp"

int main()
{
  CConvert convert = CConvert();
  short option = 0;
  int decimal;
  std::string value;
  do
  {
    system("cls");
    std::cout << "Elija una opcion" << std::endl;
    std::cout << "[ 1 ] Decimal a Binario" << std::endl;
    std::cout << "[ 2 ] Binario a Decimal" << std::endl;
    std::cout << "[ 3 ] Decimal a Hexadecimal" << std::endl;
    std::cout << "[ 4 ] Hexadecimal a Decimal " << std::endl;
    std::cout << "[ 5 ] Binario a Hexadecimal" << std::endl;
    std::cout << "[ 6 ] Hexadecimal a Binario" << std::endl;
    std::cout << "Opcion:  ";
    std::cin >> option;

    if (option == 1 || option == 3)
    {
      std::cout << "Ingrese un numero: ";
      std::cin >> decimal;
    }
    else
    {
      std::cout << "Ingrese un valor: ";
      std::cin >> value;
    }

    switch (option)
    {
    case 1:
      std::cout << convert.decToBin(decimal) << std::endl;
      break;
    case 2:
      std::cout
          << convert.binToDec(value) << std::endl;
      break;
    case 3:
      std::cout << convert.decToHex(decimal) << std::endl;
      break;
    case 4:
      std::cout << convert.hexToDec(value) << std::endl;
      break;
    case 5:
      std::cout << convert.binToHex(value) << std::endl;
      break;
    case 6:
      std::cout << convert.hexToBin(value) << std::endl;
      break;

    default:
      break;
    }
    system("pause");

  } while (true);

  return 0;
}