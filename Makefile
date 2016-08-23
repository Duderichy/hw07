all: calc.c 
	gcc calc.c -o calc.o

clean :
	rm -f *.o
	rm -f *.*~

