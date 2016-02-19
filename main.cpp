#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "Character.h"
#include "Character1.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background,rect_character;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 900/*WIDTH*/, 450/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    background = IMG_LoadTexture(renderer,"fondo.png");
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 900;
    rect_background.h = 450;

    Character* character = new Character(renderer);
    Character1* character1 = new Character1(renderer);

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_character.x--;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        character->logic();
        character->draw();

        character1->logic();
        character1->draw();

        SDL_RenderPresent(renderer);
    }

	return 0;
}
