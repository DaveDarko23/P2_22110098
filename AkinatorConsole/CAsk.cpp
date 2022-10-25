#include <list>

class CAsk
{
public:
  int key = 0;
  std::string value;

  CAsk(int pKey, std::string pValue)
  {
    key = pKey;
    value = pValue;
  }
  ~CAsk() {}
};