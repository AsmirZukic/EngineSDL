# EngineSDL

A simple graphics engine made using SDL2. Currently has the ability to create a window and renderer with timer and input handling. I also added simple shape rendering using texures so you can make circles.

Deffinitely not general purpose but it will do the job for basic tasks like rendering the mandelbrot set.

On Linux you should be able to just do make all and it should compile if you have the SDL2 library installed. On windows it would require to change "SDL2/SDL.H" for "SDL.h" and probably some changes to the make file
