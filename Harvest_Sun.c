#include <stdio.h>

void goHome(int *day, int *gold, int *energy, int *hunger, int *gameLoop){
    if (*gold >= 10){
        *energy = 30;
        *gold -= 10;
    }
    else{
        *hunger-=1;
    }

    printf("You went Home!");
}

 void goFarm(int *day, int *gold, int *energy, int *hunger){
    int farmLoop = 0;
    
    while (farmLoop == 0 || energy <= 0){
        printf("You went to the Farm!\n\n"
                "You went to the Farm!:\n"
                " Available Plots: %d\n"
                " Tilled Plots: %d\n"
                " Water: %s\n"
                " Harvest: %s\n\n"
                "Choose action: ",
           *n, *age, *role, *status);

            
        printf("[1] Till plots\n[2] Sow Seeds\n[3] Water Crops\n[4] Harvest Crops\n[5]Buy Seeds\n[6] Sell Crops\n[7] Leave Farm");

        switch(farmLoop){
            case 1:
                
            case 2:
        }
        
    }
    
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

    //Farm stats
    int plots = 30;
    int tilledPlots = 0;
    int tomatoes;
    int corn;
    int strawberries;
    
    

	gameStart(&day, &gold, &energy, &hunger, &gameLoop);
	
	while (gameLoop == 1){

        if (hunger == 0){
        gameLoop = 0;
    }
        
        printf(" \n\n This is in main \n\nDay: %d | Gold: %d | Energy: %d | Hunger: %d/3\n", day, gold, energy, hunger);
        options(&day, &gold, &energy, &hunger, &gameLoop);
	}

    if(hunger <= 0){
	printf("Game over! You fainted from hunger!");
    }

    
    return 0;
}
