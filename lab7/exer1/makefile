exe: driver.o sort.o stack.o employee.o sort.h stack.h employee.h
	gcc -o exe driver.o sort.o stack.o employee.o

driver.o: driver.c
	gcc -c -g driver.c

stack.o: stack.c
	gcc -c -g stack.c

sort.o: sort.c
	gcc -c -g sort.c

driver.o: driver.c
	gcc -c -g driver.c

run:
	./exe

clean:
	rm *.o

debug:
	gdb --tui ./exe