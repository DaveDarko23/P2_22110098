class Node
{
public:
  int mID, Nivel;
  std::string value;
  Node *left;
  Node *right;

  Node() {}
  ~Node()
  {
    delete left;
    delete right;
  }
};