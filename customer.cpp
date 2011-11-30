#include "customer.h"
#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

//temporary hack to avoid double definition
std::vector<std::string> split_string(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
    while(std::getline(ss, item, delim)) {
      elems.push_back(item);
    }
    return elems;
}
//done because of undefined reference error during linking
Customer::Customer(){
  int customer_id=0;
  int passwd=0;
}
 

Customer::Customer(int id)
  :customer_id(id){};
  
void Customer::register_func()
{
     cout<<"Enter the user id and password: \t";
     cin>>customer_id>>passwd;
     ofstream fout;
     fout.open("customer.list",ios::app);
     stringstream register_data;
     register_data <<customer_id <<" "<<passwd;
     fout << register_data.str()<<endl;
     fout.close();
     cout<<"Registration Successfull"<<endl;
}


int Customer::login()
{
     cout<<"Enter the user id and password: \t";
     cin>>customer_id>>passwd;
      ifstream fin("customer.list");
      string line;
      //to check if the file exists
        while(getline(fin,line))
        {
         //we need to see if the value is greater than the old bid price
         vector<string> tokens = split_string(line,' ');
         if( (atof(tokens[0].c_str()) == customer_id) && (atof(tokens[1].c_str()) == passwd) )
         {
             //write the updated bidding information
             cout<<"Log-in Successfull"<<endl;
             fin.close();
             return customer_id;
         }
      }
      fin.close();
      cout<<"log in unsuccessful\n";
      return 0;
}
 

void Customer::bid(Item i,float new_price)
{
  //we open the bid file for the given item
  //the file is stored as a text file in the bids directory
  ifstream fin(i.bid_file_name().c_str());
  ofstream fout;

  //to check if the file exists
  if (fin.good())
  {
    string line;
    getline(fin,line);
    fin.close();
    //we need to see if the value is greater than the old bid price
    vector<string> tokens = split_string(line,' ');
   if( (atof(tokens[0].c_str()) == i.get_item_id()) && (atof(tokens[2].c_str()) < new_price) )
   {
      //write the updated bidding information
      fout.open(i.bid_file_name().c_str());
      stringstream bid_data;
      bid_data << i.get_seller_id() <<" "<<customer_id <<" " <<new_price;
      fout << bid_data.str();
      fout.close();
      cout<<"Bid Successfully placed"<<endl;
    }
    else
    {
      cout<<"Somebody has outbid you"<<endl;
    }

  }
  else
  {
    //if the file doesn't exist then we come to this part
    //place the bid if the new_price is greater than the min price
    //i'm ommiting the logic for that but you must implement that
	
	//to check if the new_price is greater than min_price or not
	
		ifstream fin("items.list");
		string line;
		
		while(getline(fin,line))
		{
		
                //we need to see if the value is greater than the minimum item price
		         vector<string> tokens = split_string(line,' ');
		        if( (atoi(tokens[0].c_str()) == i.get_item_id()) && (atof(tokens[2].c_str()) < new_price) )
		         {
                         fout.open(i.bid_file_name().c_str());
			             stringstream bid_data;
			             bid_data << i.get_seller_id() <<" "<<customer_id <<" " <<new_price;
			             fout << bid_data.str();
			             fout.close();
			             cout<<"Bid Successfully placed"<<endl;
	               }
                if ( (atof(tokens[0].c_str()) == i.get_item_id()) && (atof(tokens[2].c_str()) >= new_price) )
               {
                    cout<<"\nCannot place bid, please increase the amount";
               }

		       
           }
           fin.close();
                      
  }

		
}

    
void Customer::display_items()
{
    ifstream item_file("items.list");
    string line;
    while(getline(item_file,line))
    {
       cout<<line<<endl;
    }
    item_file.close();
}
