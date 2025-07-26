CXX = g++
CC = gcc

# Флаги компиляции
CFLAGS = -Wall
CXXFLAGS = -Wall
DEBUG_CFLAGS = -Wall -g -O0
DEBUG_CXXFLAGS = -Wall -g -O0

.PHONY: all debug clean

all: CFLAGS := $(CFLAGS)
all: CXXFLAGS := $(CXXFLAGS)
all: matchac

debug: CFLAGS := $(DEBUG_CFLAGS)
debug: CXXFLAGS := $(DEBUG_CXXFLAGS)
debug: matchac

matchac: parser/lex.yy.c parser/matcha.tab.c main.cpp
	$(CC) $(CFLAGS) -c parser/ast.c -o parser/ast.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c parser/matcha.tab.c -o parser/matcha.tab.o
	$(CC) $(CFLAGS) -c parser/lex.yy.c -o parser/lex.yy.o
	$(CXX) $(CXXFLAGS) -o matchac main.o parser/ast.o parser/matcha.tab.o parser/lex.yy.o

parser/matcha.tab.c parser/matcha.tab.h: parser/matcha.y
	bison -d parser/matcha.y -o parser/matcha.tab.c

parser/lex.yy.c: parser/matcha.l parser/matcha.tab.h
	flex -o parser/lex.yy.c parser/matcha.l

clean:
	rm -f matchac main.o parser/*.o parser/lex.yy.c parser/matcha.tab.c parser/matcha.tab.h
