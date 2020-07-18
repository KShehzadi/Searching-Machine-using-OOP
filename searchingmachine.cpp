#include <iostream>
#include <cstring>
#include <cstdlib>
#include "searchingmachine.h"
using namespace std;
SearchingMachine::SearchingMachine()
{
  data[10] = '\0';
  size = 0;
}
SearchingMachine::~SearchingMachine()
{

}
void SearchingMachine::input()
{
  cout<< "Enter 10 integers:";
  int i = 0;
  while (i < 10)
 {
    cin>> this->data[i];
    i++;
  }
  this->size = 10;
}
void SearchingMachine::print()
{
  int i = 0;
  while(i < this->size)
  {
    cout << this->data[i] << '\n';
    i++;
  }
}
BinarySearch::BinarySearch()
{

}
BinarySearch::~BinarySearch()
{

}
void BinarySearch::sort()
{
  int i, j, temp;
  for(i = 1; i < this->size; ++i)
  {
    for(j = 0; j < this->size - i; ++j)
    {
      if(this->data[j] < this->data[j + 1])
      {
        temp = this->data[j];
        this->data[j] = this->data[j + 1];
        this->data[j + 1] = temp;
      }
    }
  }
}
void BinarySearch::search(int v)
{
  this->sort();
  int low = 0, high = this->size;
  while(low <= high )
  {
    int mid = (low + high) / 2;
    if(v == this->data[mid])
    {
      cout<< "yes!! element is in the list!"<< endl;
      return;
    }
    if(v > this->data[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  cout<< "oops! element is not here "<< endl;
}
LinearSearch::LinearSearch()
{

}
void LinearSearch::search(int v)
{
  int i;
  for (i = 0; i < this->size; i++)
  {
    if (data[i] == v)
    {
      cout<< "yayyyy! element is here in the list !"<< endl;
      return;
    }
  }
  cout<< "ohh! element does not exist in the list"<< endl;
}
LinearSearch::~LinearSearch()
{

}
