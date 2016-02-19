#ifndef CHARACTER1_H
#define CHARACTER1_H

#include <iostream>
#include <map>
#include "Move.h"
using namespace std;

class Character1
{
    public:
        map<string,Move*>moves;
        string current_move;
        int current_sprite;
        int current_sprite_frame;
        Character1(SDL_Renderer* renderer);
        virtual ~Character1();
        void logic();
        void draw();
        Move* getMove(SDL_Renderer *renderer, string name, int sprite_amount);
    protected:
    private:
};

#endif // CHARACTER_H

