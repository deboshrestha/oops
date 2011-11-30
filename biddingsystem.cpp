#include<iostream>
#include<set>
#include "customer.h"
#include "item.h"
#include "seller.h"
#include "user.h"
#include<fstream>
#include<exception>

using namespace std;




int main()
{
  try{  
	cout<<"Welcome to XYZ auction system\n";
	cout<<"Are you a seller or buyer, please specify(S or B) : \t";
	char ch;
	cin>>ch;

	if(ch == 'S')
	{
		Seller obj;
	    cout<<"\t MENU";
	    cout<<"\n \t 1. registeration";
	    cout<<"\n \t 2. log-in \n";
		cout<<"\n \t 3. HELP \n";
	    int cho;
	    cin>>cho;
	    int id ; 
		switch(cho)
			{
				case 1 : 	obj.register_func();
							id = obj.login();
					        break;
				case 2 :  	id = obj.login();
					        break;
				case 3:	throw string("Invalid option");
				              break;
			}
		if(id != 0)
		{         
			char choice = 'n';
            do{ 
                cout<<"\nMENU\n";
				cout<<" 1. Entering into the item list\n";
				
			    cout<<"Enter your choice";
				int ch;
				cin>>ch;
				switch(ch)
				{
					case 1 :	Seller seller(id);
								cout<<"Enter the item id and the starting price of the item : ";
								int id_item;
								float start_price;
								cin>>id_item>>start_price;
								seller.item_entry(id_item,start_price);
									break;
				/*	case 2 :	throw string("Invalid option");	
                    				break;*/
                        
				}
				cout<<"Want to enter more items(y/n)??\n";
				cin>>choice;
             }while(choice == 'y');
		}
				
	}

	else if (ch == 'B')
	{
        Customer obj;
		cout<<"\t MENU";
		cout<<"\n \t 1. registeration";
		cout<<"\n \t 2. log-in";
		cout<<"\n \t 3. HELP\n ";
	    
		int cho;
		cin>>cho;
	    int id;
		switch(cho)
		{
            case 1 : 	obj.register_func();
						id = obj.login();
						break;
			case 2: 
						id = obj.login();
						break;
			case 3:		throw string("Invalid option");
			          break;
        
		}
		if(id != 0)
		{  
            char chic = 'n';
            do
            {
			cout<<"\nmenu\n";
			cout<<"1. display the item list \n";
			cout<<"2. HELP\n";
			cout<<"3. enter the bidding price \n";
			
	    
			cout<<"Enter your choice \t";
			int ch;
			cin>>ch;
			char choice = 'n';
							
			switch(ch)
			{
				case 1 : 	obj.display_items();
							system("pause");
							break;
				case 2:	throw string("Invalid option");
				              break;
				case 3 : 	Customer customer(id);
							set<Item> items = Item::getItems();
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
	    cout<<"Enter 'y/n' to go back to previous menu\n";
		}while(chic=='y');
        }
					
	}

	else
		throw string("Invalid option");
}
		
catch(...)
{
	string line;
	ifstream help_doc("auction.help");
    while(getline(help_doc,line))
    {
      cout<<line<<endl;
    }
    system("pause");
    help_doc.close();
  }

        
  return 0;
}
