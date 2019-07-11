main:main.o map.o
	g++ main.o map.o -o main
	rm *.o
main.o: main.cc
	g++ main.cc -c
map.o:map.cc map.o
	g++ map.cc -c
