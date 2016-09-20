obj = main.o stack.o

cc = gcc

main:$(obj)
	$(cc) -g -o main $(obj)

main.o:main.c stack.h 
	$(cc) -g -c main.c

stack.o:stack.h
	$(cc) -g -c stack.c

.PHONY:clean

clean:
	-rm -rf $(obj) main 