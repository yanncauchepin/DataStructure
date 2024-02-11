main : main.c bst_matrix.o yale_matrix.o
		gcc -o ../main main.c bst_matrix.o yale_matrix.o

yale_matrix.o : yale_matrix.c yale_matrix.h bst_matrix.o
		gcc -c yale_matrix.c -o yale_matrix.o

bst_matrix.o : bst_matrix.c bst_matrix.h
		gcc -c bst_matrix.c -o bst_matrix.o

clean :
		rm *.o ../main
