exe : mergedriver.o merge.o merge.h
	gcc -o exe mergedriver.o merge.o

mergedriver.o: mergedriver.c
	gcc -c -g mergedriver.c

merge.o: merge.c
	gcc -c -g merge.c

run:
	./exe 1024.txt

clean:
	rm *.o

debug:
	gdb --tui ./exe