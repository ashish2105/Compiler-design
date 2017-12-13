#include "symboltable.h"

using namespace std;

  void SymbolTable::insert(string x, string y)
	{
		o[x]=y;
        }
  bool SymbolTable::search(string x)
	{
		map<string,string>::iterator it=o.find(x);
		if(it != o.end())
		return true;
		else return false;
	}
  string SymbolTable::getvalue(string x)
	{
		map<string,string>::iterator it=o.find(x);
		return (it->second);
		
	}

