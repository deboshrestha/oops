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
    
   cout<<"Debo, this is the starting point for your code"<<endl;
  //create the customer
  //this should be done by the login module
  cout<<"Welcome to XYZ auction system\n";
  cout<<"Are you a seller or buyer, please specify(S or B) : \t";
  char ch;
  cin>>ch;
  //system("cls");


 if(ch == 'S')
  {
        //you cant do this makes no sense sell has to be intitalized with an id
        Seller obj;
	    cout<<"\t MENU";
	    cout<<"\n \t 1. registeration";
	    cout<<"\n \t 2. log-in \n";
	    int cho;
	    cin>>cho;
	    //this makes no sense to me
	    int id ; 
          //you have to do something with id, it will mot magically get a value      
	            switch(cho)
	            {
                           case 1 : obj.register_func();
                                    id = obj.login();
					            break;
		                   case 2 :  id = obj.login();
					            break;
                    }
	//you use id before initializing it ofcourse there'll be errors
	//and why call the seller with the id 0
	//that was the whole point of disabling the default constructor
	         // id = obj.login();
				if(id != 0)
				{//you check for id first and then initialize it not very logically coherent at all
				
                      
                      //you chefor id here it is never initialized let it be 0 for the time being but later you need to fix it
                      //go on
                     char choice = 'n';
                     do{ 
                      cout<<"\nMENU\n";
				      cout<<" 1. Entering into the item list ";
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
                        
					  }
					  cout<<"Want to enter more items(y/n)??\n";
					  cin>>choice;
                    }while(choice == 'y');
				}
				
	}

	//please dont be a kanjoos with comments

	//this is absurd ch is declared in a different scope 
	//ther is a difference between cho and choice the ch ch is int for one conditions arent nested clearly
	 if (ch == 'B')
	{
         Customer obj;
		cout<<"\t MENU";
		cout<<"\n \t 1. registeration";
		cout<<"\n \t 2. log-in\n";
		int cho;
		cin>>cho;
	    int id;
		switch(cho)
		{
            case 1 : obj.register_func();
                     obj.login();
					break;
			case 2: 
                 id = obj.login();
					  break;
		}
	//	id = obj.login();
		 if(id != 0)
		{
			cout<<"\nmenu\n";
			cout<<"1. display the item list \n ";
			cout<<"2. enter the bidding price \n";
			cout<<"Enter your choice";
			int ch;
			cin>>ch;
			switch(ch)
			{
				case 1 : obj.display_items();
				         system("pause");
						break;
				case 2 : Customer customer(id);
				         set<Item> items = Item::getItems();
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
    exit(0);

  return 0;
}
