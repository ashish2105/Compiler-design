#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
class Ast;
class TableManager {
    public:
  void insert(string x, int y)
	{
		//cout<<"entered"<<endl;
		o[x]=y;
		//map<string,int>::iterator it=o.find(x);
		//if(it != o.end())
		//cout<<"scope value "<<it->first<<" is "<<it->second<<endl;
        }
  int getvalue(string x)
	{
		map<string,int>::iterator it=o.find(x);
		return (it->second);

	}
  bool search(string x)
	{
		map<string,int>::iterator it=o.find(x);
		if(it != o.end())
		return true;
		else return false;
	}
   private:
	static map<string,int> o;	
};

class Pvalue {
    public:
  void insert(int x, Ast* y)
	{
		o[x]=y;
		//map<int,Ast*>::iterator it=o.find(x);
		//if(it != o.end())
		//cout<<"scope value cc"<<it->first<<"  "<<it->second;
        }
  Ast* getvalue(int x)
	{
		map<int,Ast*>::iterator it=o.find(x);
		return (it->second);
	}
  bool search(int x)
	{
		map<int,Ast*>::iterator it=o.find(x);
		if(it != o.end())
		return true;
		else return false;
	}

   private:
	static map<int,Ast*> o;	
};
