/*
*
*  Designer: Kamyab Rouhifar
*  Date: 2020-04-18
*  Program: C++ Language
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
////////////////////////////Base class///////////////////////////////////
const int MAX_CHAR = 20;

class Vehicle
{
      /*---------------------------------------------------*/
private:
  char *city;

       /*---------------------------------------------------*/

public:
    Vehicle (const char *city)
  {
    if (city != nullptr)
      {
	this->city = new char[strlen (city) + 1];
	  memcpy (this->city, city, strlen (city) + 1);
      }

  }
   ~Vehicle ()
  {
    delete[]city;
    city = nullptr;
  }

  void Diplay (std::ostream & os) const
  {

      os << "I am living in " << city << std::endl;
  }
};
////////////////////////////Derived class///////////////////////////////////
class Car:public Vehicle
{
    /*---------------------------------------------------*/
private:			// As a default

  int number;
  char name[MAX_CHAR];

    /*---------------------------------------------------*/

public:

    Car (const char *name, int number, const char *city):Vehicle (city)
  {
    if (name != nullptr && number != 0)	// Checking empty state
      {
	this->number = number;
	memcpy (this->name, name, MAX_CHAR);
	FullData ();
      }
    else
        setEmpty ();

  }
  /*---------------------------------------------------*/
  void Diplay () const
  {

    if (!isEmpty ())
      {
	std::cout << "My name is " << name << std::endl;
	std::cout << "I was born in " << number << std::endl;
	Vehicle::Diplay (std::cout);
      }

  }
  /*---------------------------------------------------*/
  bool isEmpty () const
  {
    return (name[0] == '\0' && number == 0) ? true : false;
  }
  /*---------------------------------------------------*/
  void setEmpty ()
  {
    printf ("***Data are empty***\n");
    number = 0;
    name[0] = '\0';
  }
  /*---------------------------------------------------*/
  void FullData ()
  {
    printf ("Data is Full , No empty\n");
  }
 /*---------------------------------------------------*/
};

/*---------------------------------------------------*/
int
main ()
{
  std::
    cout << "The sample of Encapsulation & hierarchy inheritance in C++" <<
    std::endl << std::endl;

  Car a ("Kamyab", 1998, "Toronto");
  Car b (nullptr, 1998, "Montreal");
  Car c ("Kamyab", 0,  "London");
  printf ("-----------------------\n");
  a.Diplay ();
  b.Diplay ();
  c.Diplay ();
  return 0;
}
