obj = main.o list.o


cc = gcc

main: $(obj)
	$(cc) -g -o main  $(obj)
	
main.o: main.c list.h
	$(cc) -g -c main.c

list.o: list.h
	$(cc) -g -c list.c

.PHONY: clean

clean:
	-rm -rf $(obj) main
