all: integrate.c integral_general.c
	gcc integrate.c -I/usr/local/inlcude integral_general.c -o integrate.o

clean :
	rm -f *.o
	rm -f *.*~
