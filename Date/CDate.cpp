#include <iostream>
#include <string>

class CDate
{
private:
  std::string mDate;
  bool mBisiesto;

  void separate()
  {
    std::string mTempDate = mDate;

    mDay = stoi(mTempDate.substr(0, 2));
    mTempDate.erase(0, 3);

    mMonth = stoi(mTempDate.substr(0, 2));
    mTempDate.erase(0, 3);

    mYear = stoi(mTempDate.substr(0, 4));
  }

  bool validateDay()
  {

    if (mYear <= 0)
      return false;

    switch (mMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return (mDay <= 31);
    case 4:
    case 6:
    case 9:
    case 11:
      return (mDay <= 30);
    case 2:
      return ((mDay <= 28 && !mBisiesto) || (mDay <= 29 && mBisiesto));
    }

    return true;
  }

  short validateMonth() { return (mMonth >= 1 && mMonth <= 12); }

  short validateYear() { return ((mYear % 4 == 0) && (mYear % 100 != 0)); }

public:
  int mDay, mMonth, mYear;

  CDate(std::string pDate) { mDate = pDate; }

  CDate &operator++();

  bool setDate(std::string pDate)
  {
    if (pDate.length() != 10)
      return false;

    separate();

    mDate = pDate;
    return true;
  }

  std::string getDate() { return mDate; }

  bool validate()
  {
    mBisiesto = validateYear();

    if (!validateMonth())
      return false; // Mes InCorrecto

    if (!validateDay())
      return false; // Día InCorrecto

    return true; // Fecha Correcta
  }
};

std::ostream &operator<<(std::ostream &o, const CDate &pDate)
{
  o << "(" << pDate.mDay << "/" << pDate.mMonth << "/" << pDate.mYear << ")";
  return o;
}

CDate &CDate::operator++()
{
  this->mDay++;

  if (!this->validate())
  {
    this->mDay = 1;
    this->mMonth++;
    if (!this->validate())
    {
      this->mMonth = 1;
      this->mYear++;
    }
  }

  return *this;
}