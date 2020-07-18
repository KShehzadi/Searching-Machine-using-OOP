#include <iostream>
#include <cstring>
#include "CPerson.h"
using namespace std;
Person::Person(){
  CName n1;
  CDate d1;
  name = n1;
  dob = d1;
  Email = new char[1];
  Email = '\0';
  Address = new char[1];
  Address = '\0';
  Contact = new char[1];
  Contact = '\0';
  CNIC = new char[1];
  CNIC = '\0';
}
Person::Person(CName &name, CDate &dob, char* Email, char* Address, char* Contact, char* CNIC)
{
  this->name = name;
  this->dob = dob;
  this->Email = new char[strlen(Email) + 1];
  strcpy(this->Email, Email);
  this->Address = new char[strlen(Address) + 1];
  strcpy(this->Address, Address);
  this->Contact = new char[strlen(Contact) + 1];
  strcpy(this->Contact, Contact);
  this->CNIC = new char[strlen(CNIC) + 1];
  strcpy(this->CNIC, CNIC);
}
CName& Person::getname()
{
  return name;
}
CDate& Person::getdob()
{
  return dob;
}
char* Person::getemail()
{
  return Email;
}
char* Person::getaddress()
{
  return Address;
}
char* Person::getcontact()
{
  return Contact;
}
char* Person::getCNIC()
{
  return CNIC;
}
Person& Person::setname(CName &src)
{
  name = src;
  return *this;
}
Person& Person::setdob(CDate &src)
{
  dob = src;
  return *this;
}
Person& Person::setemail(char * src)
{
  delete[]Email;
  this->Email = new char[strlen(src) + 1];
  strcpy(this->Email, src);
  return *this;
}
Person& Person::setaddress(char * src)
{
  delete[]Address;
  this->Address = new char[strlen(src) + 1];
  strcpy(this->Address, src);
  return *this;
}
Person& Person::setcontact(char * src)
{
  delete[]Contact;
  this->Contact = new char[strlen(src) + 1];
  strcpy(this->Contact, src);
  return *this;
}
Person& Person::setCNIC(char * src)
{
  delete[] CNIC;
  this->CNIC = new char[strlen(src) + 1];
  strcpy(this->CNIC, src);
  return *this;
}
int Person::getAge()
{
  int i;
  CDate d1;
  cout<< "Enter todays date in dd mm yyyy format:";
  d1.Readfromkb();
  i = d1.getyear() - this->dob.getyear();
  return i;
}
bool Person::validatedob()
{
  dob.validate();
  if(dob.getday() == -1)
  {
    return false;
  }
  return true;
}
bool Person::validatecontact()
{
  int i;
  if(strlen(Contact) != 11)
  {
    return false;
  }
  if((int)Contact[0] != 48)
  {
    return false;
  }
  if((int)Contact[1] != 51)
  {
    return false;
  }
  for(i = 2; i < strlen(Contact); i++)
  {
    if(Contact[i] < 48 || Contact[i] > 57)
    {
      return false;
    }
  }
  return true;

}
bool Person::validatename()
{
  char* str1;
  str1 = name.getfirstname();
  int i, j;
  for(i = 0; i < strlen(str1); i++)
  {
    j = (int)str1[i];
    if(j < 65 || j > 122)
    {
      return false;
    }
    if(j < 97 && j > 90)
    {
      return false;
    }
  }
  str1 = name.getmidname();
  for(i = 0; i < strlen(str1); i++)
  {
    j = (int)str1[i];
    if(j < 65 || j > 122)
    {
      return false;
    }
    if(j < 97 && j > 90)
    {
      return false;
    }
  }
  str1 = name.getlastname();
  for(i = 0; i < strlen(str1); i++)
  {
    j = (int)str1[i];
    if(j < 65 || j > 122)
    {
      return false;
    }
    if(j < 97 && j > 90)
    {
      return false;
    }
  }
  return true;
}
bool Person::validateCNIC()
{
  if(strlen(CNIC) != 13)
  {
    return false;
  }
  int i;
  for(i = 0; i < strlen(CNIC); i++)
  {
    if((int)CNIC[i] < 48 || (int)CNIC[i] > 57)
    {
      return false;
    }
  }
}
Person::~Person()
{
  delete[] Email;
  delete[] Contact;
  delete[] CNIC;
}
Student::Student()
{
  Person p1;
  RegistrationNumber = new char[1];
  RegistrationNumber = '\0';
}
int Student::getsession()
{
  char * str1;
  cin>> this->name;
  cin>> this->dob;
  cout<< "enter your email address:";
  cin>> str1;
  this->setemail(str1);
  cout<< "enter your contact number:";
  cin>> str1;
  this->setcontact(str1);
  cout<< "enter your CNIC:";
  cin>> str1;
  this->setCNIC(str1);
  cout<< "enter your RegistrationNumber:";
  cin>> str1;
  delete [] this->RegistrationNumber;
  this->RegistrationNumber = new char[strlen(str1) + 1];
  strcpy(this->RegistrationNumber, str1);
  int i = 3;
  int j = 0;
  char* x;
  int p = 10;
  while(i > 0)
  {
    x = (char*)this->RegistrationNumber[i];
    j = j + (atoi(x)) * p;
    p = p * 10;
    i--;
  }
  return j;
}
char* Student::getdegreename()
{
  char * str1;
  cin>> this->name;
  cin>> this->dob;
  cout<< "enter your email address:";
  cin>> str1;
  this->setemail(str1);
  cout<< "enter your contact number:";
  cin>> str1;
  this->setcontact(str1);
  cout<< "enter your CNIC:";
  cin>> str1;
  this->setCNIC(str1);
  cout<< "enter your RegistrationNumber:";
  cin>> str1;
  delete [] this->RegistrationNumber;
  this->RegistrationNumber = new char[strlen(str1) + 1];
  strcpy(this->RegistrationNumber, str1);
  int i = 4, j = 0;
  char * degree = new char[3];
  degree[2] = '\0';
  while(i < 6)
  {
    degree[j] = this->RegistrationNumber[i];
    i++;
    j++;
  }
  return degree;
}
Student::~Student()
{
  delete[] RegistrationNumber;
}


Teacher::Teacher()
{
  Person p1();
  Designation = new char[1];
  Designation = '\0';
}
Teacher::~Teacher(){
  delete[] Designation;
}
char* Teacher::getDesignation()
{
  char * str1;
  cin>> this->name;
  cin>> this->dob;
  cout<< "enter your email address:";
  cin>> str1;
  this->setemail(str1);
  cout<< "enter your contact number:";
  cin>> str1;
  this->setcontact(str1);
  cout<< "enter your CNIC:";
  cin>> str1;
  this->setCNIC(str1);
  cout<< "enter your RegistrationNumber:";
  cin>> str1;
  delete [] this->Designation;
  this->Designation = new char[strlen(str1) + 1];
  strcpy(this->Designation, str1);
  return Designation;
}
