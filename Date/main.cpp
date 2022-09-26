#include <iostream>
#include <stdlib.h>
#include "CDate.cpp"

int main()
{
  std::string sDate;
  char escape;

  CDate date = CDate("00/00/0000");

  do
  {
    system("cls");
    std::cout << "\n\t\t\tIngrese la fecha (dd/MM/yyyy): ";
    std::cin >> sDate;
    if (date.setDate(sDate))
    {
      date.setDate(sDate);
      if (date.validate())
      {
        std::cout << "\n\t\t\tFecha Correcta" << std::endl;
        std::cout << "\n\t\t\t" << date;
        for (int i = 0; i < 1000; i++)
        {
          ++date;
          std::cout << "\n\t\t\t" << date;
        }
      }
      else
        std::cout << "Fecha Incorrecta" << std::endl;
    }
    else
      std::cout << "Fecha Incorrecta" << std::endl;

    std::cout << "\n\t\t\tPresione E para salir: ";
    std::cin >> escape;

  } while (escape != 'E' || escape == 'e');

  system("pause");
  return 0;
}