#include "auction.h"
#include<iostream>
#include<fstream>
#define SIZE 100 

using namespace std;

void AUCTIONING_ITEM :: inputdata()
{
      fstream outfile;
      outfile.open("ITEM.DAT",ios::app|ios::out);
      fflush(stdin);
      cout<<"\n Enter the id of the item : ";
      cin>>item_id;
      cout<<"\n Enter id of the seller :";
      cin>>seller_id;
      fflush(stdin);
      cout<<"\n Enter the category of the item : ";
      cin.getline(category,SIZE);
      cout<<"\n Enter the name of the item : ";
      cin.getline(item_name,SIZE);
      cout<<"\n Enter the maximum price of the item : ";
      cin>>max_price;
      cout<<"\n Enter the starting price for the auctioning :";
      cin>>start_price;
      cout<<"\n Enter the actual price of the item : ";
      cin>>actual_price;
      /*cout<<"\n Enter the details of the package : ";
      cin.getline(item_attr,SIZE);*/
      outfile.write((char *)this,sizeof(*this));
      outfile.close();
}

void AUCTIONING_ITEM :: outputdata()
{
     ifstream infile;
     infile.open("ITEM.DAT");
     while(infile.read((char *)this,sizeof(*this)))
     {
            cout<<"\nITEM ID : "<<item_id;
            cout<<"\nSELLER ID : "<<seller_id;
            cout<<"\nCATEGORY : "<<category;
            cout<<"\nITEM NAME : "<<item_name;
            cout<<"\nSTART PRICE : "<<start_price;
      }
      infile.close();
}
             


