#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void startEnemyTop(Enemy enemiesTop[], int);
void startEnemyDown(Enemy enemiesDown[], int);
void startEnemyLeft(Enemy enemiesLeft[], int);
void startEnemyRight(Enemy enemiesRight[], int);
void updateEnemyTop(Enemy enemiesTop[], int);
void updateEnemyDown(Enemy enemiesDown[], int);
void updateEnemyLeft(Enemy enemiesLeft[], int);
void updateEnemyRight(Enemy enemiesRight[], int);


/*
Determines a spawning point for the enemies
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: changes the spawn points of enemies
*/
void startEnemyTop(Enemy enemiesTop[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(!enemiesTop[i].live){
            if(rand() % 650 == 0){
                enemiesTop[i].live = true;
                enemiesTop[i].x = rand() % 936;
                enemiesTop[i].y = 50;
                break;
            }//ends the if
        }//ends the if
    }//ends the loop
}//ends the function

/*
Determines a spawning point for the enemies
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: changes the spawn points of enemies
*/
void startEnemyDown(Enemy enemiesDown[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(!enemiesDown[i].live){
            if(rand() % 650 == 0){
                enemiesDown[i].live = true;
                enemiesDown[i].x = rand() % 936;
                enemiesDown[i].y = 430;
                break;
            }//ends the if
        }//ends the if
    }//ends the loop
}//ends the function

/*
Determines a spawning point for the enemies
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: changes the spawn points of enemies
*/
void startEnemyLeft(Enemy enemiesLeft[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(!enemiesLeft[i].live){
            if(rand() % 650 == 0){
                enemiesLeft[i].live = true;
                enemiesLeft[i].x = 50;
                enemiesLeft[i].y = rand() % 430;
                break;
            }//ends the if
        }//ends the if
    }//ends the loop
}//ends the function

/*
Determines a spawning point for the enemies
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: changes the spawn points of enemies
*/
void startEnemyRight(Enemy enemiesRight[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(!enemiesRight[i].live){
            if(rand() % 650 == 0){
                enemiesRight[i].live = true;
                enemiesRight[i].x = 936;
                enemiesRight[i].y = rand() % 430;
                break;
            }//ends the if
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates where the enemies are
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: updates where the enemies are
*/
void updateEnemyTop(Enemy enemiesTop[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesTop[i].live){
            enemiesTop[i].y += enemiesTop[i].speed;
            if(enemiesTop[i].y > 430)
                enemiesTop[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates where the enemies are
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: updates where the enemies are
*/
void updateEnemyDown(Enemy enemiesDown[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesDown[i].live){
            enemiesDown[i].y -= enemiesDown[i].speed;
            if(enemiesDown[i].y < 50)
                enemiesDown[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates where the enemies are
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: updates where the enemies are
*/
void updateEnemyLeft(Enemy enemiesLeft[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesLeft[i].live){
            enemiesLeft[i].x += enemiesLeft[i].speed;
            if(enemiesLeft[i].y > 936)
                enemiesLeft[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function

/*
Updates where the enemies are
Pre: needs the runGame function to be running and the enemies array needs to be created already
Parameters: enemies and max enemies
Returns: nothing
Post: updates where the enemies are
*/
void updateEnemyRight(Enemy enemiesRight[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesRight[i].live){
            enemiesRight[i].x -= enemiesRight[i].speed;
            if(enemiesRight[i].y < 50)
                enemiesRight[i].live = false;
        }//ends the if
    }//ends the loop
}//ends the function



#endif // ENEMIES_H_INCLUDED
