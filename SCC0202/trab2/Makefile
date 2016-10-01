all: clean item.o array_list.o main.o compile clean

compile:
	gcc -o arraylist main.o array_list.o item.o

main.o:
	gcc -c ./src/main.c -I./include

array_list.o:
	gcc -c ./src/array_list.c -I./include

item.o:
	gcc -c ./src/item.c -I./include

clean:
	find -name '*~'  | xargs rm -rf {}
	find -name '*.o' | xargs rm -rf {}

run:
	./arraylist

zip:
	zip -r arraylist ./src/*.c ./include/*.h Makefile
