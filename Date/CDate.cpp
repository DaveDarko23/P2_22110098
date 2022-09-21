#include <iostream>
#include <string>

class CDate
{
private:
  std::string date;
  std::string year, month, day;

  void separate()
  {
    std::string tempDate = date;

    day = tempDate.substr(0, 2);
    tempDate.erase(0, 3);

    month = tempDate.substr(0, 2);
    tempDate.erase(0, 3);

    year = tempDate.substr(0, 4);
  }

  short validateDay(int day, int month, bool bisiesto)
  {

    if (day <= 0)
      return false;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return (day <= 31);
    case 4:
    case 6:
    case 9:
    case 11:
      return (day <= 30);
    case 2:
      return ((day <= 28 && !bisiesto) || (day <= 29 && bisiesto));
    }
  }

  short validateMonth(int month) { return (month >= 1 && month <= 12); }

  short validateYear(int year) { return ((year % 4 == 0) && (year % 1000 == 0)); }

public:
  CDate(std::string pDate) { date = pDate; }

  void setDate(std::string pDate) { date = pDate; }

  std::string getDate() { return date; }

  short validate()
  {
    bool bisiesto;

    if (date.length() != 10)
      return 0; // Fecha Incorrecta

    separate();

    bisiesto = validateYear((int)stoi(year));

    if (!validateMonth((int)stoi(month)))
      return 1; // Mes InCorrecto

    if (!validateDay((int)stoi(day), stoi(month), bisiesto))
      return 2; // Día InCorrecto

    return 3; // Fecha Correcta
  }
};
