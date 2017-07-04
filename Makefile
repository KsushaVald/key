test: print_n.o test.c
		gcc test.c -o test print_n.o -lpthread -Wall
print_n.o: print_n.c lib.h
		gcc -c print_n.c
clean:
		rm print_n.o test.o


