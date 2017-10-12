#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED
#include <iostream>
using namespace std;

void moveUp(User &player);
void moveDown(User &player);
void moveLeft(User &player);
void moveRight(User &player);

/*
Moves the player up
Pre: needs the runGame function to be running and the character needs to be created already
Parameters: player
Returns: nothing
Post: Player x and y values
*/
void moveUp(User &player){
        player.y -= player.speed;
    if(player.y < 50)
        player.y = 50;
}//ends the function

/*
Moves the player up
Pre: needs the runGame function to be running and the character needs to be created already
Parameters: player
Returns: nothing
Post: Player x and y values
*/
void moveDown(User &player){
        player.y += player.speed;
        if(player.y > 430)
            player.y = 430;
}//ends the function

/*
Moves the player up
Pre: needs the runGame function to be running and the character needs to be created already
Parameters: player
Returns: nothing
Post: Player x and y values
*/
void moveLeft(User &player){
        player.x -= player.speed;
        if(player.x < 50)
            player.x = 50;
}//ends the function

/*
Moves the player up
Pre: needs the runGame function to be running and the character needs to be created already
Parameters: player
Returns: nothing
Post: Player x and y values
*/
void moveRight(User &player){
        player.x += player.speed;
        if(player.x > 936)
            player.x = 936;
}//ends the function


#endif // MOVEMENT_H_INCLUDED
