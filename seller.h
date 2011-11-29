#ifndef SELLER
#define SELLER
#include "user.h"
#include<string>
#include "item.h"

class Seller : public User
{
      public:
  std::string seller_name;
  int seller_id;
  std::string user_name;
	std::string email_id;
	std::string bank;
	int userid;
	int passwd;
	
  //Yes constructors can be private too
  
  Seller();
  Seller(int);
  void item_entry(int item_id,float price);
  int login();
  void register_func();
};
#endif //SELLER
