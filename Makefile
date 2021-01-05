all: gameExec test
gameFiles: main.cpp cards.cpp cards.h
	g++ main.cpp cards.cpp -c 
gameExec: main.o cards.o
	g++ main.o cards.o -o game
tester: testcards.cpp cards.cpp cards.h testcards.h
	g++ testcards.cpp cards.cpp -c 
test: testcards.o cards.o
	g++ testcards.o cards.o -o test 
clean:
	rm game
