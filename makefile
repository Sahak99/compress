compr : main.o Program.o Compress.o
	g++-11 main.o Program.o Compress.o -o compr -Wall -pedantic --std=c++20

main.o : main.cpp
	g++-11 -c main.cpp

Program.o : ./src/Program.cpp
	g++-11 -c ./src/Program.cpp

Compress.o : ./src/Compress.cpp
	g++-11 -c ./src/Compress.cpp

clean:
	rm *.o