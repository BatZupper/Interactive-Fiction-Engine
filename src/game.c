#include <stdio.h>
#include "engine.h"

//variabili del player
int playerClass;
char playerName[16];
int playerGold = 0;
int inventory[10] = {0};

int main() {
    while(inGame) {
        //fai scegliere la classe al giocatore
        step(0, "???: Welcome young boy first of all choose your class\n 1: Elf\n 2: Wizard\n 3: Thief\n 4: Warrior", 4, true);
        playerClass = savedChoice;
        //stampa il messaggio a seconda della classe del player
        switch (ID)
        {
            //printa il testo giusto asseconda della classe
            case 1:
                step(1, "???: So you're an Elf welcome in the land of Raonesia", 0, false);
                ID = 5;
                break;
            case 2:
                step(2, "???: So you're a Wizard welcome in the land of Raonesia", 0, false);
                ID = 5;
                break;
            case 3:
                step(3, "???: So you're a Thief welcome in the land of Raonesia", 0, false);
                ID = 5;
                break;
            case 4:
                step(4, "???: So you're a Warrior welcome in the land of Raonesia", 0, false);
                ID = 5;
                break;
            
            default:
                ID = 5;
                break;
        }
        step(5, "Stranger: Hello there young man are you new in this town?\n 1: Yes 2: No", 2, false);
        if(ID == 6)
            step(6, "Stranger: Hell yeah is always good to see new faces around here. But before we start a question what's your name?", 0, false);
        else
            step(7, "Stranger: Really?! I never saw you around anyway what's your name?", 0, false);

        ID = 8;
        printf("Insert your name: ");
        scanf("%s", &playerName);
        step(8, "Miky: That's a pretty name I'm Miky catch me later at the bar I'll buy you a beer.\n 1: Ok see you later\n 2: I don't know where the bar is", 2, false);
        if (ID == 10)
            step(10,"Miky: Just look in your map it should be in your backpack", 0, false);
        //prima volta dove il giocatore è effetivamente fuori dei dialoghi
        freedom();

        if(stage == 2) {
            ID = 11;
            step(11,"Miky: Here you are finaly! Bartender one large beer for my friend\n 1: Go to Miky", 1, false);
            step(12,"Bartender: So new in town kid? I suppose you have no money\n 1: You're right i came here for maybe finding a job and some new opportunites in life\n 2: Actually i do have money", 2, false);
            if(ID == 13)
                step(13, "I knew it! Don't worry for today the drink is on Miky but if you want to start making some money take this broom and go kill a bunch of rats in my basement\n 1: Ok thanks", 1, false);
            else
                step(14, "I know you're lying. But don't worry for today the drink is on Miky but if you want to start making some money take this broom and go kill a bunch of rats in my basement\n 1: Ok thanks", 1, false);
            ID == 15;
            pickItem("broom");
            step(15, "You entered the basement and started going down the stairs", 0, false);
            battle("rat");
            ID = 16;
            step(16, "Bartender: You did it boy thanks for killing the rats now i imagine you want your reward\n 1: Yes how much are we talking\n 2: No man you can keep them", 2, false);
            if(ID == 17) {
                step(17, "Max i can do is 10g", 0, false);
                playerGold += 10;
                ID = 19;
            }
            else {
                step(18, "Since you where so kind I'm going to give you 30g", 0, false);
                playerGold += 30;
                ID = 19;
            }
        }
        //quando finisce annulla il loop del gioco
        inGame = false;
    }

    return 0;
}