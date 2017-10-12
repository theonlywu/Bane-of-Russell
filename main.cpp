//Andy Wu P.8
//A 2D platform game with a top down view that spawns enemies on all 4 sides,
//The enemies move to the other side of the screen and only stop either by
//colliding with the player, or with a bullet. There are 5 lives
//CPP Headers
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

//Allegro Headers
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

//Custom Headers
#include "Menu.h"
#include "objects.h"
#include "movement.h"
#include "firing.h"
#include "enemies.h"
#include "collision.h"
using namespace std;

//GLOBAL VARIABLES
const int WIDTH = 1036; //resolution width
const int HEIGHT = 540; //resolution height
const int MAX_ARROWS = 10; //The number of arrows allowed on the screen at one time
const int MAX_ENEMIES = 15;
const int KEYS_USED = 11;
bool keys[KEYS_USED] = {false, false, false, false, false, false, false, false, false, false, false}; //For holding down a key
enum KEYS{W, S, A, D, UP, DOWN, LEFT, RIGHT, SPACE, MOUSELEFT, MOUSERIGHT}; //Makes the keys easier to remember when accessing the array


//Function Prototypes
void runGame(int, int);

void createPlayer(User &player);
void drawPlayer(User &player, int);

void createArrow(Arrow arrowsUp[], Arrow arrowsDown[], Arrow arrowsLeft[], Arrow arrowsRight[], int);
void drawArrow(Arrow arrowsUp[], Arrow arrowsDown[], Arrow arrowsLeft[], Arrow arrowsRight[], int, int);

void createEnemy(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int);
void drawEnemy(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int);

/*
Sets up the console menu and loops it and changes the color of console
Lots of parameters get passed around
returns 0; to end the program
changes the console and sets up the GUI
no prerequisites
*/
int main() {
//Color change for pretty console
system("color F1");

//Variables
int choice,     //Choice from the menu
    character = 1, //character choice
    background = 1;
char confirmation; //confirms if you want to quit the game
bool done =  true; //Closes the menu

//Loops the Menu
do{


//Brings up the menu
choice = menu(choice);
system("CLS");

//Switches between the functions
switch(choice){
case 1:
    runGame(character, background);
    break;
case 2:
    character = characterChoice(choice, character);
    break;
case 3:
    instructions(choice);
    break;
case 4:
    background = backgroundChoice(choice, background);
    break;
case 5:
    system("CLS");
    cout << "Are you sure you wish to exit? Y or N?\n";
    cin >> confirmation;
    while(confirmation != 'Y' && confirmation != 'N' && confirmation != 'y' && confirmation != 'n'){
        cout << "Invalid entry, please input Y or N.\n";
        cin >> confirmation;
        system("CLS");
    }//ends the loop

    if(confirmation == 'Y' || confirmation == 'y'){
        done = false;
    }//ends the if statement
    else if(confirmation == 'N' || confirmation == 'n'){
        cout << "We will now return to the main menu.\n";
        system("pause");
        system("CLS");
    }//ends the if statement
    //Closes the game
    if(!done){
    cout << "The game will now exit.\n";
    return 0;
    }//ends the if statement
}//ends the switch statement
}while(1);

return 0;
}//ends the function

/*Begins the game
Prerequisites: character should be chosen.
parameters: character
returns: nothing
changes: nothing
*/
void runGame(int character, int background){
     bool done = false; //Keeps track of the loop that runs the game
     int fps = 60; //Goal FPS of the game
     bool redraw; //redrawing the object for smoothness
     int image1Height, image1Width;
     double second = 1.0; //For the FPS
     bool isGameOver = false; //is game over?

     //Object/Structure Variables
     User player;
     Enemy enemiesTop[MAX_ENEMIES];
     Enemy enemiesDown[MAX_ENEMIES];
     Enemy enemiesLeft[MAX_ENEMIES];
     Enemy enemiesRight[MAX_ENEMIES];
     Arrow arrowsUp[MAX_ARROWS];
     Arrow arrowsDown[MAX_ARROWS];
     Arrow arrowsLeft[MAX_ARROWS];
     Arrow arrowsRight[MAX_ARROWS];

     //Creates our structures
     srand(time(NULL));
     createPlayer(player);
     createArrow(arrowsUp, arrowsDown, arrowsLeft, arrowsRight, MAX_ARROWS);
     createEnemy(enemiesTop, enemiesDown, enemiesLeft, enemiesRight, MAX_ENEMIES);

     int *score = &player.score;

     cout << "The game will now commence.\n";

     //ALLEGRO VARIABLES
     ALLEGRO_DISPLAY *display = NULL; //Initializes the display
     ALLEGRO_EVENT_QUEUE *event_queue = NULL; //creates a variable for the event queue
     ALLEGRO_TIMER *timer = NULL; //Helps the program run 60 fps

     ALLEGRO_BITMAP *image1 = NULL; //generates the images to be used

     ALLEGRO_FONT *font18 = NULL; //creates a pointer for the font size
     ALLEGRO_FONT *font36 = NULL; //creates a pointer for the font size


     if(!al_init()){
        cout << "Game failed to start please exit game.\n";
        abort(); //leaves function
     }//ends the if statement

     display = al_create_display(WIDTH, HEIGHT);

     if(!display){
        cout << "Window failed to create please exit the game.\n";
        abort(); //leaves function
     }//ends the if statement

     //Addons and installations
     al_install_keyboard(); //Installs the Keyboard
     al_install_mouse();    //Installs the mouse
     al_init_primitives_addon(); //Initializes the use of primitives and shapes
     al_init_image_addon(); //Initializes the use of windows images
     al_init_font_addon(); //initializes use of fonts
     al_init_ttf_addon(); //initializes use of .ttf files

     //Font Loading
     font18 = al_load_font("arial.ttf", 18, 0);
     font36 = al_load_font("arial.ttf", 36, 0);

     //Event source registries and timers
     timer = al_create_timer(second / fps);  //Creates the goal fps timer
     event_queue = al_create_event_queue(); //Initializes the event queue
     al_register_event_source(event_queue, al_get_keyboard_event_source());            /* These allow these inputs to register */
     al_register_event_source(event_queue, al_get_display_event_source(display));
     al_register_event_source(event_queue, al_get_mouse_event_source());
     al_register_event_source(event_queue, al_get_timer_event_source(timer));
     al_hide_mouse_cursor(display);

     //Image Loading
     if(background == 1)
          image1 = al_load_bitmap("Underwater.png");
     else if(background == 2)
     image1 = al_load_bitmap("Space.png");


     image1Width = al_get_bitmap_width(image1);
     image1Height = al_get_bitmap_height(image1);

     al_start_timer(timer); //Starts the timer before the game starts

     while(!done){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //This controls the movement
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys[W] = true;
                    break;
                case ALLEGRO_KEY_S:
                    keys[S] = true;
                    break;
                case ALLEGRO_KEY_A:
                    keys[A] = true;
                    break;
                case ALLEGRO_KEY_D:
                    keys[D] = true;
                    break;
                case ALLEGRO_KEY_UP:
                    keys[UP] = true;
                    fireUp(arrowsUp, MAX_ARROWS, player);
                    break;
                case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = true;
                    fireDown(arrowsDown, MAX_ARROWS, player);
                    break;
                case ALLEGRO_KEY_LEFT:
                    keys[LEFT] = true;
                    fireLeft(arrowsLeft, MAX_ARROWS, player);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    keys[RIGHT] = true;
                    fireRight(arrowsRight, MAX_ARROWS, player);
                    break;
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = true;
                    break;
                }//ends the switch
            }//ends the if
        else if(ev.type == ALLEGRO_EVENT_KEY_UP){
               switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys[W] = false;
                    break;
                case ALLEGRO_KEY_S:
                    keys[S] = false;
                    break;
                case ALLEGRO_KEY_A:
                    keys[A] = false;
                    break;
                case ALLEGRO_KEY_D:
                    keys[D] = false;
                    break;
                case ALLEGRO_KEY_UP:
                    keys[UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    keys[LEFT] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    keys[RIGHT] = false;
                    break;
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = false;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                }//ends the switch
            }//ends the if statement
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            done = true;
        }//ends the if statement
        else if(ev.type == ALLEGRO_EVENT_TIMER){
            redraw = true;
            if(keys[W])
                moveUp(player);
            else if(keys[S])
                moveDown(player);
            else if(keys[A])
                moveLeft(player);
            else if(keys[D])
                moveRight(player);

            //Consistently update the game with new info as well as spawning
            if(!isGameOver){
            startEnemyTop(enemiesTop, MAX_ENEMIES);
            startEnemyDown(enemiesDown, MAX_ENEMIES);
            startEnemyLeft(enemiesLeft, MAX_ENEMIES);
            startEnemyRight(enemiesRight, MAX_ENEMIES);

            updateEnemyTop(enemiesTop, MAX_ENEMIES);
            updateEnemyDown(enemiesDown, MAX_ENEMIES);
            updateEnemyLeft(enemiesLeft, MAX_ENEMIES);
            updateEnemyRight(enemiesRight, MAX_ENEMIES);

            updateUp(arrowsUp, MAX_ARROWS);
            updateDown(arrowsDown, MAX_ARROWS);
            updateLeft(arrowsLeft, MAX_ARROWS);
            updateRight(arrowsRight, MAX_ARROWS);

            collideUpToUp(arrowsUp, MAX_ARROWS, enemiesTop, MAX_ENEMIES, player);
            collideUpToDown(arrowsUp, MAX_ARROWS, enemiesDown, MAX_ENEMIES, player);
            collideUpToLeft(arrowsUp, MAX_ARROWS, enemiesLeft, MAX_ENEMIES, player);
            collideUpToRight(arrowsUp, MAX_ARROWS, enemiesRight, MAX_ENEMIES, player);

            collideDownToUp(arrowsDown, MAX_ARROWS, enemiesTop, MAX_ENEMIES, player);
            collideDownToDown(arrowsDown, MAX_ARROWS, enemiesDown, MAX_ENEMIES, player);
            collideDownToLeft(arrowsDown, MAX_ARROWS, enemiesLeft, MAX_ENEMIES, player);
            collideDownToRight(arrowsDown, MAX_ARROWS, enemiesRight, MAX_ENEMIES, player);

            collideLeftToUp(arrowsLeft, MAX_ARROWS, enemiesTop, MAX_ENEMIES, player);
            collideLeftToDown(arrowsLeft, MAX_ARROWS, enemiesDown, MAX_ENEMIES, player);
            collideLeftToLeft(arrowsLeft, MAX_ARROWS, enemiesLeft, MAX_ENEMIES, player);
            collideLeftToRight(arrowsLeft, MAX_ARROWS, enemiesRight, MAX_ENEMIES, player);

            collideRightToUp(arrowsRight, MAX_ARROWS, enemiesTop, MAX_ENEMIES, player);
            collideRightToDown(arrowsRight, MAX_ARROWS, enemiesDown, MAX_ENEMIES, player);
            collideRightToLeft(arrowsRight, MAX_ARROWS, enemiesLeft, MAX_ENEMIES, player);
            collideRightToRight(arrowsRight, MAX_ARROWS, enemiesRight, MAX_ENEMIES, player);

            collidePlayer(enemiesTop, enemiesDown, enemiesLeft, enemiesRight, MAX_ENEMIES, player);
            if(player.lives <= 0)
                isGameOver = true;
            }//ends the if statement
        }//ends the if statement

        if(redraw && al_event_queue_is_empty(event_queue)){
            redraw = false;

            if(!isGameOver){
                drawPlayer(player, character);
                drawArrow(arrowsUp, arrowsDown, arrowsLeft, arrowsRight, MAX_ARROWS, character);
                drawEnemy(enemiesTop, enemiesDown, enemiesLeft, enemiesRight, MAX_ENEMIES);

                al_draw_textf(font18, al_map_rgb(255, 255, 255), 5, 5, 0, "Lives: %i", player.lives);
                al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH - 180, HEIGHT - 30, 0, "Russells Slain: %i", player.score);
            }//ends the if statement
            else{
                al_draw_textf(font36, al_map_rgb(0, 0, 0), WIDTH / 2, (HEIGHT / 2) - 70, ALLEGRO_ALIGN_CENTRE, "Game Over!", 0);
                al_draw_textf(font36, al_map_rgb(0, 0, 0), WIDTH / 2, (HEIGHT / 2) - 30, ALLEGRO_ALIGN_CENTRE, "Russells Slain: %i", *score);
                al_draw_textf(font36, al_map_rgb(0, 0, 0), WIDTH / 2, (HEIGHT / 2) + 10, ALLEGRO_ALIGN_CENTRE, "Press Esc to Exit", 0);
            }//ends the if statement

            al_flip_display(); //Clears the double buffer and brings background up
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(image1, WIDTH - image1Width, HEIGHT - image1Height, 0); //Loads the first image
        }//ends the if statement
    }//ends the loop
     al_destroy_bitmap(image1); //Destroys the bitmap
     al_destroy_display(display); //Destroys the display
     system("pause");
     system("CLS");
}//ends the function

/*
Creates the class of the player character
Pre: needs the runGame function to be running
Parameters: player
Returns: nothing
Post: changes all of the player's variables
*/
void createPlayer(User &player){
    player.id = PLAYER;
    player.x = WIDTH / 2;
    player.y = HEIGHT / 2;
    player.speed = 6;
    player.lives = 5;
    player.boundx = 6;
    player.boundy = 7;
    player.score = 0;
}//ends the function

/*
Draws the player on the screen
Pre: needs the runGame function to be running and the character needs to be created already
Parameters: player
Returns: nothing
Post: creates the players display
*/
void drawPlayer(User &player, int character){
    //Creates bitmap pointers
    ALLEGRO_BITMAP *Gunner = NULL;
    ALLEGRO_BITMAP *Russell = NULL;
    ALLEGRO_BITMAP *Ninja = NULL;
    ALLEGRO_BITMAP *Wizard = NULL;
    //Load in the character bitmaps onto the pointers
    Gunner = (al_load_bitmap("Gunner.bmp"));
    Russell = (al_load_bitmap("RussellCharacter.bmp"));
    Ninja = (al_load_bitmap("Ninja.bmp"));
    Wizard = (al_load_bitmap("Wizard.bmp"));
    //gets rid of any backgrounds
    al_convert_mask_to_alpha(Gunner, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Russell, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Ninja, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Wizard, al_map_rgb(255, 255, 255));

    //determines which character was selected
    if(character == 1)
        al_draw_bitmap(Gunner, player.x, player.y, 0);
    else if(character == 2)
        al_draw_bitmap(Ninja, player.x, player.y, 0);
    else if(character == 3)
        al_draw_bitmap(Russell, player.x, player.y, 0);
    else if(character == 4)
        al_draw_bitmap(Wizard, player.x, player.y, 0);
    else
        al_draw_bitmap(Gunner, player.x, player.y, 0);
}//ends the function

/*
Creates the class of the arrow
Pre: needs the runGame function to be running
Parameters: arrow, max arrows
Returns: nothing
Post: creates the arrow variables
*/
void createArrow(Arrow arrowsUp[], Arrow arrowsDown[], Arrow arrowsLeft[], Arrow arrowsRight[], int MAX_ARROWS){
    for(int i = 0; i < MAX_ARROWS ; i++) {
        arrowsUp[i].id = ARROW_UP;
        arrowsUp[i].speed = 8;
        arrowsUp[i].live = false;
    }//ends the loop
    for(int i = 0; i < MAX_ARROWS ; i++) {
        arrowsDown[i].id = ARROW_DOWN;
        arrowsDown[i].speed = 8;
        arrowsDown[i].live = false;
    }//ends the loop
     for(int i = 0; i < MAX_ARROWS ; i++) {
        arrowsLeft[i].id = ARROW_LEFT;
        arrowsLeft[i].speed = 8;
        arrowsLeft[i].live = false;
    }//ends the loop
     for(int i = 0; i < MAX_ARROWS ; i++) {
        arrowsRight[i].id = ARROW_RIGHT;
        arrowsRight[i].speed = 8;
        arrowsRight[i].live = false;
    }//ends the loop
}//ends the function

/*
Draws the arrow on the screen
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: creates the arrow display
*/
void drawArrow(Arrow arrowsUp[], Arrow arrowsDown[], Arrow arrowsLeft[], Arrow arrowsRight[], int MAX_ARROWS, int character){
    //Initializes Weapon Image pointers
    ALLEGRO_BITMAP *image2 = NULL;
    ALLEGRO_BITMAP *image3Up = NULL;
    ALLEGRO_BITMAP *image3Down = NULL;
    ALLEGRO_BITMAP *image3Left = NULL;
    ALLEGRO_BITMAP *image3Right = NULL;
    ALLEGRO_BITMAP *image4 = NULL;
    //loads in the weapon bitmaps into pointers
    image2 = al_load_bitmap("Ninja Star.bmp");
    image3Up = al_load_bitmap("RussellBulletUp.bmp");
    image3Down = al_load_bitmap("RussellBulletDown.bmp");
    image3Left = al_load_bitmap("RussellBulletLeft.bmp");
    image3Right = al_load_bitmap("RussellBulletRight.bmp");
    image4 = al_load_bitmap("Fireball.bmp");
    //converts the background so that the white disappears
    al_convert_mask_to_alpha(image2, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(image3Up, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(image3Down, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(image3Left, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(image3Right, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(image4, al_map_rgb(255, 255, 255));

    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsUp[i].live){
            if(character == 2)
                al_draw_bitmap(image2, arrowsUp[i].x, arrowsUp[i].y, 0);
            else if(character == 3)
                al_draw_bitmap(image3Up, arrowsUp[i].x, arrowsUp[i].y, 0);
            else if(character == 4)
                al_draw_bitmap(image4, arrowsUp[i].x, arrowsUp[i].y, 0);
            else
                al_draw_filled_circle(arrowsUp[i].x, arrowsUp[i].y, 2, al_map_rgb(0, 0, 0));
       }//ends the if
    }//ends the loop
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsDown[i].live){
            if(character == 2)
                al_draw_bitmap(image2, arrowsDown[i].x, arrowsDown[i].y, 0);
            else if(character == 3)
                al_draw_bitmap(image3Down, arrowsDown[i].x, arrowsDown[i].y, 0);
            else if(character == 4)
                al_draw_bitmap(image4, arrowsDown[i].x, arrowsDown[i].y, 0);
            else
                al_draw_filled_circle(arrowsDown[i].x, arrowsDown[i].y, 2, al_map_rgb(0, 0, 0));
       }//ends the if
    }//ends the loop
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsLeft[i].live){
            if(character == 2)
                al_draw_bitmap(image2, arrowsLeft[i].x, arrowsLeft[i].y, 0);
            else if(character == 3)
                al_draw_bitmap(image3Left, arrowsLeft[i].x, arrowsLeft[i].y, 0);
            else if(character == 4)
                al_draw_bitmap(image4, arrowsLeft[i].x, arrowsLeft[i].y, 0);
            else
                al_draw_filled_circle(arrowsLeft[i].x, arrowsLeft[i].y, 2, al_map_rgb(0, 0, 0));
       }//ends the if
    }//ends the loop
    for(int i = 0; i < MAX_ARROWS ; i++) {
       if(arrowsRight[i].live){
            if(character == 2)
                al_draw_bitmap(image2, arrowsRight[i].x, arrowsRight[i].y, 0);
            else if(character == 3)
                al_draw_bitmap(image3Right, arrowsRight[i].x, arrowsRight[i].y, 0);
            else if(character == 4)
                al_draw_bitmap(image4, arrowsRight[i].x, arrowsRight[i].y, 0);
            else
                al_draw_filled_circle(arrowsRight[i].x, arrowsRight[i].y, 2, al_map_rgb(0, 0, 0));
       }//ends the if
    }//ends the loop
}//ends the function

/*
Creates the class of the enemy
Pre: needs the runGame function to be running
Parameters: enemy, max enemies
Returns: nothing/*
Detects collision between the arrow and enemy
Pre: Needs arrow and enemy arrays to have been created
Parameters: arrows, enemies and the max sizes
return: none
post will set to false if collision detected
*/
void createEnemy(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int MAX_ENEMIES){
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        enemiesTop[i].id = ENEMY;
        enemiesTop[i].live = false;
        enemiesTop[i].speed = 7;
        enemiesTop[i].boundx = 22;
        enemiesTop[i].boundy = 22;
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        enemiesDown[i].id = ENEMY;
        enemiesDown[i].live = false;
        enemiesDown[i].speed = 7;
        enemiesDown[i].boundx = 22;
        enemiesDown[i].boundy = 22;
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        enemiesLeft[i].id = ENEMY;
        enemiesLeft[i].live = false;
        enemiesLeft[i].speed = 7;
        enemiesLeft[i].boundx = 22;
        enemiesLeft[i].boundy = 22;
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        enemiesRight[i].id = ENEMY;
        enemiesRight[i].live = false;
        enemiesRight[i].speed = 7;
        enemiesRight[i].boundx = 22;
        enemiesRight[i].boundy = 22;
    }//ends the loop
}//ends the function

/*
Draws the enemies on the screen
Pre: needs the runGame function to be running and the arrows array needs to be created already
Parameters: arrows and max arrows
Returns: nothing
Post: creates the enemies display
*/
void drawEnemy(Enemy enemiesTop[], Enemy enemiesDown[], Enemy enemiesLeft[], Enemy enemiesRight[], int MAX_ENEMIES){
    //Bitmaps for Enemies
    ALLEGRO_BITMAP *Up = NULL;
    ALLEGRO_BITMAP *Down = NULL;
    ALLEGRO_BITMAP *Left = NULL;
    ALLEGRO_BITMAP *Right = NULL;
    Up = al_load_bitmap("RussellUp.bmp");
    Down = al_load_bitmap("RussellDown.bmp");
    Left = al_load_bitmap("RussellLeft.bmp");
    Right = al_load_bitmap("RussellRight.bmp");
    al_convert_mask_to_alpha(Up, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Down, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Left, al_map_rgb(255, 255, 255));
    al_convert_mask_to_alpha(Right, al_map_rgb(255, 255, 255));

    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesTop[i].live){
            al_draw_bitmap(Up, enemiesTop[i].x, enemiesTop[i].y, 0);
        }//ends the if
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesDown[i].live){
            al_draw_bitmap(Down, enemiesDown[i].x, enemiesDown[i].y, 0);
        }//ends the if
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesLeft[i].live){
            al_draw_bitmap(Left, enemiesLeft[i].x, enemiesLeft[i].y, 0);
        }//ends the if
    }//ends the loop
    for(int i = 0 ; i < MAX_ENEMIES ; i++){
        if(enemiesRight[i].live){
            al_draw_bitmap(Right, enemiesRight[i].x, enemiesRight[i].y, 0);
        }//ends the if
    }//ends the loop
}//ends the function
