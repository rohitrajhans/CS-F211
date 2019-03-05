exe: List.o List.h main.o
	gcc -o exe main.o List.o

main.o: main.c
	gcc -c -g main.c
	
List.o: List.c 
	gcc -c -g List.c 

clean:
	rm *.o

run:
	./exe

debug:
	gdb --tui ./exe
