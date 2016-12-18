all: clean heap.o arvore_binaria.o huffman.o main.o compile clean

compile:
	gcc -o huffman arvore_binaria.o heap.o huffman.o main.o

main.o:
	gcc -c ./src/main.c -I./include

arvore_binaria.o:
	gcc -c ./src/arvore_binaria.c -I./include

heap.o:
	gcc -c ./src/heap.c -I./include

huffman.o:
	gcc -c ./src/huffman.c -I./include

clean:
	find -name '*~' | xargs rm -rf {}
	find -name '*.o' | xargs rm -rf {}

run:
	./huffman

zip:
	zip -r huffman ./src/*.c ./include/*.h Makefile
