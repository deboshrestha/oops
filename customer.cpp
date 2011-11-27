#include<iostream>
#include<conio.h>
#include<fstream>
#include "auctioned_items.h"
#include<iomanip>
#include "auction.h"
#define SIZE 100

using namespace std;

struct bid
{
       int item;
       float price;
       int user;
}arr[10];

class CUSTOMER
{
      private:
              int itemd;
              float priced;
              char userd[10];
      public:
         void buy();
         void bid();
         void buy2();
         void display_items();
         void putdata();
};

void CUSTOMER::display_items()
{
     AUCTIONING_ITEM auc;
     auc.outputdata();
}
/*
void CUSTOMER::buy2()
{
     int i=0;
     int flag = 0;
     cout<<"\nEnter the value for item:";
     cin>>itemd;
     cout<<"\nEnter the bidding value:";
     cin>>priced;
     cout<<"\nEnter the user id:";
     cin>>userd;
     CUSTOMER obj;
     obj.putdata();
     ifstream file1;
     fstream file2;
     file1.open("BID.DAT");
     while(file1.read((char *)&(arr[++i]),sizeof(struct bid)));
     file1.close();
     for(int j=1;j<=i;j++)
     {
             if(itemd == arr[j].item)
             {
               if(priced > arr[j].price)
               {
                 arr[j].price = priced;
                 arr[j].user = userd;
              }
              flag =1 ;
              break;
               
             }
     }
    if(flag==0)
    {
       ++i;
       arr[i].item = itemd;
       arr[i].price = priced;
       arr[i].user = userd;
    }
    
    file2.open("BID.DAT", ios::app | ios::out);
    for(int j=1;j<=i;j++)
    {
            file2.write((char *)&(arr[j]),sizeof(struct bid));
    }
    
   file2.close();  
}

*/

void CUSTOMER::bid()
{
     fstream outfile;
     ifstream infile;
     int loc,end;
     CUSTOMER obj;
     obj.putdata();
     int flag=0;
     infile.open("BID.DAT");
     
     fflush(stdin);
      cout<<"Enter your id : \t";
     cin.getline(userd, SIZE);
     cout<<"\nEnter the item id you want to place a bid for : \t";
     cin>>itemd;
     cout<<"\nEnter the price you want to place the bid for :\t";
     cin>>priced;
      while(infile.read((char *)&obj,sizeof(obj)))
      {
           if(obj.itemd == itemd)
           {
                flag=1;
                break;
           }
      }
      loc = infile.tellg();
      cout<<"current pos:"<<loc;
      infile.seekg(0,ios::end);
      end = infile.tellg();
      cout<<"end of file:"<<end;
      infile.close();
      if(flag==1)
      {
                 if( obj.priced < priced)
                 {    
                      outfile.open("BID.DAT",ios::out| ios::app|ios::ate|ios::binary);
                      cout<<"\n"<<loc-sizeof(CUSTOMER);
                      outfile.seekp(loc-sizeof(CUSTOMER));
                      cout<<"\n"<<outfile.tellp();
                      outfile.write((char *)this,sizeof(*this));
                      outfile.close();
                 }
      }
      else
      {
          outfile.open("BID.DAT",ios::out| ios::app);
          outfile.write((char *)this,sizeof(*this));
          outfile.close();

      }          
          //  infile.close(); 
             obj.putdata();     
}
void CUSTOMER:: putdata(void)
             {
                  ifstream infile;
                  infile.open("BID.DAT");
                  while(infile.read((char *)this,sizeof(*this)))
                  {
                  cout<<"\nUSER id : "<<userd;
                  cout<<"\nItem id : "<<itemd;
                  cout<<"\nprice : "<<priced;
                  }
                  infile.close();
             }
             
     
int main()
{
    CUSTOMER cust;
    int op;
    while(1){
    cout<<"\n Welcome customer, these are your options : \n";
    cout<<"\n 1. CHECK AVAILABLE ITEMS IN THE AUCTION SYSTEM . \n";
    cout<<"\n 2. PLACE A BID FOR ONE SPECIFIC ITEM .\n";
    cout<<"\n 3. EXIT. \n";
    cin>>op;
             switch(op)
             {
                case 1: cust.display_items();
                  break;
                 case 2: cust.bid();
                  break;
                 case 3: exit(0);
                      break;
                 default : cout<<"\n Invalid option";
             }
    }
    getch();
}
