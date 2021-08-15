main: main.o quantity.o
	g++ main.o quantity.o -o main
main.o: main.cpp quantity.h
	g++ -std=c++11 -c main.cpp -o main.o
quantity.o: quantity.h quantity.cpp
	g++ -std=c++11 -c quantity.cpp -o quantity.o
dich: main
	./main