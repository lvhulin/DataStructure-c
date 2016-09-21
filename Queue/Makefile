obj = main.o queue.o

cc = gcc

main: $(obj)
	$(cc) -g -o main $(obj)

main.o: main.c queue.h
	$(cc) -g -c main.c

queue.o: queue.h
	$(cc) -g -c queue.c

.PYONY:clean

clean:
	-rm -rf $(obj) main