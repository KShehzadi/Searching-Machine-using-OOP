#include "CPerson.h"
int main()
{
  bool my;
  CName name((char*)"komal",(char*)"", (char*)"shehzadi");
  CDate dob(2, 12, 1998);
  Person p1();
  Person p2(name, dob, (char*)"shehzadikomal303@gmail.com", (char*)"xyz", (char*)"03231499343", (char*)"3520114265578");
  my = p2.validatename();
  if(my)
  {
    cout<< "yayyyy!"<< endl;
  }
  my = p2.validatecontact();
  if(my)
  {
    cout<< "yippppeee"<< endl;
  }
  my = p2.validateCNIC();
  if(my)
  {
    cout<< "finally!"<< endl;
  }
  int i = p2.getAge();
  cout<< p2.getname()<< "'s age is :"<< i<< endl;
  CName n1((char*)"123",(char*)"", (char*)"hi");
  p2.setname(n1);
  if(p2.validatename())
  {
    cout<< "something went wrong"<< endl;
  }
  p2.setcontact((char*)"03686fh7111");
  if(p2.validatecontact())
  {
    cout<< " something went wrong"<< endl;
  }
  p2.setCNIC((char*)"6532637981gfu");
  if(p2.validateCNIC())
  {
    cout<< "oops something went wrong"<< endl;
  }
  Student s1();
  return 0;
}
