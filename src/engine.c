#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "engine.h"

/*Variabili intermediare*/
int ID = 0;
bool inGame = true;
int savedChoice = 0;
int stage = 1;

/*Dati*/
int enemyData[] = {10, 2}; //GRUPPI DI 2 NUMERI {VITA, DANNO}

/*Funzioni Generiche*/
char* mergeStrings(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

/*Funzioni specifiche dell'engine*/

// gestisce i vari step dell'avventura
void step(int stepID, const char* text, int options, bool keepChoice) {
    int choice = 0;
    if (ID == stepID) {
        printf("------------------------\n");
        printf("%s\n", text);
        // controlla se il player ha la possibilità di fare una scelta
        if (options > 0) {
            printf("What do you choose: \n");
            scanf("%d", &choice);
            ID += choice;
        } else {
            ID += 1;
        }
        // controlla se bisogna salvare la scelta
        if (keepChoice && options > 0) {
            savedChoice = choice;
        }
    }
}

void freedom() {
    ID = 0;
    while (true) {
        step(0, "You're now alone you can choose what to do\n 1: Go to a place\n 2: Open your map", 2, true);
        switch (savedChoice) {
            case 1:
                step(1, "Where do you want to go\n 1: Forest\n 2: Bar", 2, true);
                stage = savedChoice;
                return;
            case 2:
                printf("------------------------\n|           |\n|   castle   |\n|           |\n|           |\n|           |\n| bar village |\n|           |\n|           |\n|           |\n|   forest   |\n------------------------\n");
                ID = 0;
                break; // Mostra di nuovo il menu
            default:
                return;
        }
    }
}

void pickItem(const char* item) {
    if(item == "broom")
        inventory[0] = 0;

    printf(mergeStrings("congratulations you hust got a ", mergeStrings(item, "\n"))); //questa cosa è merdosa ma dovrebbe funzionare
}

void battle(const char* enemy) {
    ID = 0;
    int playerLife = 100;
    int playerDamage = 1 + inventory[0];
    int enemyLife;
    int enemyDamage;
    bool enemyAlive = true;

    // Prendi statistiche del nemico
    if (strcmp(enemy, "rat") == 0) {
        enemyLife = enemyData[0];
        enemyDamage = enemyData[1];
    }

    while (enemyAlive && playerLife > 0) {
        printf("%s is fighting you\n", enemy);
        step(0, "What do you do?\n 1: Attack\n 2: Magic\n 3: Run", 3, true);

        switch (savedChoice) {
            case 1: // Attacco
                printf("You attacked the %s\n", enemy);
                enemyLife -= playerDamage;
                printf("Enemy life: %d\n", enemyLife);
                break;

            case 2: // Magia
                switch (playerClass) {
                    case 1: // Elfo
                        printf("You used your flute to damage the enemy by 10 points\n");
                        enemyLife -= 10;
                        break;
                    case 2: // Mago
                        printf("You used a health spell to heal yourself by 30 points\n");
                        playerLife += 30;
                        break;
                    case 3: // Ladro
                        printf("You stole an item from the enemy\n");
                        pickItem("random_item"); // Puoi migliorare questa parte
                        break;
                    case 4: // Guerriero
                        printf("You used your fire punch to damage the enemy by 20 points\n");
                        enemyLife -= 20;
                        break;
                    default:
                        printf("You stole 10 gold from the enemy\n");
                        playerGold += 10;
                        break;
                }
                break;

            case 3: // Fuggi
                printf("You decided to run away!\n");
                enemyAlive = false;
                continue; // Esci immediatamente dal ciclo
        }

        if (enemyLife <= 0) {
            printf("You defeated the %s!\n", enemy);
            enemyAlive = false;
            break;
        }

        // Attacco del nemico
        if (enemyAlive) {
            printf("%s attacks!\n", enemy);
            playerLife -= enemyDamage;
            printf("Your life: %d\n", playerLife);
            ID = 0;
        }
    }

    if (playerLife <= 0) {
        printf("You have been defeated...\n");
        inGame = false; // Termina il gioco
    }
}
