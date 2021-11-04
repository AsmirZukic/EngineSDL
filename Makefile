CC=g++
CFLAGS= -c -Wall
SDL2= -w -lSDL2

all: ParticleExplosion

ParticleExplosion: main.o engine.o renderer.o window.o inputHandler.o
	$(CC) main.o engine.o renderer.o window.o inputHandler.o $(SDL2) -o Engine

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

engine.o: src/engine.cpp
	$(CC) $(CFLAGS) src/engine.cpp

renderer.o: src/renderer.cpp
	$(CC) $(CFLAGS) src/renderer.cpp

window.o: src/window.cpp
	$(CC) $(CFLAGS) src/window.cpp

inputHandler.o: src/inputHandler.cpp
	$(CC) $(CFLAGS) src/inputHandler.cpp


clean:
	rm *.o Engine
