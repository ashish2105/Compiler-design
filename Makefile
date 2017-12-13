CCC = clang++
LEX = flex
YACC = bison
CFLAGS = -Wall -std=c++11 
LEXFLAGS = -Wno-unused

#LEXDEBUG = -d
LEXDEBUG =
YACCDEBUG = -vtd -Wno

OBJS = main.o symboltable.o tablemanager.o ast.o parse.tab.o lex.yy.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp parse.y scan.l parse.tab.cpp lex.yy.cpp symboltable.o tablemanager.o
	$(CCC) $(CFLAGS) -c main.cpp

symboltable.o: symboltable.cpp symboltable.h
	$(CCC) $(CFLAGS) -c symboltable.cpp

tablemanager.o: tablemanager.cpp tablemanager.h
	$(CCC) $(CFLAGS) -c tablemanager.cpp

ast.o: ast.cpp ast.h symboltable.h tablemanager.h
	$(CCC) $(CFLAGS) -c ast.cpp

parse.tab.cpp: parse.y ast.h symboltable.h
	$(YACC) -o parse.tab.cpp $(YACCDEBUG) parse.y

parse.tab.o: parse.tab.cpp
	$(CCC) $(CFLAGS) -c parse.tab.cpp

lex.yy.cpp: scan.l parse.tab.o
	$(LEX) -o lex.yy.cpp $(LEXDEBUG) scan.l

lex.yy.o: lex.yy.cpp
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.cpp
	
clean:
	rm -f run *.o main.o symboltable.o ast.o parse.tab.cpp lex.yy.cpp
	rm -f parse.tab.hpp
	rm -f parse.output
