# Project: BiddingSystem

all: customer.o item.o biddingsystem.o
	g++ item.o customer.o biddingsystem.o -o BiddingSystem.exe

customer.o: customer.cpp
	g++ -c customer.cpp

biddingsystem.o: biddingsystem.cpp
	g++ -c biddingsystem.cpp

item.o: item.h item.cpp
	g++ -c item.cpp

