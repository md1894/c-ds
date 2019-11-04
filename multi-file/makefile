output: main.o div.o
	g++ main.o div.o -o output

main.o: main.cpp
	g++ -c main.cpp

div.o:div.cpp div.h
	g++ -c div.cpp

clean:
	rm *.o output
