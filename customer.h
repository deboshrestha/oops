#ifndef CUSTOMER
#define CUSTOMER
#include "user.h"
#include<string>
#include "item.h"

class Customer : public User
{
  
  std::string customer_name;
  int customer_id;
  int passwd;
  //Yes constructors can be private too
 public:
   Customer();      
   Customer(int);
   void bid(Item,float);
   virtual int login();
   virtual void register_func();
};

#endif //CUSTOMER
