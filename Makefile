CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -std=c17 -g

bfi.exe: obj/main.o obj/stack.o
	$(CC) obj/main.o obj/stack.o -o bfi.exe $(CFLAGS)

obj/main.o: main.c
	$(CC) -c main.c -o obj/main.o $(CFLAGS)

obj/stack.o: stack.c
	$(CC) -c stack.c -o obj/stack.o $(CFLAGS)

clean:
	rm obj/*.o
	rm *.exe