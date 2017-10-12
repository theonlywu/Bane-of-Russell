#ifndef FIRING_H_INCLUDED
#define FIRING_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

//Firing
void fireUp(Arrow arrows[], int, User &player);
void fireDown(Arrow arrows[], int, User &player);
void fireLeft(Arrow arrows[], int, User &player);
void fireRight(Arrow arrows[], int, User &player);
void updateUp(Arrow arrows[], int);
void updateDown(Arrow arrows[], int);
void updateLeft(Arrow arrows[], int);
void updateRight(Arrow arrows[], int);

/*
Fires the arrow up
Prerequisites: Arrows must be created
Returns nothing
Parameters are the arrows and user
Changes the arrow from not live to live
*/
void fireUp(Arrow arrowsUp[], int MAX_ARROWS, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(!arrowsUp[i].live){
            arrowsUp[i].x = player.x + 45;
            arrowsUp[i].y = player.y + 10;
            arrowsUp[i].live = true;
            break;
       }//ends the if
    }//ends the loop
}//ends the function

/*
Fires the arrow down
Prerequisites: Arrows must be created
Returns nothing
Parameters are the arrows and user
Changes the arrow from not live to live
*/
void fireDown(Arrow arrowsDown[], int MAX_ARROWS, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(!arrowsDown[i].live){
            arrowsDown[i].x = player.x + 45;
            arrowsDown[i].y = player.y + 70;
            arrowsDown[i].live = true;
            break;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Fires the arrow Left
Prerequisites: Arrows must be created
Returns nothing
Parameters are the arrows and user
Changes the arrow from not live to live
*/
void fireLeft(Arrow arrowsLeft[], int MAX_ARROWS, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(!arrowsLeft[i].live){
            arrowsLeft[i].x = player.x  + 30;
            arrowsLeft[i].y = player.y + 45;
            arrowsLeft[i].live = true;
            break;
       }//ends the if
    }//ends the loop
}//ends the function

/*
Fires the arrow right
Prerequisites: Arrows must be created
Returns nothing
Parameters are the arrows and user
Changes the arrow from not live to live
*/
void fireRight(Arrow arrowsRight[], int MAX_ARROWS, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(!arrowsRight[i].live){
            arrowsRight[i].x = player.x + 70;
            arrowsRight[i].y = player.y + 45;
            arrowsRight[i].live = true;
            break;
       }//ends the if
    }//ends the loop
}//ends the function


/*
Updates arrow positioning
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: updates arrow position
*/
void updateUp(Arrow arrowsUp[], int MAX_ARROWS){
for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsUp[i].live){
            arrowsUp[i].y -= arrowsUp[i].speed;
            if(arrowsUp[i].y < 0)
                arrowsUp[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates arrow positioning
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: updates arrow position
*/
void updateDown(Arrow arrowsDown[], int MAX_ARROWS){
for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsDown[i].live){
            arrowsDown[i].y += arrowsDown[i].speed;
            if(arrowsDown[i].y > 540)
                arrowsDown[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates arrow positioning
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: updates arrow position
*/
void updateLeft(Arrow arrowsLeft[], int MAX_ARROWS){
for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsLeft[i].live){
            arrowsLeft[i].x -= arrowsLeft[i].speed;
            if(arrowsLeft[i].x < 0)
                arrowsLeft[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates arrow positioning
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: updates arrow position
*/
void updateRight(Arrow arrowsRight[], int MAX_ARROWS){
for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsRight[i].live){
            arrowsRight[i].x += arrowsRight[i].speed;
            if(arrowsRight[i].x > 1036)
                arrowsRight[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

#endif // FIRING_H_INCLUDED
