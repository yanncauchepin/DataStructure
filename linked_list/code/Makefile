main : main.c linked_list.o
		gcc -o ../main main.c linked_list.o

linked_list.o : linked_list.h linked_list.c
		gcc -c linked_list.c -o linked_list.o

clean :
		rm *.o ../main
