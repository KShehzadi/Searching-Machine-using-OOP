#include "CDate.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Static data members shared among all objects of class
int  CDate::daysofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char CDate::strofmonth[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char CDate::stringofmonth[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

// NULL constructor
CDate::CDate(){day = 14; month = 8; year = 1947; validate();}

// Parametric constructor
CDate::CDate(int d, int m, int y){
  day = d, month = m; year = y; validate();
}

// input function to get input from user
void CDate::Readfromkb(){
  do{cout<< "\n \a Enter a date as dd mm yyyy :";cin>> day>> month>> year;validate();}while(day == -1);
}

// validate function to check the date is valid or invalid if invalid it will change the day to -1
void CDate::validate(){if(month < 1 || month > 12) day = -1; else{if(isleapyear())daysofMonth[1] = 29; else daysofMonth[1] = 28;}
if(day < 1 || day > daysofMonth[month - 1]) day = -1;}

// checks weather the year is leap or not
bool CDate::isleapyear()const{
  if(year % 4 ) return 0;else return 1;
}

// setter function for day data member
CDate& CDate::setDay(int d){day = d; validate();return *this;}

// setter function for year data member
CDate& CDate::setYear(int y){year = y; validate(); return *this;}

// setter function for month data member
CDate& CDate::setMonth(int m){month = m; validate(); return *this;}

// setter function for all data members togather year month and day data member
CDate& CDate::setDate(int d, int m, int y){
  day = d, month = m; year = y; validate();
  return *this;
}

// getter function to get day data member
int CDate::getday()
{
  return day;
}

// getter function to get month data member
int CDate::getmonth()
{
  return month;
}

// getter function to get year data member
int CDate::getyear()
{
  return year;
}

// print function for date object to print it with different formats
void CDate::print(int opt)
{
  if(opt == 2)
  {
    cout<< stringofmonth[month - 1]<< " "<< day<< "," <<year <<"\n";
  }
  else if(opt == 1)
  {
    cout <<day << "-"<< strofmonth[month - 1]<< "-"<<year <<"\n";
  }
  else
  {
    cout<<day <<"/" <<month <<"/" <<year <<"\n";
  }
}

// function to compare two date objects
int CDate::comparewithdate(CDate date)
{
  if (year < date.year)
  {
    return -1;
  }
  if (year > date.year)
  {
    return 1;
  }
  if (month < date.month)
  {
    return -1;
  }
  if (month > date.month)
  {
    return 1;
  }
  if (day < date.day)
  {
    return -1;
  }
  if (day > date.day)
  {
    return 1;
  }
  return 0;
}

// utility function to get the string object of the required object
char* CDate::tostring()const{
  char pad[20];
  sprintf(pad, "%d / %d / %d", this->day, this->month, this->year);
  char *str = new char[strlen(pad) + 1];
  strcpy(str, pad);
  return str;
}
int CDate::operator <(CDate date)const
{
  if (this->year < date.year)
  {
    return 1;
  }
  if (this->year > date.year)
  {
    return 0;
  }
  if (this->month < date.month)
  {
    return 1;
  }
  if (this->month > date.month)
  {
    return 0;
  }
  if (this->day < date.day)
  {
    return 1;
  }
  return 0;
}

// <= comparison function for two date objects
int CDate::operator <=(CDate date)const
{
  if (this->year < date.year)
  {
    return 1;
  }
  if (this->year > date.year)
  {
    return 0;
  }
  if (this->month < date.month)
  {
    return 1;
  }
  if (this->month > date.month)
  {
    return 0;
  }
  if (this->day <= date.day)
  {
    return 1;
  }
  return 0;
}

// > function for two date objects
int CDate::operator >(CDate date)const
{
  if (this->year > date.year)
  {
    return 1;
  }
  if (this->year < date.year)
  {
    return 0;
  }
  if (this->month > date.month)
  {
    return 1;
  }
  if (this->month < date.month)
  {
    return 0;
  }
  if (this->day > date.day)
  {
    return 1;
  }
  return 0;
}

// >= function for two date objects
int CDate::operator >=(CDate date)const
{
  if (this->year > date.year)
  {
    return 1;
  }
  if (this->year < date.year)
  {
    return 0;
  }
  if (this->month > date.month)
  {
    return 1;
  }
  if (this->month < date.month)
  {
    return 0;
  }
  if (this->day >= date.day)
  {
    return 1;
  }
  return 0;
}

// == function for two date objects
int CDate::operator ==(const CDate date)const
{
  if (this->year != date.year)
  {
    return 0;
  }
  if (this->month != date.month)
  {
    return 0;
  }
  if(this->day != date.day)
  {
    return 0;
  }
  return 1;
}

// != function for two date objects
int CDate::operator !=(const CDate date)const
{
  if (this->year != date.year)
  {
    return 1;
  }
  if (this->month != date.month)
  {
    return 1;
  }
  if(this->day != date.day)
  {
    return 1;
  }
  return 0;
}

// excertion operator overloaded
ostream & operator <<(ostream & output, const CDate & date)
{
  output<< date.day<< '/'<< date.month<< '/'<< date.year;
  return output;
}

// incertion operator overloaded
istream& operator >>(istream & input, CDate & date)
{
  do{
    cout<< "\n \a Enter date as dd mm yyyy :";
    input>> date.day>> date.month>> date.year;
    date.validate();
  }while(date.day == -1);
  return input;
}

// prefix increment operator for cdate class object
CDate& CDate::operator ++()
{
  this->validate();
  ++day;
  if(day > daysofMonth[month - 1])
  {
    day = 1;
    ++month;
    if(month > 12)
    {
      month = 1;
      year++;
    }
  }
  return *this;
}

// postfix increment operator for cdate class object
CDate CDate::operator++(int){
  CDate temp(*this);
  this->validate();
  ++day;
  if(day > daysofMonth[month - 1])
  {
    day = 1;
    ++month;
    if(month > 12)
    {
      month = 1;
      year++;
    }
  }
  return temp;
}

// prefix decrement operatorfor cdate class object
CDate& CDate::operator--()
{
  this->validate();
  --this->day;
  if (this->day == 0)
  {
    --this->month;
    this->day = daysofMonth[this->month - 1];
    if(this->month == 0)
    {
      this->month = 12;
      this->day = daysofMonth[this->month - 1];
      --this->year;
    }
  }
  return *this;
}

// postfix decrement operator for cdate class object
CDate CDate::operator--(int)
{
  this->validate();
  CDate temp(*this);
  this->day--;
  if (this->day == 0)
  {
    this->month--;
    this->day = daysofMonth[month - 1];
    if(this->month == 0)
    {
      this->month = 12;
      this->day = daysofMonth[month - 1];
      this->year--;
    }
  }
  return temp;

}

// + operator for cdate class objects
CDate CDate::operator +(CDate & m)
{
  CDate x;
  CDate y;
  CDate newdate;
  int i;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year + i;
  newdate.month = x.month + y.month;
  if(newdate.month > 12)
  {
    newdate.year++;
    newdate.month = newdate.month - 12;
  }
  newdate.day = x.day + y.day;
  if(newdate.day > daysofMonth[newdate.month - 1])
  {
    newdate.day = newdate.day - daysofMonth[newdate.month - 2];
    newdate.month++;
  }
  return newdate;
}

// - operator for cdate class objects
CDate CDate::operator -(CDate & m)
{
  CDate newdate;
  int i;
  CDate x, y;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year - i;
  newdate.month = x.month - y.month;
  if(newdate.month < 1)
  {
    newdate.year--;
    newdate.month = newdate.month + 12;
    newdate.day = x.day - y.day;
    if(newdate.day < 1)
    {
      newdate.day = daysofMonth[newdate.month - 1] + newdate.day;
      newdate.month--;
    }
  }
  return newdate;
}

// += operator for cdate class object
CDate& CDate::operator +=(CDate & m)
{
  CDate x;
  CDate y;
  CDate newdate;
  int i;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year + i;
  newdate.month = x.month + y.month;
  if(newdate.month > 12)
  {
    newdate.year++;
    newdate.month = newdate.month - 12;
  }
  newdate.day = x.day + y.day;
  if(newdate.day > daysofMonth[newdate.month - 1])
  {
    newdate.day = newdate.day - daysofMonth[newdate.month - 2];
    newdate.month++;
  }
  this->year = newdate.year;
  this->month = newdate.month;
  this->day = newdate.day;
  return *this;
}

// -= operator for cdate class objects
CDate& CDate::operator -=(CDate & m)
{
  CDate newdate;
  int i;
  CDate x, y;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year - i;
  newdate.month = x.month - y.month;
  if(newdate.month < 1)
  {
    newdate.year--;
    newdate.month = newdate.month + 12;
    newdate.day = x.day - y.day;
    if(newdate.day < 1)
    {
      newdate.day = daysofMonth[newdate.month - 1] + newdate.day;
      newdate.month--;
    }
  }
  this->year = newdate.year;
  this->month = newdate.month;
  this->day = newdate.day;
  return *this;
}

// + operator to add a int type object in cdate class object
CDate CDate::operator +(int m)
{
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < m; i++)
  {
    ++my;
    my.validate();
  }
  return my;
}

// - operator to subtract a int type object from a cdate class object
CDate CDate::operator -(int m)
{
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < m; i++)
  {
    --my;
  }
  return my;
}

// + operator to add a double type object to cdate class object
CDate CDate::operator +(double m)
{
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < m; i++)
  {
    my++;
  }
  return my;
}

// - operator to subtract a double type object from cdate class object
CDate CDate::operator -(double m)
{
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < m; i++)
  {
    my--;
  }
  return my;
}

// + operator to add a char type object to cdate class object
CDate CDate:: operator +(char* m)
{
  int k;
  k = atoi(m);
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < k; i++)
  {
    my++;
  }
  return my;
}

// - operator to subtract char type object from cdate class object
CDate CDate::operator -(char* m)
{
  int k;
  k = atoi(m);
  CDate my;
  my.year = this->year;
  my.month = this->month;
  my.day = this->day;
  my.validate();
  for(int i = 0; i < k; i++)
  {
    my--;
  }
  return my;
}

// += : cdate class object += int type object
CDate& CDate::operator +=(int m)
{
  for(int i = 0; i < m; i++)
  {
    this->validate();
    ++day;
    if(day > daysofMonth[month - 1])
    {
      day = 1;
      ++month;
      if(month > 12)
      {
        month = 1;
        year++;
      }
    }
  }
  return *this;
}

// -= operator : cdate class object -= int type object
CDate& CDate::operator -=(int m)
{
  for(int i = 0; i < m; i++)
  {
    this->validate();
    --this->day;
    if (this->day == 0)
    {
      --this->month;
      this->day = daysofMonth[this->month - 1];
      if(this->month == 0)
      {
        this->month = 12;
        this->day = daysofMonth[this->month - 1];
        --this->year;
      }
    }
  }
  return *this;
}

// += operator: cdate class object += double type object
CDate& CDate::operator +=(double m)
{
  for(int i = 0; i < m; i++)
  {
    this->validate();
    ++day;
    if(day > daysofMonth[month - 1])
    {
      day = 1;
      ++month;
      if(month > 12)
      {
        month = 1;
        year++;
      }
    }
  }
  return *this;
}

// -= operator : cdate class object -= double type object
CDate& CDate::operator -=(double m)
{
  for(int i = 0; i < m; i++)
  {
    this->validate();
    --this->day;
    if (this->day == 0)
    {
      --this->month;
      this->day = daysofMonth[this->month - 1];
      if(this->month == 0)
      {
        this->month = 12;
        this->day = daysofMonth[this->month - 1];
        --this->year;
      }
    }
  }
  return *this;
}

// += : cdate class object += char type object
CDate& CDate::operator +=(char* m)
{
  int p = atoi(m);
  for(int i = 0; i < p; i++)
  {
    this->validate();
    ++day;
    if(day > daysofMonth[month - 1])
    {
      day = 1;
      ++month;
      if(month > 12)
      {
        month = 1;
        year++;
      }
    }
  }
  return *this;
}

// -= operator: cdate class object -= char type object
CDate& CDate::operator -=(char* m)
{
  int p = atoi(m);
  for(int i = 0; i < p; i++)
  {
    this->validate();
    --this->day;
    if (this->day == 0)
    {
      --this->month;
      this->day = daysofMonth[this->month - 1];
      if(this->month == 0)
      {
        this->month = 12;
        this->day = daysofMonth[this->month - 1];
        --this->year;
      }
    }
  }
  return *this;
}

// + operator : cdate object = int + cdate
CDate operator +(int m, CDate &date)
{
  CDate my;
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < m; i++)
  {
    my.validate();
    ++my.day;
    if(my.day > date.daysofMonth[my.month - 1])
    {
      my.day = 1;
      ++my.month;
      if(my.month > 12)
      {
        my.month = 1;
        my.year++;
      }
    }
  }
  return my;
}

// - operator : cdate object = int - cdate
CDate operator -(int m, CDate & date)
{
  CDate my;
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < m; i++)
  {
    my.validate();
    --my.day;
    if (my.day == 0)
    {
      --my.month;
      my.day = date.daysofMonth[my.month - 1];
      if(my.month == 0)
      {
        my.month = 12;
        my.day = date.daysofMonth[my.month - 1];
        --my.year;
      }
    }
  }
  return my;
}

// + operator: cdate = double + cdate
CDate operator +(double m, CDate &date)
{
  CDate my;
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < m; i++)
  {
    my.validate();
    ++my.day;
    if(my.day > date.daysofMonth[my.month - 1])
    {
      my.day = 1;
      ++my.month;
      if(my.month > 12)
      {
        my.month = 1;
        my.year++;
      }
    }
  }
  return my;
}

// - operator : cdate object = double - cdate
CDate operator -(double m, CDate & date)
{
  CDate my;
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < m; i++)
  {
    my.validate();
    --my.day;
    if (my.day == 0)
    {
      --my.month;
      my.day = date.daysofMonth[my.month - 1];
      if(my.month == 0)
      {
        my.month = 12;
        my.day = date.daysofMonth[my.month - 1];
        --my.year;
      }
    }
  }
  return my;
}

// + operator: cdate object = char + cdate
CDate operator +(char* m, CDate &date)
{
  CDate my;
  int p = atoi(m);
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < p; i++)
  {
    my.validate();
    ++my.day;
    if(my.day > date.daysofMonth[my.month - 1])
    {
      my.day = 1;
      ++my.month;
      if(my.month > 12)
      {
        my.month = 1;
        my.year++;
      }
    }
  }
  return my;
}

// - operator: cdate = char - cdate
CDate operator -(char* m, CDate & date)
{
  CDate my;
  int p = atoi(m);
  my.year = date.year;
  my.month = date.month;
  my.day = date.day;
  for(int i = 0; i < p; i++)
  {
    my.validate();
    --my.day;
    if (my.day == 0)
    {
      --my.month;
      my.day = date.daysofMonth[my.month - 1];
      if(my.month == 0)
      {
        my.month = 12;
        my.day = date.daysofMonth[my.month - 1];
        --my.year;
      }
    }
  }
  return my;
}

// -= operator: cdate object = (int -= cdate)
CDate operator -=(int m, CDate &my)
{
  CDate date;
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < m; i++)
  {
    date.validate();
    --date.day;
    if (date.day == 0)
    {
      --date.month;
      date.day = date.daysofMonth[date.month - 1];
      if(date.month == 0)
      {
        date.month = 12;
        date.day = date.daysofMonth[date.month - 1];
        --date.year;
      }
    }
  }
  return date;
}

// += operator: cdate = (int += cdate)
CDate operator +=(int m, CDate &my)
{
  CDate date;
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < m; i++)
  {
    date.validate();
    ++date.day;
    if(date.day > date.daysofMonth[date.month - 1])
    {
      date.day = 1;
      ++date.month;
      if(date.month > 12)
      {
        date.month = 1;
        date.year++;
      }
    }
  }
  return date;
}

// -= operator: cdate object = (double -= cdate)
CDate operator -=(double m, CDate &my)
{
  CDate date;
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < m; i++)
  {
    date.validate();
    --date.day;
    if (date.day == 0)
    {
      --date.month;
      date.day = date.daysofMonth[date.month - 1];
      if(date.month == 0)
      {
        date.month = 12;
        date.day = date.daysofMonth[date.month - 1];
        --date.year;
      }
    }
  }
  return date;
}

// += operator: cdate = (double += cdate)
CDate operator +=(double m, CDate &my)
{
  CDate date;
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < m; i++)
  {
    date.validate();
    ++date.day;
    if(date.day > date.daysofMonth[date.month - 1])
    {
      date.day = 1;
      ++date.month;
      if(date.month > 12)
      {
        date.month = 1;
        date.year++;
      }
    }
  }
  return date;
}

// -= operator : cdate = (char -= cdate)
CDate operator -=(char* m, CDate &my)
{
  CDate date;
  int p = atoi(m);
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < p; i++)
  {
    date.validate();
    --date.day;
    if (date.day == 0)
    {
      --date.month;
      date.day = date.daysofMonth[date.month - 1];
      if(date.month == 0)
      {
        date.month = 12;
        date.day = date.daysofMonth[date.month - 1];
        --date.year;
      }
    }
  }
  return date;
}

// += operator: cdate = (char += cdate)
CDate operator +=(char* m, CDate &my)
{
  CDate date;
  int p = atoi(m);
  date.year = my.year;
  date.month = my.month;
  date.day = my.day;
  for(int i = 0; i < p; i++)
  {
    date.validate();
    ++date.day;
    if(date.day > date.daysofMonth[date.month - 1])
    {
      date.day = 1;
      ++date.month;
      if(date.month > 12)
      {
        date.month = 1;
        date.year++;
      }
    }
  }
  return date;
}
