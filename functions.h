#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "classes.h"

void intro();
void describeRules();

void hotelArt();
void ghostArt();
void monsterArt();
void printLine();

int getChoice(int minChoice, int maxChoice);

void showStats(Player player);
void showInventory(Player player);

void showLocationMenu(vector<Location> locations, vector<int> visitedLocations);
int chooseLocation(vector<Location> locations, vector<int> visitedLocations);

vector<int> assignNotesToLocations(int totalNotes, int totalLocations);

bool playLocation(
    Player &player,
    Location location,
    vector<Note> notes,
    vector<int> &noteLocations,
    vector<int> &visitedLocations,
    int locationIndex
);

bool hideFromMonster(Location location);

void checkForNote(
    Player &player,
    vector<Note> notes,
    vector<int> &noteLocations,
    int locationIndex
);

bool allNotesFound(Player player, int totalNotes);

void ghostSpeak(string message);

string buildCorrectCode(vector<Note> notes);
bool lockedDoorPuzzle(Player player, vector<Note> notes);

void gameOver();
void ending(Player player);

#endif