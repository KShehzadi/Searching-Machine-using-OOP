#include "CDate.h"
#include "cname.h"
class Person
{
protected:
  CName name;
  CDate dob;
  char* Email;
  char* Address;
  char* Contact;
  char* CNIC;
public:
  Person();
  Person(CName &name, CDate &dob, char* Email, char* Address, char* Contact, char* CNIC);
  ~Person();
  int getAge();
  bool validatedob();
  bool validatecontact();
  bool validatename();
  bool validateCNIC();
  CName& getname();
  CDate& getdob();
  char* getemail();
  char* getaddress();
  char* getcontact();
  char* getCNIC();
  Person& setname(CName &src);
  Person& setdob(CDate &src);
  Person& setemail(char * src);
  Person& setaddress(char * src);
  Person& setcontact(char * src);
  Person& setCNIC(char * CNIC);

};
class Student:public Person{
protected:
  char* RegistrationNumber;
public:
  Student();
  ~Student();
  int getsession();
  char* getdegreename();

};
class Teacher:public Person{
protected:
  char* Designation;
public:
  Teacher();
  Teacher(char* tech);
  ~Teacher();
  char* getDesignation();

};
