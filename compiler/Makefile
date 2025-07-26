CXX = g++
CC = gcc

.PHONY: all clean

all: matchac

matchac: parser/lex.yy.c parser/matcha.tab.c main.cpp
	$(CC) -c parser/ast.c -o parser/ast.o
	$(CXX) -c main.cpp -o main.o
	$(CC) -c parser/matcha.tab.c -o parser/matcha.tab.o
	$(CC) -c parser/lex.yy.c -o parser/lex.yy.o
	$(CXX) -o matchac main.o parser/ast.o parser/matcha.tab.o parser/lex.yy.o

parser/matcha.tab.c parser/matcha.tab.h: parser/matcha.y
	bison  -d parser/matcha.y -o parser/matcha.tab.c

parser/lex.yy.c: parser/matcha.l parser/matcha.tab.h
	flex -o parser/lex.yy.c parser/matcha.l

clean:
	rm -f matchac main.o parser/*.o parser/lex.yy.c parser/matcha.tab.c parser/matcha.tab.h