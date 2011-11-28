#ifndef ITEM_H
#define ITEM_H

#include<set>
#include<string>

class Item
{
      private:
              int item_id;
              int seller_id;
              float price;
              Item();
      public:
             Item(int i_id = 0, int s_id = 0, float p=0.0)
             :item_id(i_id),seller_id(s_id),price(p){};
             //Getters for the private data members
             int get_item_id()const
             {
               return item_id;
             }

             int get_seller_id()
             {
               return seller_id;
             }

             float get_price()
             {
               return price;
             }

  //overloaded < operator, this is needed for a set
  bool operator<(const Item& i)const
  {
    return item_id < i.get_item_id();
  }
  //overload == operator for comparision
  bool operator==(const Item& i)const
  {
    return item_id == i.get_item_id();
  }

  //other utility functions these will be defined in the items.cpp file
  static std::set<Item> getItems();
  std::string bid_file_name();

};
#endif
