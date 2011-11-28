#include "item.h"
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<vector>

using namespace std;

//function to split a string into parts based on a delimiter
std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
    while(std::getline(ss, item, delim)) {
      elems.push_back(item);
    }
    return elems;
}

//Member functions of item
set<Item> Item::getItems()
{
  //returns the set of items after reading them from items.list
  set<Item> allItems;
  ifstream fin("items.list");
  string line;

  while(getline(fin,line))
  {
    //read line by line and construct an item
    //the format of the file is : item_id seller_id starting_price
    vector<string> tokens = split(line,' ');
    int tmp_id,tmp_sid;
    float tmp_sp;
    tmp_id = atoi(tokens[0].c_str());
    tmp_sid = atoi(tokens[1].c_str());
    tmp_sp = atof(tokens[2].c_str());
    allItems.insert(Item(tmp_id,tmp_sid,tmp_sp));
  }

  return allItems;
}

string Item::bid_file_name()
{
  stringstream out;
  out << "bids/" << item_id << ".bid";
  return out.str();
}
