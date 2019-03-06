exe: merge_file.o driver.o ../exer1/merge.o
	gcc -o exe driver.o merge_file.o ../exer1/merge.o

driver.o: driver.c
	gcc -c -g driver.c

merge_file.o: merge_file.c merge_file.h
	gcc -c -g merge_file.c

run:
	./exe 10240.txt

clean:
	rm *.o && rm temp*.txt

debug:
	gdb --tui ./exe 10240.txt
