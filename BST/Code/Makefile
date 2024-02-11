main : main.c bst.o
		gcc -o ../main main.c bst.o

bst.o : bst.h bst.c
		gcc -c bst.c -o bst.o

clean :
		rm *.o ../main
