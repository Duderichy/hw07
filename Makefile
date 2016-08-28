all: integrate.c integral_general.c
	gcc -Wall -I/usr/local/include integral_general.c integrate.c -o integrate.o
	gcc -L/usr/local/include -lgsl integrate.o -o a.out


clean :
	rm -f *.o
	rm -f *.*~
