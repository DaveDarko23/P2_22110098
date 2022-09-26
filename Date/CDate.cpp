#include <iostream>
#include <string>

class CDate
{
private:
  std::string date;
  bool bisiesto;

  void separate()
  {
    std::string tempDate = date;

    day = stoi(tempDate.substr(0, 2));
    tempDate.erase(0, 3);

    month = stoi(tempDate.substr(0, 2));
    tempDate.erase(0, 3);

    year = stoi(tempDate.substr(0, 4));
  }

  bool validateDay()
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

    return true;
  }

  short validateMonth() { return (month >= 1 && month <= 12); }

  short validateYear() { return ((year % 4 == 0) && (year % 100 != 0)); }

public:
  int day, month, year;

  CDate(std::string pDate) { date = pDate; }

  CDate &operator++();

  bool setDate(std::string pDate)
  {
    if (pDate.length() != 10)
      return false;

    separate();

    date = pDate;
    return true;
  }

  std::string getDate() { return date; }

  bool validate()
  {
    bisiesto = validateYear();

    if (!validateMonth())
      return false; // Mes InCorrecto

    if (!validateDay())
      return false; // Día InCorrecto

    return true; // Fecha Correcta
  }
};

std::ostream &operator<<(std::ostream &o, const CDate &p)
{
  o << "(" << p.day << "/" << p.month << "/" << p.year << ")";
  return o;
}

CDate &CDate::operator++()
{
  this->day++;

  if (!this->validate())
  {
    this->day = 1;
    this->month++;
    if (!this->validate())
    {
      this->month = 1;
      this->year++;
    }
  }

  return *this;
}