all: strings

strings: main.o mypilha.o mystring.o
	gcc	main.o mypilha.o mystring.o -o strings

main.o: main.c
	gcc -c main.c

mypilha.o: mypilha.c
	gcc -c mypilha.c

mystring.o: mystring.c
	gcc -c mystring.c

clean: 
	rm -rf *o *exe *gch strings
