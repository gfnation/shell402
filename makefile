all: shell402 create list
shell402: shell402.o shellFunctions.o input.o
	gcc shell402.o shellFunctions.o input.o -o shell402
list: list.o
	gcc list.o -o list
create: create.o
	gcc create.o -o create
shell402.o: shell402.c
	gcc -c shell402.c
shellFunctions.o: shellFunctions.c
	gcc -c shellFunctions.c
input.o: input.c
	gcc -c input.c
list.o: list.c
	gcc -c list.c
create.o: create.c
	gcc -c create.c
clean:
	rm *.o