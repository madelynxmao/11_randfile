main: main.o
	touch output.out
	gcc -o main.out main.o

main.o: main.c
	gcc -c main.c

run: main.out
	./main.out

clean:
	rm *.o