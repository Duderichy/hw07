all: integrate.c integral_general.c
	gcc -Wall -I/usr/local/include -c integral_general.c integrate.c adjust.c timer.c
	gcc -L/usr/local/lib -lgsl integrate.o timer.o adjust.o integral_general.o -o integration.o

clean :
	rm -f *.o
	rm -f *.*~
