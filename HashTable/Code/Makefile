main : main.c simple_hashing.o
		gcc -o ../main main.c simple_hashing.o

simple_hashing.o : simple_hashing.c simple_hashing.h
		gcc -c simple_hashing.c -o simple_hashing.o

clean :
		rm *.o ../main
