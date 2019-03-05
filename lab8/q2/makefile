exe: main.o qsort.o qsort.h
	gcc -o exe main.o qsort.o

main.o: main.c
	gcc -c -g main.c

qsort.o: qsort.c
	gcc -c -g qsort.c

run:
	./exe Input.txt

clean:
	rm *.o

debug:
	gdb --tui ./exe Input.txt