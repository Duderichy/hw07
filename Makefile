all: integrate.c integral_general.c
	gcc -Wall -I/usr/local/include -c integral_general.c integrate.c
	gcc -L/usr/local/lib -lgsl integrate.o integral_general.o -o integration.o

clean :
	rm -f *.o
	rm -f *.*~
