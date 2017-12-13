//  Declarations for an AST calculator
//  From "flex & bison", fb3-1, by John Levine
//  Adapted by Brian Malloy


#include <string.h>
#include <sstream>
//#include "symbol.h"
extern void yyerror(const char*);
extern void yyerror(const char*, const char);
extern int scope;
using namespace std;

class Ast {
public:
  virtual ~Ast() {}
  virtual string eval() const=0;
  virtual Ast* getLeft() const { throw std::string("No Left"); }
  virtual Ast* getRight() const { throw std::string("No Right"); }
  virtual string getNumber() const { throw std::string("No Number"); }
  virtual string getName() const { throw std::string("No Name"); }
  virtual char Nodetype()const=0;
};




class Number : public Ast {
public:
  Number(char* n) :number(n) {} 
  virtual ~Number() {}
  virtual string eval() const {return number; }
  virtual string getNumber() const { return number; }
  virtual char Nodetype()const{return 'K';}
private:
  char* number;
};

class Name : public Ast {
public:
  Name(char* n) :name(n) {}
  virtual ~Name() {}
  virtual string eval() const {
	SymbolTable s;
	string xst=name;
	if(scope==0)
	{
	xst=xst+"0";
	bool y=s.search(xst);
	if (y==true){return (s.getvalue(xst));} else {cout<<"variable not declared ignore any displayed value"<<endl; return "\0"; }
	} 
	else
	{
	stringstream ss;
        ss<<scope;
	string mxt=xst+ss.str();
	//cout<<"search value="<<mxt<<endl;
	bool y=s.search(mxt);
	if (y==true) {return (s.getvalue(mxt));}
	else
	{
	xst=xst+"0";
	bool x=s.search(xst);
	if (x==true){return (s.getvalue(xst));} else {cout<<"variable not declared ignore any displayed value"<<endl;return "\0";  }
	}
	}	
   
        }
 virtual string getName() const {return name; }
  virtual char Nodetype()const{return 'K';}
  private:
   char* name;
};

class Print : public Ast {
public:
  Print( Ast* v):pvar(v)  {}
  virtual ~Print() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return pvar; }
  virtual char Nodetype()const{return '+';}
private:
  Ast *pvar;
};

class Add : public Ast {
public:
  Add( Ast* l, Ast* r):left(l), right(r)  {}
  virtual ~Add() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype()const{return '+';}
private:
  Ast *left;
  Ast *right;
};


class Sub : public Ast {
public:
  Sub( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Sub() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '-';}
private:
  Ast *left;
  Ast *right;
};


class Mul : public Ast {
public:
  Mul( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Mul() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '*';}
private:
  Ast *left;
  Ast *right;
};


class Divide : public Ast {
public:
  Divide( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Divide() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '/';}
private:
  Ast *left;
  Ast *right;
};


class Power : public Ast {
public:
  Power( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Power() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '^';}
private:
  Ast *left;
  Ast *right;
};

class Umin : public Ast {
public:
  Umin( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Umin() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return 'M';}
private:
  Ast *left;
  Ast *right;
};

class Uplus : public Ast {
public:
  Uplus( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Uplus() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return 'M';}
private:
  Ast *left;
  Ast *right;
};

class Mod : public Ast {
public:
  Mod( Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Mod() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '-';}
private:
  Ast *left;
  Ast *right;
};

class Dslash : public Ast {
public:
  Dslash (Ast* l, Ast* r) :left(l), right(r){}
  virtual ~Dslash() {}
  virtual string eval() const;
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual char Nodetype() const{return '-';}
private:
  Ast *left;
  Ast *right;
};
string call(char* a);
string compute(Ast *a);
void treeFree(Ast *a);

