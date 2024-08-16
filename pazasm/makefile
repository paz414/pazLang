CFLAGS=-std=c++11

all: pazasm

pazasm: pazasm.o lexer.o
	g++ $(CFLAGS) pazasm.o lexer.o -o $@

lexer.o: lexer.h lexer.cpp
	g++ $(CFLAGS) -c lexer.cpp

pazasm.o: pazasm.cpp lexer.h
	g++ $(CFLAGS) -c pazasm.cpp

clean:
	rm -f pazasm *.o *.bin 

