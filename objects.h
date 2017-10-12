#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
using namespace std;

enum IDS{PLAYER, ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, ENEMY};

//The Player
struct User{
    int id;
    int x;
    int y;
    int speed;
    int lives;
    int boundx;
    int boundy;
    int score;
};//ends the structure declaration

//The arrows
struct Arrow{
    int id;
    int x;
    int y;
    int speed;
    bool live;
};//ends the structure declaration

//The Enemies
struct Enemy{
    int id;
    int x;
    int y;
    bool live;
    int speed;
    int boundx;
    int boundy;
};//ends the structure declaration

#endif // OBJECTS_H_INCLUDED
