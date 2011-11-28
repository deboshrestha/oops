#include<iostream>
#include<string>
#include<fstream>
#include "auctioned_items.h"
#include<iomanip>
#include "auction.h"
#define SIZE 100

using namespace std;

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

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

void CUSTOMER::bid()
{
	ifstream fin;
	ofstream fout;
	
	int item_id;
	char user_id[80];
	float price_id;
	cout<<"item user price"<<endl;
	cin>>item_id>>user_id>>price_id;
	fin.open("bid.dat",ios::in);
	fout.open("tmp.dat",ios::out);
	CUSTOMER object,t_obj;
	strcpy(object.userd,user_id);
	object.priced = price_id;
	object.itemd = item_id;
	cout<<object.itemd<<endl;
	system("pause");
	//check if the file is empty as it will be the first time
	if( is_empty(fin) )
	{
        cout<<"New file found";
        fout.write((char*)&object,sizeof(object));
    }
    
	while(!fin.eof())
	{
		fin.read((char*)&t_obj,sizeof(t_obj));
		if( object.itemd == t_obj.itemd && object.priced > t_obj.priced )
		{
			fout.write((char*)&object,sizeof(object));
		}
		string tmp;
		cout<<"I just wrote "<<t_obj.itemd<<endl;
		fout.write((char*)&t_obj,sizeof(t_obj));
	}
	fin.close();
	fout.close();
	
	//copy tmp into bid
	system("move tmp.dat bid.dat");
	this->putdata();
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
}
