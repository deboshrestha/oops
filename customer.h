#ifndef CUSTOMER
#define CUSTOMER

#include<string>
#include "item.h"

class Customer
{
  std::string customer_name;
  int customer_id;
  //Yes constructors can be private too
  Customer();
  public:
  Customer(std::string,int);
  void bid(Item,float);
};
#endif //CUSTOMER
