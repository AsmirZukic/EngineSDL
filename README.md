# EngineSDL
A graphics engine aiming to streamline the creation of SDL2 applications. Future plans include expanding it to be a bit more general purpose but currently only serves as a backend to my personal project.

## Features
Creates a window and renderer and provides input handling as well as the ability to render a circle.

## Compilation 

### Linux
Make sure you have the SDL2 library installed, insturctions on that will veary depending on your system. 
cd into the project folder and run ```make all```. It will create a executable called Engine which you can just run.

### Windows
Has not been tested on windows. Make sure you have the SDL2 library installed. Change include statements from ```#include <SDL2/SDL.h>``` to ``` #Include<SDL.h>```
after that everything should compile correctly. 
