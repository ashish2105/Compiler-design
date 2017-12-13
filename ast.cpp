// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
#  include <iostream>
#  include <math.h>
#  include <cstring>
#  include <iomanip>
#  include <stdlib.h>
#  include <string>
#  include <sstream>
#  include "symboltable.h"
#  include "tablemanager.h"
#  include "ast.h"
#  include<fstream>
using namespace std;

map<string,string> SymbolTable::o;
map<string,int> TableManager::o;
map<int,Ast*> Pvalue::o;

template <typename T>
std::string NumberToString(T ntos)
{
 stringstream ss;
 ss <<setprecision(17)<<ntos;
 return ss.str();
}

string Add::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
        int rv = tv + bv;
	output=NumberToString(rv);
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	double rv = tv + bv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}


string Sub::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
        int rv = tv - bv;
	output=NumberToString(rv);
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	double rv = tv - bv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}



string Mul::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
        int rv = tv * bv;
	output=NumberToString(rv);
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	double rv = tv * bv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}



string Divide::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
	if(bv==0){cout<<"Division by zero ignore any displayed answer";}
        else
	{
        int rv = tv / bv;
	int c=tv%bv;
	if (((tv<0&&bv>0)||(tv>0&&bv<0))&&(c!=0)){rv=rv-1;}
	output=NumberToString(rv);
        }
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	if(bv==0){cout<<"Division by zero ignore any displayed answer";}
        else
	{
        double rv = tv / bv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
	}
  }
  return output;
}


string Power::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
	if (bv<0)
	{float xv=atof(b.c_str());
	 float rv=pow(tv,xv);
	 output=NumberToString(rv);if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}	
	}
	else{
        int rv = pow(tv,bv);
	output=NumberToString(rv);}
	
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	double rv = pow(tv,bv);
        output=NumberToString(rv);if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}

string Dslash::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
	if(bv==0){cout<<"Division by zero ignore any displayed answer";}
	else{
        int rv = tv / bv;
        int c=tv%bv;
	if (((tv<0&&bv>0)||(tv>0&&bv<0))&&(c!=0)){rv=rv-1;}
	output=NumberToString(rv);
	}
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	if(bv==0){cout<<"Division by zero ignore any displayed answer";}
	else{
	int rv = int(tv / bv);
	double c=fmod(tv,bv);
	if (((tv<0&&bv>0)||(tv>0&&bv<0))&&(c!=0)){rv=rv-1;}
        output=NumberToString(rv);
	string a=".0";
	output.append(a);
	}
  }
  return output;
}

string Mod::eval() const
{
  string t=left->eval();
  string b=right->eval();
  string output;
  if(t.find(".")==std::string::npos && b.find(".")== std::string::npos)
  {
	int tv=atoi(t.c_str());
        int bv=atoi(b.c_str());
	if(bv==0){cout<<"mod by zero ignore any displayed answer";}
	else{
        int rv = tv % bv;
	if (((tv<0&&bv>0)||(tv>0&&bv<0))&&(rv!=0)){rv=rv+bv;}
	output=NumberToString(rv);
	}
  }
  else
  {
	double tv=atof(t.c_str());
        double bv=atof(b.c_str());
	if(bv==0){cout<<"mod by zero ignore any displayed answer";}
	else{
	double rv = fmod(tv,bv);
	if (((tv<0&&bv>0)||(tv>0&&bv<0))&&(rv!=0)){rv=rv+bv;}
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
	}
  }
  return output;
}

string Umin::eval() const
{
  string t=left->eval();
  string output;
  if(t.find(".")==std::string::npos)
  {
	int tv=atoi(t.c_str());
        int rv = -tv;
	output=NumberToString(rv);
  }
  else
  {
	double tv=atof(t.c_str());
	double rv = -tv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}

string Uplus::eval() const
{
  string t=left->eval();
  string output;
  if(t.find(".")==std::string::npos)
  {
	int tv=atoi(t.c_str());
        int rv = -tv;
	output=NumberToString(rv);
  }
  else
  {
	double tv=atof(t.c_str());
	double rv = +tv;
        output=NumberToString(rv);
	if(output.find(".")==std::string::npos){
	string a=".0";
	output.append(a);}
  }
  return output;
}


string compute(Ast *a) {
  string v = a->eval();
  if(v.find(".")!=std::string::npos)
  {
  int j=v.size();
   for (int i=0;i<j;i++)
	{
		if(v.back()=='0'){v.resize((v.size())-1);}
		else if(v.back()=='.'){v.append("0"); i=j;}
	}
	
  }
  return v;
}

void treeFree(Ast *a) {
  switch(a->Nodetype()) {
   // two subtrees
  case '+':
  case '-':
  case '^':
  case '*':
  case '/':
    treeFree(a->getRight());
   // one subtrees
  case 'M':
    treeFree(a->getLeft());
   //no subtree
  case 'K':
    delete a;
    break;
  default: std::cout << "internal error: bad node "
                << a->Nodetype() << std::endl;;
  }
}


