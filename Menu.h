#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <windows.h>
using namespace std;

int menu(int);
int characterChoice(int, int);
void instructions(int);
int backgroundChoice(int, int);



/* Gives out instructions on how
   to play the game.
   prerequisites: none
   parameters: choice
   returns nothing
   changes nothing      */
void instructions(int choice){
cout << "How to play:\n"
     << "--------------------\n"
     << "Russell clones have chased you and you must try to fight them "
     << "off and survive\nfor as long as you can, Russell will float in from all "
     << "directions, you have\nenough health to survive about 5 hits, afterwards you will be "
     << "given a score.\n"
     << endl
     << "----------KEYS---------\n"
     << "W - Move Up\n"
     << "A - Move Left\n"
     << "S - Move Down\n"
     << "D - Move Right\n"
     << "Up Arrow - Fire Up\n"
     << "Left Arrow - Fire Left\n"
     << "Down Arrow - Fire Down\n"
     << "Right Arrow - Fire Right\n"
     << "Escape - Ends the Game\n"
     << endl;
     system("pause");
     system("CLS");
}//ends the function

/*
1)Start Game
2)Select Difficulty
3)How to Play
4)Background Select
5)Quit Game
No Prerequisites
Parameter: Choice
Returns: Player Choice
Post: Changes the users choice inside.
*/
int menu(int choice) {
do{
    cout << "Please make a selection:\n"
         << "1)Start Game\n"
         << "2)Select Character\n"
         << "3)How to Play\n"
         << "4)Background Select\n"
         << "5)Quit Game\n";
    cin >> choice;
    if(choice < 1 || choice > 5){
        system("CLS");
        cout << "Invalid entry  --  Please try again.\n";
        Sleep(1200);
        system("CLS");
    }//ends the if
}while(choice <= 0 || choice >= 6); //Input Validation

return choice;
}//ends the function

/*Allows the user to
select his character
No prerequisites
Parameters: choice, and character
returns the character
changes the character
*/
int characterChoice(int choice, int character){
    do{
        cout << "Choose your character:\n"
             << "1)Gunner\n"
             << "2)Ninja\n"
             << "3)Russell\n"
             << "4)Wizard\n";
        cout << "\n*Note: character hit boxes are a little messed up.\n";
        cin >> character;
        if(character < 1 || character > 4){
            system("CLS");
            cout << "Not a valid character -- Try again.\n";
            Sleep(1200);
            system("CLS");
        }//ends the if
    }while(character < 1 || character > 4);
    system("pause");
    system("CLS");
    return character;
}//ends the function

/*Allows the user to
select his stage
No prerequisites
Parameters: choice, and background
returns the character
changes the character
*/
int backgroundChoice(int choice, int background){
    do{
        cout << "Choose your background:\n"
             << "1)Microsoft Paint Forest\n"
             << "2)Space\n";
        cin >> background;
        if(background < 1 || background > 2){
            system("CLS");
            cout << "Not a valid background -- Try again.\n";
            Sleep(1200);
            system("CLS");
        }
    }while(background < 1 || background > 2);
    system("pause");
    system("CLS");
    return background;
}


#endif // MENU_H_INCLUDED
