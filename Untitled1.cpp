struct bid
{
       int item;
       float price;
       int user;
}arr[10];

/*
void CUSTOMER::buy2()
{
     int i=0;
     int flag = 0;
     cout<<"\nEnter the value for item:";
     cin>>itemd;
     cout<<"\nEnter the bidding value:";
     cin>>priced;
     cout<<"\nEnter the user id:";
     cin>>userd;
     CUSTOMER obj;
     obj.putdata();
     ifstream file1;
     fstream file2;
     file1.open("BID.DAT");
     while(file1.read((char *)&(arr[++i]),sizeof(struct bid)));
     file1.close();
     for(int j=1;j<=i;j++)
     {
             if(itemd == arr[j].item)
             {
               if(priced > arr[j].price)
               {
                 arr[j].price = priced;
                 arr[j].user = userd;
              }
              flag =1 ;
              break;
               
             }
     }
    if(flag==0)
    {
       ++i;
       arr[i].item = itemd;
       arr[i].price = priced;
       arr[i].user = userd;
    }
    
    file2.open("BID.DAT", ios::app | ios::out);
    for(int j=1;j<=i;j++)
    {
            file2.write((char *)&(arr[j]),sizeof(struct bid));
    }
    
   file2.close();  
}

*/
