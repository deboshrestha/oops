#include "user.h"
#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

void User::register_func(User obj)
{
	fstream outfile;
    outfile.open("REGISTER.DAT",ios::app|ios::out);
    fflush(stdin);
    cout<<"\n Enter name : ";
    cin>>obj.user_name;
    cout<<"\n Enter your email id : ";
    cin>>obj.email_id;
    cout<<"\n Enter the bank name : ";
    cin>>obj.bank;
    cout<<"\n Enter the user id : ";
    cin>>obj.userid;
    cout<<"\n Enter the password:";
    cin>>obj.passwd;
    outfile.write((char *)&u,sizeof(u));
    outfile.close();
}

