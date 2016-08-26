all: integrate.c
	gcc integrate.c -o integrate.o

clean :
	rm -f *.o
	rm -f *.*~
