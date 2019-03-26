exe: main.o hash.o parser.o
	gcc -o exe main.o hash.o parser.o

hash.o: hash.h hash.c
	gcc -c hash.c

parser.o: parser.h parser.c
	gcc -c parser.c

main.o: main.c
	gcc -c main.c

run:
	./exe

clean:
	rm -rf *.o

debug:
	gdb ./exe