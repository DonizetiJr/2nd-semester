all: clean item.o listaligada.o utils.o main.o compile clean 

compile: 
	gcc -o gerenciamento listaligada.o utils.o item.o main.o

main.o:
	gcc -c ./src/main.c -I./include

utils.o:
	gcc -c ./src/utils.c -I./include

listaligada.o:
	gcc -c ./src/listaligada.c -I./include

item.o:
	gcc -c ./src/item.c -I./include

clean:
	find -name '*~'  | xargs rm -rf {}
	find -name '*.o' | xargs rm -rf {}

run:
	./gerenciamento

zip:
	zip -r gerenciamento ./src/*.c ./include/*.h Makefile
