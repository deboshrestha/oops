#include<iostream>
#include<set>
#include "customer.h"
#include "item.h"

using namespace std;

int main()
{
  set<Item> items = Item::getItems();
  cout<<"Debo, this is the starting point for your code"<<endl;
  //create the customer
  //this should be done by the login module
  Customer customer("Debo",1001);

  char choice = 'n';
  do{

  cout<<"Enter the item id and the bidding price : ";
  int id_item,id_seller,id_customer;
  float new_bid_price;
  cin>>id_item>>new_bid_price;

  //we check if the item is valid
  set<Item>::iterator sit = items.find(Item(id_item));
  if( sit != items.end())
  {
     customer.bid(*sit,new_bid_price);
  }
  else
  {
    cout<<"Invalid Item"<<endl;
  }

  cout<<"Bid some more (y/n) ?? ";
  cin>>choice;
  }
  while(choice == 'y');

  return 0;
}
