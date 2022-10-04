#include <iostream>
#include <string>

class CConvert
{

private:
  int potencia, length;

  void getPotencia(int pDecNumber)
  {
    potencia = 1;
    length = 1;
    while (pDecNumber > potencia)
    {
      potencia *= 2;
      length++;
    }

    potencia /= 2;
    length--;
  }

  std::string hexadecimal(int pHexadecimal)
  {
    switch (pHexadecimal)
    {
    case 1:
      return "1";
    case 2:
      return "2";
    case 3:
      return "3";
    case 4:
      return "4";
    case 5:
      return "5";
    case 6:
      return "6";
    case 7:
      return "7";
    case 8:
      return "8";
    case 9:
      return "9";
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
    }

    return "0";
  }

  int hexadecimalInt(int ascii)
  {
    switch (ascii)
    {
    case 48:
      return 0;
    case 49:
      return 1;
    case 50:
      return 2;
    case 51:
      return 3;
    case 52:
      return 4;
    case 53:
      return 5;
    case 54:
      return 6;
    case 55:
      return 7;
    case 56:
      return 8;
    case 57:
      return 9;
    case 65:
      return 10;
    case 66:
      return 11;
    case 67:
      return 12;
    case 68:
      return 13;
    case 69:
      return 14;
    case 70:
      return 15;
    }
  }

public:
  CConvert()
  {
  }

  std::string decToBin(int pDecNumber)
  {
    std::string mNumberConvert;

    getPotencia(pDecNumber);
    for (int i = 0; i < length; i++)
    {
      pDecNumber -= potencia;
      if (pDecNumber >= 0)
        mNumberConvert += "1";
      else
      {
        pDecNumber += potencia;
        mNumberConvert += "0";
      }
      potencia /= 2;
    }
    return mNumberConvert;
  }

  int binToDec(std::string pBinNumber)
  {
    length = pBinNumber.length();
    potencia = 1;
    int number = 0;

    for (int i = length - 1; i >= 0; i--)
    {
      if (pBinNumber[i] == '1')
        number += potencia;

      potencia *= 2;
    }

    return number;
  }

  std::string decToHex(int pNumber)
  {
    int hex = pNumber / 16;

    if (hex < 1)
      return hexadecimal(pNumber);

    return decToHex(hex) + hexadecimal(pNumber - (hex * 16));
  }

  int hexToDec(std::string hex)
  {
    int hexInt = 0, multiplicator = 1, finalHex = 0;

    for (int i = hex.length() - 1; i >= 0; i--)
    {
      hexInt = hexadecimalInt(hex[i]);

      finalHex += (multiplicator * hexInt);

      multiplicator *= 16;
    }

    return finalHex;
  }

  std::string hexToBin(std::string pNumeroHex)
  {
    int pNumeroDec = hexToDec(pNumeroHex);
    return decToBin(pNumeroDec);
  }

  std::string binToHex(std::string pNumeroBin)
  {
    int pNumeroDec = binToDec(pNumeroBin);
    return decToHex(pNumeroDec);
  }
};
