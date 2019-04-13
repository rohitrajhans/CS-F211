exe: main.o tree.o
	gcc -o exe main.o tree.o

main.o: main.c
	gcc -c -g main.c

tree.o: tree.c
	gcc -c -g tree.c

run:
	./exe

clean:
	rm *.o

debug:
	gdb --tui ./exe
