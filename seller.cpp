#include<iostream>
#include<conio.h>
#include "auctioned_items.h"
#include "auction.h"
#define SIZE 100

using namespace std;

class SELLER
{
      public:
         void sell();
         void register_goods();
};


void SELLER :: register_goods()
{
     AUCTIONING_ITEM auction;
      auction.inputdata();
}

void SELLER :: sell()
{
}   

int main()
{
      SELLER sel;
      sel.register_goods();
      getch();
}
