#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream ifile("ifile.txt",std::ios::binary);
	ifile.seekg(0,std::ios_base::end);
	long s=ifile.tellg();
	char *buffer=new char[s];
	ifile.seekg(0);
	ifile.read(buffer,s);
	ifile.close();
	std::string txt(buffer,s);
	delete[] buffer;
	size_t off=0;
	while ((off=txt.find("lol",off))!=std::string::npos)
		txt.replace(off,sizeof("lol")-1,"roffles");
	std::ofstream ofile("ofile.txt");
	ofile.write(txt.c_str(),txt.size());
	return 0;
}
