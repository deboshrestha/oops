#ifndef AUCTIONING_ITEM_H
#define AUCTIONING_ITEM_H

class AUCTIONING_ITEM
{
      int item_id;
      int seller_id;
      char category[30];
      char item_name[30];
      float max_price;
      float actual_price;
      float start_price;
      char item_attr[100];
      
      public:
             void inputdata();
             void outputdata();
};
#endif
      
