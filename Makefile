all: calc.c recur.c
	gcc calc.c -o calc.o
	gcc recur.c -o recur.o

clean :
	rm -f *.o
	rm -f *.*~

