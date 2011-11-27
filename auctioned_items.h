#ifndef AUCTIONED_ITEMS_H
#define AUCTIONED_ITEMS_H

class AUCTIONED_ITEMS
{
      private:
        int item_id;
        int seller_id;
        int purchaser_id;
        char item_name;
        char auction_date;
        float start_price;
        float end_price;
        float avg_price_end;
        float avg_end_price_all;
        char category[30];
        //char item_attr[50];
};
#endif
