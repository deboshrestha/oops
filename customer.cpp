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

Customer::Customer(string n,int id)
  :customer_name(n),customer_id(id){};

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
    if( atof(tokens[2].c_str()) < new_price )
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
    fin.close();
    fout.open(i.bid_file_name().c_str());
    stringstream bid_data;
    bid_data << i.get_seller_id() <<" "<<customer_id <<" " <<new_price;
    fout << bid_data.str();
    fout.close();
    cout<<"Bid Successfully placed"<<endl;
  }
}
