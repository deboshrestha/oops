#include "seller.h"
#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

//temporary hack to avoid double definition
std::vector<std::string> split_string_str(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
    while(std::getline(ss, item, delim)) {
      elems.push_back(item);
    }
    return elems;
}

//how on earth can this be a constructor? you have defined one in your header file that takes one argument and
//written the bdy for something that takes two arguments
Seller::Seller(){  seller_id = 0; passwd = 0;}
Seller::Seller(int id)
  :seller_id(id){};
  
  

void Seller::register_func()
{
     cout<<"Enter the user id and password: \t";
     cin>>seller_id>>passwd;
     ofstream fout;
     fout.open("seller.list",ios::app);
     stringstream register_data;
     register_data <<seller_id <<" "<<passwd;
     fout << register_data.str()<<endl;
     fout.close();
     cout<<"Registration Successfull"<<endl;
}


int Seller::login()
{
     cout<<"Enter the user id and password: \t";
     cin>>seller_id>>passwd;
      ifstream fin("seller.list");
      string line;
      //to check if the file exists
        while(getline(fin,line))
        {
         //we need to see if the value is greater than the old bid price
         vector<string> tokens = split_string_str(line,' ');
         if( (atof(tokens[0].c_str()) == seller_id) && (atof(tokens[1].c_str()) == passwd) )
         {
             //write the updated bidding information
             cout<<"Log-in Successfull"<<endl;
             fin.close();
             return seller_id;
         }
      }
      fin.close();
      cout<<"log in unsuccessful\n";
      return 0;
}
 

void Seller::item_entry(int item_id, float start_price)
{
		ifstream fin;
		fin.open("items.list");
		string line;
		int flag = 0; //had to use flag cudnt come up with better logic
        while(getline(fin,line))
        {
                vector<string> tokens = split_string_str(line,' ');
		        if( (atoi(tokens[0].c_str()) == item_id) )
		         {
                 
                      cout<<"\nItem already exists, enter a new one";
                      flag =1;
                      
                 }
          }
                 
           
           if(flag==0)
           {
               ofstream fout;
               fout.open("items.list",ios::app);
               stringstream item_data;
               item_data <<item_id <<" "<<seller_id <<" " <<start_price;
               fout << item_data.str()<<endl;
               fout.close();
               cout<<"Item Successfully entered"<<endl;
           }
           fin.close();
           
}
/*
void Seller::display_items()
{
    ifstream item_file("items.list");
    string line;
    while(getline(item_file,line))
    {
       cout<<line<<endl;
    }
    item_file.close();
}
  */   
//can a


