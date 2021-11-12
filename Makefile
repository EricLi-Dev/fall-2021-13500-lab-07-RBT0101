main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ -c -std=c++11 main.cpp

indent.o: indent.cpp indent.h unindent.h
	g++ -c -std=c++11 indent.cpp

unindent.o: unindent.cpp unindent.h
	g++ -c -std=c++11 unindent.cpp

clean:
	rm -f main.o unindent.o indent.o
