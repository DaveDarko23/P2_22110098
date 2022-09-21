#include <iostream>
#include <stdlib.h>
#include "CDate.cpp"

std::string Controll(CDate);

int main()
{
  std::string sDate;
  char escape;

  CDate date = CDate("00/00/0000");

  do
  {
    std::cout << "Ingrese la fecha (dd/MM/yyyy): ";
    std::cin >> sDate;
    date.setDate(sDate);
    std::cout << "\n\t\t\t" << Controll(date);
    std::cout << "\n\t\t\tContinuar: ";
    std::cin >> escape;

  } while (escape != 'z');

  system("pause");
  return 0;
}

std::string Controll(CDate date)
{
  std::string message;

  switch (date.validate())
  {
  case 0:
    message = "Fecha Incorrecta";
    break;
  case 1:
    message = "Mes Incorrecto";
    break;
  case 2:
    message = "Dia Incorrecto";
    break;
  case 3:
    message = "Fecha Correcta";
    break;
  }

  return message;
}