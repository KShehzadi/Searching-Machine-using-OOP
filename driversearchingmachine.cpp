#include "searchingmachine.h"
#include <iostream>
using namespace std;
int main()
{
  int i;
  SearchingMachine s1;
  BinarySearch b1;
  b1.input();
  cout<<"*************************************************"<< endl;
  cout<< "this is the list before sorting:"<< endl;
  cout<<"**************************************************"<< endl;
  b1.print();
  cout<<"*************************************************"<< endl;
  cout<< "this is the list after sorting:"<< endl;
  cout<<"**************************************************"<< endl;
  b1.sort();
  b1.print();
  cout<<"*************************************************"<< endl;
  cout<< "checking whether the element 4 is in the list or not"<< endl;
  cout<<"**************************************************"<< endl;
  b1.search(4);
  cout<< "\t enter a element to search in list via binary search:\n";
  cin>> i;
  b1.search(i);
  LinearSearch l1;
  cout<<"*************************************************"<< endl;
  cout<< "now testing of Linear search class starts!"<< endl;
  cout<<"**************************************************"<< endl;
  l1.input();
  cout<< "\t enter a element to search in list via linear search:\n";
  cin>> i;
  l1.search(i);
}
