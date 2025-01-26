#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

// Dichiara le funzioni
void step(int stepID, const char* text, int options, bool keepChoice);
void freedom();
void pickItem(const char* item);
void battle(const char* enemy);

// Variabili globali
extern int ID;
extern bool inGame;
extern int savedChoice;
extern int stage;
extern int inventory[];
extern int playerClass;
extern int playerGold;
#endif // ENGINE_H
