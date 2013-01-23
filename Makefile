all: strings

strings: main.o mypilha.o mystring.o
	gcc	main.o -o strings

main.o: main.c
	gcc -c main.c

mypilha.o: mypilha.h
	gcc -c mypilha.h

mystring.o: mystring.h
	gcc -c mystring.h

clean: 
	rm -rf *o strings
