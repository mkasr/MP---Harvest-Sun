#include <stdio.h>

void goHome(int *day, int *gold, int *energy, int *hunger, int *gameLoop){
    if (*gold >= 10){
        *energy = 30;
        *gold -= 10;
    }
    else{
        *hunger-=1;
    }

    if (*hunger == 0){
        *gameLoop = 1;
    }
    printf("You went Home!");
}

 void goFarm(){
    printf("You went to the Farm!");
}

 void goShop(){
    printf("You went Shopping!");  
}

  void quit(int *gameLoop){
	*gameLoop = 0;
    printf("Exiting Game!");
}

void options(int *day, int *gold, int *energy, int *hunger, int *gameLoop){
    int choice;
    
    printf("What would you like to do?\n[1] Go Home -- rest up and call it a day\n[2] Go to the Farm -- tend to your fields\n[3] Go to the Shop -- buy seeds and/or sell crops\n[0] Quit\n\n");
    scanf(" %d", &choice);

    switch (choice){
        case 1:
            goHome(day, gold, energy, hunger, gameLoop);
            break;
        case 2:
            goFarm();
            break;
        case 3:
            goShop();
            break;
        case 0:
            quit(gameLoop);
            break;
        default:
            //loop the question
            break;
    }
}

void gameStart(int *day, int *gold, int *energy, int *hunger, int *gameLoop){
    *day = 1; *gold = 50; *energy = 30; *hunger = 3;
    printf("Welcome to Harvest Sun!\n\nYou arrive in town bright-eyed and ready for a fresh start, having already eaten a hearty breakfast to power you through your first morning.\n\n");
    printf("Day: %d | Gold: %d | Energy: %d | Hunger: %d/3 \n\n", *day, *gold, *energy, *hunger);

    options(day, gold, energy, hunger, gameLoop);
}


int main() {

    //Player stats
    int day, gold, energy, hunger;
    
	//Game stats
	int gameLoop = 1;

	gameStart(&day, &gold, &energy, &hunger, &gameLoop);
	
	while (gameLoop == 1){
        printf(" \n\n This is in main \n\nDay: %d | Gold: %d | Energy: %d | Hunger: %d/3\n", day, gold, energy, hunger);
        options(&day, &gold, &energy, &hunger, &gameLoop);
	}
	
    return 0;
}
