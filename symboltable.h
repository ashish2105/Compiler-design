#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class SymbolTable {
    public:
  void insert(string x, string y);
  bool search(string x);
  string getvalue(string x);
   private:
	static map<string,string> o;	
};
