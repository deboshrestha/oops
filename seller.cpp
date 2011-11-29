#include "seller.h"
#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


Seller::Seller(string n,int id)
  :seller_id(id){};

void Seller::item_entry(int item_id,float new_price)
{
	ofstream fout;
	fout.open("items.list",ios::app);
	stringstream item_data;
	item_data<<item_id<<" "<<seller_id<<" "<<" "<<new_price;
	fout<< item_data.str()<endl;
	fout.close();
}

int Seller::login(Seller S)
{
	ifstream infile;
    infile.open("REGISTER.DAT");
    int id;
	string pwd;
    cout<<"enter user id:";
    cin>>name;
    cout<<"enter password:";
    cin>>pwd;
    while(infile.read((char *)&S,sizeof(S)))
    {
        if(!(strcmp(name,userid)||strcmp(pwd,passwd)))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
	{
        cout<<"login successful!!!";
		return 1;
	}
    else
	{
        cout<<"login failed!!!";
		return 0;
	}
        infile.close();
}
