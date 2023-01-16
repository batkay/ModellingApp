#include <stdio.h>
#include <iostream>
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

const int width = 680;
const int height = 480;

int main(int argc, char *argv[])
{
    // tries to initialize the SDL library and exits if error
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    // tries to create a window
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    // gets the window's surface (aka the thing inside the window u can draw in)
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    if (!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    // fill rect draws a rectangle on a surface. window_surface tells it to draw the rectangle on the window surface from before, null says we want to fill the entire screen (can give it a rect object to just do a portion) and map2rgb gives the color
    SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}