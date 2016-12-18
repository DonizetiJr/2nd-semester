all: clean matriz_esparsa.o main.o compile clean

compile:
	gcc -o matriz_esparsa main.o matriz_esparsa.o

main.o:
	gcc -c ./src/main.c -I./include

matriz_esparsa.o:
	gcc -c ./src/matriz_esparsa.c -I./include

clean:
	find -name '*~'  | xargs rm -rf {}
	find -name '*.o' | xargs rm -rf {}

run:
	./matriz_esparsa

zip:
	zip -r esparsa ./src/*.c ./include/*.h Makefile
