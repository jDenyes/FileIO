# -*- MakeFile -*-

#target: dependencies
#	action

main: main.o jakeIO.o
	g++ main.o jakeIO.o -o basicPrint

main.o: main.cpp
	g++ -c main.cpp

jakeIO.o: jakeIO.cpp
	g++ -c jakeIO.cpp