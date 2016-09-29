all: clean main.o item.o utils.o item.o pilha_dinamica.o compile clean 

compile: 
	gcc -o binario utils.o item.o pilha_dinamica.o main.o

pilha_dinamica.o:
	gcc -c ./src/pilha_dinamica.c -I./include

item.o:
	gcc -c ./src/item.c -I./include

main.o:
	gcc -c ./src/main.c -I./include

utils.o:
	gcc -c ./src/utils.c -I./include

clean:
	find -name '*~'  | xargs rm -rf {}
	find -name '*.o' | xargs rm -rf {}

run:
	./binario

zip:
	zip -r binario ./src/*.c ./include/*.h Makefile
