Run: main.o Internal.o
	g++ -o Run main.o Internal.o

main.o: main.cpp
	g++ -c main.cpp

Internal.o: Internal.cpp
	g++ -c Internal.cpp

clean:
	rm Run main.o Internal.o