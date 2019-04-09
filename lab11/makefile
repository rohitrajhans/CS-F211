exe: main.o driver.o tree.o
	gcc -o exe main.o driver.o tree.o

main.o: main.c
	gcc -c -g main.c

driver.o: driver.c
	gcc -c -g driver.c

tree.o: tree.c
	gcc -c -g tree.c

run:
	./exe

clean:
	rm *.o

debug:
	gdb --tui ./exe
