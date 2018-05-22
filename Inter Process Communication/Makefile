all : Run

Run : utilities.h main.o
	gcc main.o -o Run

main.o : main.c clientInit.o serverInit.o
	gcc -c -Wall main.c

clientInit.o :
	gcc -Wall client.c -o clientInit

serverInit.o :
	gcc -Wall server.c -o serverInit

clean:
	rm -rf *.o Run *Init*
