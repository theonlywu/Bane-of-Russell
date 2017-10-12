#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void collideUpToUp(Arrow arrowsUp[], int, Enemy enemiesTop[], int, User &player);
void collideUpToDown(Arrow arrowsUp[], int, Enemy enemiesDown[], int, User &player);
void collideUpToLeft(Arrow arrowsUp[], int, Enemy enemiesLeft[], int, User &player);
void collideUpToRight(Arrow arrowsUp[], int, Enemy enemiesRight[], int, User &player);

void collideDownToDown(Arrow arrowsDown[], int, Enemy enemiesDown[], int, User &player);
void collideDownToUp(Arrow arrowsDown[], int, Enemy enemiesTop[], int, User &player);
void collideDownToLeft(Arrow arrowsDown[], int, Enemy enemiesLeft[], int, User &player);
void collideDownToRight(Arrow arrowsDown[], int, Enemy enemiesRight[], int, User &player);

void collideLeftToLeft(Arrow arrowsLeft[], int, Enemy enemiesLeft[], int, User &player);
void collideLeftToUp(Arrow arrowsLeft[], int, Enemy enemiesTop[], int, User &player);
void collideLeftToDown(Arrow arrowsLeft[], int, Enemy enemiesDown[], int, User &player);
void collideLeftToRight(Arrow arrowsLeft[], int, Enemy enemiesRight[], int, User &player);

void collideRightToRight(Arrow arrowsRight[], int, Enemy enemiesRight[], int, User &player);
void collideRightToUp(Arrow arrowsRight[], int, Enemy enemiesTop[], int, User &player);
void collideRightToDown(Arrow arrowsRight[], int, Enemy enemiesDown[], int, User &player);
void collideRightToLeft(Arrow arrowsRight[], int, Enemy enemiesLeft[], int, User &player);

void collidePlayer(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int, User &player);

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideUpToUp(Arrow arrowsUp[], int MAX_ARROWS, Enemy enemiesTop[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsUp[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesTop[k].live){
                    if(arrowsUp[i].x > (enemiesTop[k].x - enemiesTop[k].boundx) &&
                       arrowsUp[i].x < (enemiesTop[k].x + enemiesTop[k].boundx) &&
                       arrowsUp[i].y > (enemiesTop[k].y - enemiesTop[k].boundy) &&
                       arrowsUp[i].y < (enemiesTop[k].y + enemiesTop[k].boundy)){
                        arrowsUp[i].live = false;
                        enemiesTop[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideUpToDown(Arrow arrowsUp[], int MAX_ARROWS, Enemy enemiesDown[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsUp[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesDown[k].live){
                    if(arrowsUp[i].x > (enemiesDown[k].x - enemiesDown[k].boundx) &&
                       arrowsUp[i].x < (enemiesDown[k].x + enemiesDown[k].boundx) &&
                       arrowsUp[i].y > (enemiesDown[k].y - enemiesDown[k].boundy) &&
                       arrowsUp[i].y < (enemiesDown[k].y + enemiesDown[k].boundy)){
                        arrowsUp[i].live = false;
                        enemiesDown[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideUpToLeft(Arrow arrowsUp[], int MAX_ARROWS, Enemy enemiesLeft[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsUp[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesLeft[k].live){
                    if(arrowsUp[i].x > (enemiesLeft[k].x - enemiesLeft[k].boundx) &&
                       arrowsUp[i].x < (enemiesLeft[k].x + enemiesLeft[k].boundx) &&
                       arrowsUp[i].y > (enemiesLeft[k].y - enemiesLeft[k].boundy) &&
                       arrowsUp[i].y < (enemiesLeft[k].y + enemiesLeft[k].boundy)){
                        arrowsUp[i].live = false;
                        enemiesLeft[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideUpToRight(Arrow arrowsUp[], int MAX_ARROWS, Enemy enemiesRight[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsUp[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesRight[k].live){
                    if(arrowsUp[i].x > (enemiesRight[k].x - enemiesRight[k].boundx) &&
                       arrowsUp[i].x < (enemiesRight[k].x + enemiesRight[k].boundx) &&
                       arrowsUp[i].y > (enemiesRight[k].y - enemiesRight[k].boundy) &&
                       arrowsUp[i].y < (enemiesRight[k].y + enemiesRight[k].boundy)){
                        arrowsUp[i].live = false;
                        enemiesRight[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideDownToDown(Arrow arrowsDown[], int MAX_ARROWS, Enemy enemiesDown[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsDown[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesDown[k].live){
                    if(arrowsDown[i].x > (enemiesDown[k].x - enemiesDown[k].boundx) &&
                       arrowsDown[i].x < (enemiesDown[k].x + enemiesDown[k].boundx) &&
                       arrowsDown[i].y > (enemiesDown[k].y - enemiesDown[k].boundy) &&
                       arrowsDown[i].y < (enemiesDown[k].y + enemiesDown[k].boundy)){
                        arrowsDown[i].live = false;
                        enemiesDown[k].live = false;
                        ++player.score;
                        }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideDownToUp(Arrow arrowsDown[], int MAX_ARROWS, Enemy enemiesTop[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsDown[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesTop[k].live){
                    if(arrowsDown[i].x > (enemiesTop[k].x - enemiesTop[k].boundx) &&
                       arrowsDown[i].x < (enemiesTop[k].x + enemiesTop[k].boundx) &&
                       arrowsDown[i].y > (enemiesTop[k].y - enemiesTop[k].boundy) &&
                       arrowsDown[i].y < (enemiesTop[k].y + enemiesTop[k].boundy)){
                        arrowsDown[i].live = false;
                        enemiesTop[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideDownToLeft(Arrow arrowsDown[], int MAX_ARROWS, Enemy enemiesLeft[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsDown[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesLeft[k].live){
                    if(arrowsDown[i].x > (enemiesLeft[k].x - enemiesLeft[k].boundx) &&
                       arrowsDown[i].x < (enemiesLeft[k].x + enemiesLeft[k].boundx) &&
                       arrowsDown[i].y > (enemiesLeft[k].y - enemiesLeft[k].boundy) &&
                       arrowsDown[i].y < (enemiesLeft[k].y + enemiesLeft[k].boundy)){
                        arrowsDown[i].live = false;
                        enemiesLeft[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideDownToRight(Arrow arrowsDown[], int MAX_ARROWS, Enemy enemiesRight[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsDown[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesRight[k].live){
                    if(arrowsDown[i].x > (enemiesRight[k].x - enemiesRight[k].boundx) &&
                       arrowsDown[i].x < (enemiesRight[k].x + enemiesRight[k].boundx) &&
                       arrowsDown[i].y > (enemiesRight[k].y - enemiesRight[k].boundy) &&
                       arrowsDown[i].y < (enemiesRight[k].y + enemiesRight[k].boundy)){
                        arrowsDown[i].live = false;
                        enemiesRight[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideLeftToLeft(Arrow arrowsLeft[], int MAX_ARROWS, Enemy enemiesLeft[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsLeft[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesLeft[k].live){
                    if(arrowsLeft[i].x > (enemiesLeft[k].x - enemiesLeft[k].boundx) &&
                       arrowsLeft[i].x < (enemiesLeft[k].x + enemiesLeft[k].boundx) &&
                       arrowsLeft[i].y > (enemiesLeft[k].y - enemiesLeft[k].boundy) &&
                       arrowsLeft[i].y < (enemiesLeft[k].y + enemiesLeft[k].boundy)){
                        arrowsLeft[i].live = false;
                        enemiesLeft[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideLeftToUp(Arrow arrowsLeft[], int MAX_ARROWS, Enemy enemiesTop[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsLeft[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesTop[k].live){
                    if(arrowsLeft[i].x > (enemiesTop[k].x - enemiesTop[k].boundx) &&
                       arrowsLeft[i].x < (enemiesTop[k].x + enemiesTop[k].boundx) &&
                       arrowsLeft[i].y > (enemiesTop[k].y - enemiesTop[k].boundy) &&
                       arrowsLeft[i].y < (enemiesTop[k].y + enemiesTop[k].boundy)){
                        arrowsLeft[i].live = false;
                        enemiesTop[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideLeftToDown(Arrow arrowsLeft[], int MAX_ARROWS, Enemy enemiesDown[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsLeft[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesDown[k].live){
                    if(arrowsLeft[i].x > (enemiesDown[k].x - enemiesDown[k].boundx) &&
                       arrowsLeft[i].x < (enemiesDown[k].x + enemiesDown[k].boundx) &&
                       arrowsLeft[i].y > (enemiesDown[k].y - enemiesDown[k].boundy) &&
                       arrowsLeft[i].y < (enemiesDown[k].y + enemiesDown[k].boundy)){
                        arrowsLeft[i].live = false;
                        enemiesDown[k].live = false;
                        ++player.score;
                        }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideLeftToRight(Arrow arrowsLeft[], int MAX_ARROWS, Enemy enemiesRight[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsLeft[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesRight[k].live){
                    if(arrowsLeft[i].x > (enemiesRight[k].x - enemiesRight[k].boundx) &&
                       arrowsLeft[i].x < (enemiesRight[k].x + enemiesRight[k].boundx) &&
                       arrowsLeft[i].y > (enemiesRight[k].y - enemiesRight[k].boundy) &&
                       arrowsLeft[i].y < (enemiesRight[k].y + enemiesRight[k].boundy)){
                        arrowsLeft[i].live = false;
                        enemiesRight[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideRightToRight(Arrow arrowsRight[], int MAX_ARROWS, Enemy enemiesRight[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsRight[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesRight[k].live){
                    if(arrowsRight[i].x > (enemiesRight[k].x - enemiesRight[k].boundx) &&
                       arrowsRight[i].x < (enemiesRight[k].x + enemiesRight[k].boundx) &&
                       arrowsRight[i].y > (enemiesRight[k].y - enemiesRight[k].boundy) &&
                       arrowsRight[i].y < (enemiesRight[k].y + enemiesRight[k].boundy)){
                        arrowsRight[i].live = false;
                        enemiesRight[k].live = false;
                        ++player.score;
                        }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideRightToUp(Arrow arrowsRight[], int MAX_ARROWS, Enemy enemiesTop[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsRight[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesTop[k].live){
                    if(arrowsRight[i].x > (enemiesTop[k].x - enemiesTop[k].boundx) &&
                       arrowsRight[i].x < (enemiesTop[k].x + enemiesTop[k].boundx) &&
                       arrowsRight[i].y > (enemiesTop[k].y - enemiesTop[k].boundy) &&
                       arrowsRight[i].y < (enemiesTop[k].y + enemiesTop[k].boundy)){
                        arrowsRight[i].live = false;
                        enemiesTop[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideRightToDown(Arrow arrowsRight[], int MAX_ARROWS, Enemy enemiesDown[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsRight[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesDown[k].live){
                    if(arrowsRight[i].x > (enemiesDown[k].x - enemiesDown[k].boundx) &&
                       arrowsRight[i].x < (enemiesDown[k].x + enemiesDown[k].boundx) &&
                       arrowsRight[i].y > (enemiesDown[k].y - enemiesDown[k].boundy) &&
                       arrowsRight[i].y < (enemiesDown[k].y + enemiesDown[k].boundy)){
                        arrowsRight[i].live = false;
                        enemiesDown[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collideRightToLeft(Arrow arrowsRight[], int MAX_ARROWS, Enemy enemiesLeft[], int MAX_ENEMIES, User &player){
    for(int i = 0; i < MAX_ARROWS ; i++){
        if(arrowsRight[i].live){
            for(int k = 0; k < MAX_ENEMIES ; k++){
                if(enemiesLeft[k].live){
                    if(arrowsRight[i].x > (enemiesLeft[k].x - enemiesLeft[k].boundx) &&
                       arrowsRight[i].x < (enemiesLeft[k].x + enemiesLeft[k].boundx) &&
                       arrowsRight[i].y > (enemiesLeft[k].y - enemiesLeft[k].boundy) &&
                       arrowsRight[i].y < (enemiesLeft[k].y + enemiesLeft[k].boundy)){
                        arrowsRight[i].live = false;
                        enemiesLeft[k].live = false;
                        ++player.score;
                       }//ends the if
                }//ends the if
            }//ends the loop
        }//ends the if
    }//ends the loop
}//ends the function

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void collidePlayer(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int MAX_ENEMIES, User &player){
     for(int i = 0; i < MAX_ENEMIES ; i++){
        if(enemiesTop[i].live){
            if(enemiesTop[i].x - enemiesTop[i].boundx < player.x + player.boundx &&
            enemiesTop[i].x + enemiesTop[i].boundx > player.x - player.boundx &&
            enemiesTop[i].y - enemiesTop[i].boundy < player.y + player.boundy &&
            enemiesTop[i].y + enemiesTop[i].boundy > player.y - player.boundy){
                --player.lives;
                enemiesTop[i].live = false;
            }//ends the if
        }//ends the if
    }//ends the loop

     for(int i = 0; i < MAX_ENEMIES ; i++){
        if(enemiesDown[i].live){
            if(enemiesDown[i].x - enemiesDown[i].boundx < player.x + player.boundx &&
            enemiesDown[i].x + enemiesDown[i].boundx > player.x - player.boundx &&
            enemiesDown[i].y - enemiesDown[i].boundy < player.y + player.boundy &&
            enemiesDown[i].y + enemiesDown[i].boundy > player.y - player.boundy){
                --player.lives;
                enemiesDown[i].live = false;
            }//ends the if
        }//ends the if
    }//ends the loop

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
     for(int i = 0; i < MAX_ENEMIES ; i++){
        if(enemiesLeft[i].live){
            if(enemiesTop[i].x - enemiesLeft[i].boundx < player.x + player.boundx &&
            enemiesLeft[i].x + enemiesLeft[i].boundx > player.x - player.boundx &&
            enemiesLeft[i].y - enemiesLeft[i].boundy < player.y + player.boundy &&
            enemiesLeft[i].y + enemiesLeft[i].boundy > player.y - player.boundy){
                --player.lives;
                enemiesLeft[i].live = false;
            }//ends the if
        }//ends the if
    }//ends the loop

/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
     for(int i = 0; i < MAX_ENEMIES ; i++){
        if(enemiesRight[i].live){
            if(enemiesRight[i].x - enemiesRight[i].boundx < player.x + player.boundx &&
            enemiesRight[i].x + enemiesRight[i].boundx > player.x - player.boundx &&
            enemiesRight[i].y - enemiesRight[i].boundy < player.y + player.boundy &&
            enemiesRight[i].y + enemiesRight[i].boundy > player.y - player.boundy){
                --player.lives;
                enemiesRight[i].live = false;
            }//ends the if
        }//ends the if
    }//ends the loop
}//ends the function


#endif // COLLISION_H_INCLUDED
