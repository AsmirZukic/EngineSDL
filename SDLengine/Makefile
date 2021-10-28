CC=g++
CFLAGS= -c -Wall
SDL2= -w -lSDL2

all: Engine

Engine: main.o engine.o renderer.o window.o
	$(CC) main.o engine.o renderer.o window.o $(SDL2) -o Engine

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

engine.o: src/engine.cpp
	$(CC) $(CFLAGS) src/engine.cpp

renderer.o: src/renderer.cpp
	$(CC) $(CFLAGS) src/renderer.cpp

window.o: src/window.cpp
	$(CC) $(CFLAGS) src/window.cpp

clean:
	rm *.o
