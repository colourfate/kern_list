obj=main.o

all: $(obj)
	gcc $(obj) -o main

list.o: list.c list.h
	gcc -c list.c

.PHONY: clean

clean:
	rm *.o list