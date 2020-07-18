class SearchingMachine
{
protected:
  int data[10];
  int size;
public:
  SearchingMachine();
  void input();
  void print();
  ~SearchingMachine();
};
class BinarySearch:public SearchingMachine{
public:
  BinarySearch();
  void search(int v);
  void sort();
  ~BinarySearch();
};
class LinearSearch:public SearchingMachine{
public:
  LinearSearch();
  ~LinearSearch();
  void search(int v);
};
