#include<iostream>
#include<set>
#include "customer.h"
#include "item.h"
#include "seller.h"
#include "user.h"
#include<fstream>

using namespace std;




int main()
{
  set<Item> items = Item::getItems();
 cout<<"Debo, this is the starting point for your code"<<endl;
  //create the customer
  //this should be done by the login module
  cout<<"Welcome to XYZ auction system\n";
  cout<<"Are you a seller or buyer, please specify(S or B) : \t";
  char ch;
  cin>>ch;
  system("cls");
  if(ch == 'S')
  {
    Seller obj;
	cout<<"\t MENU";
	cout<<"\n \t 1. registeration";
	cout<<"\n \t 2. log-in";
	int cho;
	cin>>cho;
	int id; 
                
	switch(cho)
	{
		case 1 : obj.register_func();
					break;
		case 2 :  id = obj.login();
					break;
	}
				if(id != 0)
				{
				   cout<<"\nmenu";
				   cout<<"1. Entering into the item list ";
				   cout<<"2. Checking the current status of a bid ";
				   cout<<"Enter your choice";
				   int ch;
				   cin>>ch;
				   switch(ch)
				   {
						case 1 :	
                                    Seller seller(id);
									cout<<"Enter the item id and the starting price of the item : ";
									int id_item;
									float start_price;
									cin>>id_item>>start_price;
									seller.item_entry(id_item,start_price);
										break;
				/*	case 2 :  cout<<"\nEnter the bid number :";
                              int bid_number;
                                 S.bid_chk(bid_number);
										break;*/
					}
				}
				else 
				{
				   cout<<"Log-in again with correct id and password ";
				}
	}
	
	else if (ch == 'C')
	{
         Customer obj;
		cout<<"\t MENU";
		cout<<"\n \t 1. registeration";
		cout<<"\n \t 2. log-in";
		int cho;
		cin>>cho;
	    int id;
		switch(cho)
		{
            case 1 : obj.register_func();
					break;
			case 2: 
                 id = obj.login();
					  break;
		}
		 if(id != 0)
		{
			cout<<"\nmenu";
			cout<<"1. display the item list ";
			cout<<"2. enter the bidding price ";
			cout<<"Enter your choice";
			int ch;
			cin>>ch;
			switch(ch)
			{
				/*case 1 : 
						break;*/
				case 2 : Customer customer(id);
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
								break;
			}
		}
					
}
else
    cout<<"do nothing";
  return 0;
}

	
		
		
				   
		
  
  
  
