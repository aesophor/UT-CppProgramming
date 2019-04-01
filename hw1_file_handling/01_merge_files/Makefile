CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall
SRC=$(wildcard *.cc)
BIN=main

all:
	make $(BIN)

%: %.cc
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm $(BIN) ccc.txt

run:
	./main
