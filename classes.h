#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

using namespace std;

class Player {
public:
    int bullets = 1;
    int notesFound = 0;
    vector<string> inventory;
};

class Monster {
public:
    string monsterName;
    string monsterDescription;

    Monster(string newMonsterName, string newMonsterDescription) {
        monsterName = newMonsterName;
        monsterDescription = newMonsterDescription;
    }
};

class Note {
public:
    string noteText;

    Note(string newNoteText) {
        noteText = newNoteText;
    }
};

class Location {
public:
    string locationName;
    string locationDescription;
    string monsterName;
    string monsterDescription;
    string ghostDialogue;

    string hidingSpot1;
    string hidingSpot2;
    string hidingSpot3;
    string hidingSpot4;

    Location(
        string newLocationName,
        string newLocationDescription,
        string newMonsterName,
        string newMonsterDescription,
        string newGhostDialogue,
        string newHidingSpot1,
        string newHidingSpot2,
        string newHidingSpot3,
        string newHidingSpot4
    ) {
        locationName = newLocationName;
        locationDescription = newLocationDescription;
        monsterName = newMonsterName;
        monsterDescription = newMonsterDescription;
        ghostDialogue = newGhostDialogue;

        hidingSpot1 = newHidingSpot1;
        hidingSpot2 = newHidingSpot2;
        hidingSpot3 = newHidingSpot3;
        hidingSpot4 = newHidingSpot4;
    }
};

#endif