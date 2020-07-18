#include <iostream>
using namespace std;
class CDate{
private:
  // data members of date object
  int month, day, year;
  static int daysofMonth[12];
  static char strofmonth[12][4];
  static char stringofmonth[12][10];
public:

  // null constructor
  CDate();

  // Parametric constructor
	CDate(int d, int m, int y);

  // destructor
  ~CDate(){}

  // setter functions
	CDate& setDay(int d);
	CDate& setMonth(int m);
	CDate& setYear(int y);

  // getter functions
  int getday();
  int getmonth();
  int getyear();

  // print function for date objects in different formats
  void print(int opt = 0);

  // function to get input user input
  void Readfromkb();

  // validate function to check the valid date
  void validate();

  // isleapyear function checks the year is leap or not
  bool isleapyear()const;

  // setter function for complete date object
  CDate& setDate(int d, int m, int y);

  // compares two date objects and return a value according to the decision
  int comparewithdate(CDate date);

  // returns a string of object
  char* tostring()const;

  // all comparison operators overloaded for cdate class object behaves same as other classes and compare two dates
  int operator <(CDate date)const;
  int operator <=(CDate date)const;
  int operator >(CDate date)const;
  int operator >=(CDate date)const;
  int operator ==(const CDate date)const;
  int operator !=(const CDate date)const;

  // POSTFIX and PREFIX increment & decrement operator overloaded for cdate class
  CDate& operator++();
  CDate operator++(int);
  CDate& operator--();
  CDate operator--(int);


  // + and - operator overloaded for cdate class objects
  CDate operator +(CDate & m);
  CDate operator -(CDate & m);


  // + and - operator overloaded to add cdate class object with int, double and char data type
  CDate operator +(int m);
  CDate operator -(int m);
  CDate operator +(double m);
  CDate operator -(double m);
  CDate operator +(char* m);
  CDate operator -(char* m);

  // += and -= operator for cdate class objects
  CDate& operator +=(CDate & m);
  CDate& operator -=(CDate & m);

  // += and -= operators overloaded for cdate class object at left side and on the other side int, double or char type
  CDate& operator +=(int m);
  CDate& operator -=(int m);
  CDate& operator +=(double m);
  CDate& operator -=(double m);
  CDate& operator +=(char* m);
  CDate& operator -=(char* m);

  // default cin>> incertion operator and cout<< excertion operator overloaded for cdate class object
  friend ostream& operator <<(ostream &output, const CDate &date);
  friend istream& operator >>(istream &input, CDate &date);

  //  +, +=, -= and - functions overloaded for int, double or char type at left and cdate class object at right side of operator
  friend CDate operator +(int m, CDate &date);
  friend CDate operator -(int m, CDate &date);
  friend CDate operator +=(int m, CDate &my);
  friend CDate operator -=(int m, CDate &my);
  friend CDate operator +(double m, CDate &date);
  friend CDate operator -(double m, CDate &date);
  friend CDate operator +=(double m, CDate &my);
  friend CDate operator -=(double m, CDate &my);
  friend CDate operator +(char* m, CDate &date);
  friend CDate operator -(char* m, CDate &date);
  friend CDate operator +=(char* m, CDate &my);
  friend CDate operator -=(char* m, CDate &my);

};
