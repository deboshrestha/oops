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
	fstream outfile;
    outfile.open("REGISTER.TXT",ios::app|ios::out);
    fflush(stdin);
    cout<<"\n Enter name : ";
    cin>>customer_name;
    cout<<"\n Enter the user id : ";
    cin>>customer_id;
    cout<<"\n Enter the password:";
    cin>>passwd;
    outfile.write((char *)this,sizeof(*this));
    outfile.close();
}

//I 
int Customer::login()
{
    ifstream infile;
    infile.open("REGISTER.TXT");
    int user_id;
	int pwd;
    cout<<"enter user id:";
    cin>>user_id;
    cout<<"enter password:";
    cin>>pwd;
    int flag = 0;
    while(infile.read((char *)this,sizeof(*this)))
    {
        if(user_id == customer_id && passwd == pwd)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
	{
        cout<<"login successful!!!";
		return user_id;
	}
    else
	{
        cout<<"login failed!!!";
		return 0;
	}
        infile.close();
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
	
		ifstream fin(i.item_file_name().c_str());
		string line;
		getline(fin,line);
		fin.close();
		//we need to see if the value is greater than the minimum item price
		vector<string> tokens = split_string(line,' ');
		if( (atof(tokens[0].c_str()) == i.get_item_id()) && (atof(tokens[2].c_str()) < new_price) )
		{
      
			fout.open(i.bid_file_name().c_str());
			stringstream bid_data;
			bid_data << i.get_seller_id() <<" "<<customer_id <<" " <<new_price;
			fout << bid_data.str();
			fout.close();
			cout<<"Bid Successfully placed"<<endl;
		}
		else
		{
		cout<<"Enter a new price for the bid"<<endl;
		}
	}
}
