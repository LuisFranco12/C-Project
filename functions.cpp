#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "functions.h"

using namespace std;

void printLine() {
    cout << "\n==============================" << endl;
}

void hotelArt() {
    cout << "==============================" << endl;
    cout << "         ASHVALE HOTEL        " << endl;
    cout << "==============================" << endl;
}

void ghostArt() {
    cout << "\n   .-.   " << endl;
    cout << "  (o o)  " << endl;
    cout << "  | O |  " << endl;
    cout << "  |   |  " << endl;
    cout << "  '~~~'  " << endl;
}

void monsterArt() {
    cout << "\n      .-." << endl;
    cout << "     (o o)" << endl;
    cout << "     | O \\" << endl;
    cout << "      \\   \\" << endl;
    cout << "       `~~~'" << endl;
}

void intro() {
    printLine();

    cout << "BEEP... BEEP... BEEP..." << endl;
    cout << "A phone alarm screams beside your head." << endl;

    cout << "\nYou wake up on the floor of a hotel room." << endl;
    cout << "Your head is pounding." << endl;
    cout << "You do not remember your name or how you got here." << endl;

    ghostArt();

    cout << "\nA small ghost floats near the door." << endl;
    cout << "\"You're awake,\" she says. \"We need to move.\"" << endl;

    printLine();
}

void describeRules() {
    cout << "\nHOW TO PLAY:" << endl;
    cout << "- Choose locations to explore." << endl;
    cout << "- There are 8 notes hidden around the town." << endl;
    cout << "- The notes are placed randomly each time the game starts." << endl;
    cout << "- Each note gives part of the final 8-digit code." << endl;
    cout << "- Each location has a monster encounter." << endl;
    cout << "- To survive, choose the correct hiding spot." << endl;
    cout << "- If you choose the wrong hiding spot, the cycle restarts." << endl;
}

/*
    I made this function so the game does not break if the player types
    a bad number. The same function can be reused for menus and hiding choices.
*/
int getChoice(int minChoice, int maxChoice) {
    int choice;

    while (true) {
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number." << endl;
        }
        else if (choice < minChoice || choice > maxChoice) {
            cout << "Please choose between " << minChoice << " and " << maxChoice << "." << endl;
        }
        else {
            return choice;
        }
    }
}

void showStats(Player player) {
    cout << "\n--- STATUS ---" << endl;
    cout << "Notes Found: " << player.notesFound << "/8" << endl;
}

void showInventory(Player player) {
    cout << "\n--- NOTES FOUND ---" << endl;

    if (player.inventory.size() == 0) {
        cout << "You have not found any notes yet." << endl;
    }
    else {
        for (int i = 0; i < (int)player.inventory.size(); i++) {
            cout << "- " << player.inventory[i] << endl;
        }
    }
}

/*
    The player can choose where to go instead of being forced through
    the locations in order. Visited areas are marked to make navigation easier.
*/
void showLocationMenu(vector<Location> locations, vector<int> visitedLocations) {
    printLine();

    cout << "WHERE DO YOU WANT TO GO?" << endl;

    for (int i = 0; i < (int)locations.size(); i++) {
        cout << i + 1 << ". " << locations[i].locationName;

        if (visitedLocations[i] == 1) {
            cout << " (already searched)";
        }

        cout << endl;
    }

    cout << locations.size() + 1 << ". Check notes" << endl;
    cout << locations.size() + 2 << ". Check status" << endl;
}

int chooseLocation(vector<Location> locations, vector<int> visitedLocations) {
    showLocationMenu(locations, visitedLocations);

    int maxChoice = locations.size() + 2;

    return getChoice(1, maxChoice);
}

/*
    This randomly chooses which locations have notes. I check for duplicates
    so two notes do not get placed in the same location.
*/
vector<int> assignNotesToLocations(int totalNotes, int totalLocations) {
    vector<int> noteLocations;

    while ((int)noteLocations.size() < totalNotes) {
        int randomLocation = rand() % totalLocations;
        bool alreadyUsed = false;

        for (int i = 0; i < (int)noteLocations.size(); i++) {
            if (noteLocations[i] == randomLocation) {
                alreadyUsed = true;
            }
        }

        if (!alreadyUsed) {
            noteLocations.push_back(randomLocation);
        }
    }

    return noteLocations;
}

bool playLocation(
    Player &player,
    Location location,
    vector<Note> notes,
    vector<int> &noteLocations,
    vector<int> &visitedLocations,
    int locationIndex
) {
    printLine();

    cout << location.locationName << endl;

    printLine();

    cout << location.locationDescription << endl;

    ghostSpeak(location.ghostDialogue);

    if (visitedLocations[locationIndex] == 1) {
        cout << "\nYou already searched this area. There is nothing new here." << endl;
        return true;
    }

    visitedLocations[locationIndex] = 1;

    checkForNote(player, notes, noteLocations, locationIndex);

    cout << "\nThe air turns cold." << endl;
    cout << location.monsterName << " appears." << endl;
    cout << location.monsterDescription << endl;

    return hideFromMonster(location);
}

/*
    The correct hiding place is set in the Location object. I did this instead
    of randomizing it so the player has a fair chance based on the location.
*/
bool hideFromMonster(Location location) {
    monsterArt();

    cout << "\nWhere do you hide?" << endl;
    cout << "1. " << location.hidingSpot1 << endl;
    cout << "2. " << location.hidingSpot2 << endl;
    cout << "3. " << location.hidingSpot3 << endl;
    cout << "4. " << location.hidingSpot4 << endl;

    int choice = getChoice(1, 4);

    if (choice == location.correctHidingSpot) {
        cout << "\nYou hide just in time." << endl;
        cout << location.monsterName << " passes by without seeing you." << endl;
        return true;
    }
    else {
        cout << "\nYou picked the wrong hiding place." << endl;
        cout << location.monsterName << " finds you." << endl;
        return false;
    }
}

void checkForNote(
    Player &player,
    vector<Note> notes,
    vector<int> &noteLocations,
    int locationIndex
) {
    for (int i = 0; i < (int)noteLocations.size(); i++) {
        if (noteLocations[i] == locationIndex) {
            cout << "\nYou find a torn note:" << endl;
            cout << "\"" << notes[i].noteText << "\"" << endl;

            player.inventory.push_back(notes[i].noteText);
            player.notesFound++;

            noteLocations[i] = -1;

            return;
        }
    }

    cout << "\nYou search the area, but there is no note here." << endl;
}

bool allNotesFound(Player player, int totalNotes) {
    return player.notesFound == totalNotes;
}

void ghostSpeak(string message) {
    cout << "\nGhost: \"" << message << "\"" << endl;
}

/*
    The notes each contain one digit and one position. This function builds
    the real 8-digit code from the note information.
*/
string buildCorrectCode(vector<Note> notes) {
    string code = "00000000";

    for (int i = 0; i < (int)notes.size(); i++) {
        int position = notes[i].codePosition - 1;
        char digit = notes[i].codeDigit + '0';

        code[position] = digit;
    }

    return code;
}

/*
    This is the game-within-a-game using rand(). The code digits are generated
    randomly in main, hidden inside the notes, and the player must use the notes
    to open the final locked door.
*/
bool lockedDoorPuzzle(Player player, vector<Note> notes) {
    string correctCode = buildCorrectCode(notes);
    string playerCode;

    printLine();

    cout << "You return to the hotel." << endl;
    cout << "The locked door waits at the end of the hallway." << endl;
    cout << "It has an old keypad with space for 8 digits." << endl;

    cout << "\nThe ghost whispers:" << endl;
    cout << "\"The notes know the order. You just have to remember.\"" << endl;

    cout << "\nYour notes:" << endl;
    showInventory(player);

    cout << "\nEnter the 8-digit code: ";
    cin >> playerCode;

    if (playerCode == correctCode) {
        cout << "\nThe lock clicks open." << endl;
        return true;
    }
    else {
        cout << "\nThe keypad flashes red." << endl;
        cout << "From behind you, something laughs." << endl;
        return false;
    }
}

void gameOver() {
    printLine();

    cout << "GAME OVER" << endl;

    printLine();

    cout << "Everything goes black." << endl;
    cout << "You feel cold carpet beneath your body." << endl;
    cout << "BEEP... BEEP... BEEP..." << endl;
    cout << "You open your eyes." << endl;
    cout << "You are back in the hotel room." << endl;
}

void ending(Player player) {
    printLine();

    cout << "THE LOCKED ROOM" << endl;

    printLine();

    cout << "The door opens into the same hotel room where you first woke up." << endl;
    cout << "But now it is different." << endl;
    cout << "The phone alarm is still ringing." << endl;

    cout << "\nBEEP... BEEP... BEEP..." << endl;

    cout << "\nSomeone is pounding on the hallway door." << endl;
    cout << "The voices outside sound like police." << endl;
    cout << "\"Open the door!\" someone shouts." << endl;

    cout << "\nThe window is open." << endl;
    cout << "Cold air rushes into the room." << endl;

    cout << "\nThe notes in your hands finally connect." << endl;
    showInventory(player);

    cout << "\nYou remember enough now." << endl;
    cout << "You were not innocent." << endl;
    cout << "Someone died because of you." << endl;
    cout << "You ran from what you did." << endl;

    cout << "\nThe ghost floats beside the window." << endl;
    cout << "\"You always make it back here,\" she says." << endl;
    cout << "\"And you always forget why.\"" << endl;

    cout << "\nThe banging gets louder." << endl;
    cout << "You step toward the window without understanding why." << endl;

    cout << "\nThe ghost smiles." << endl;
    cout << "\"See you when the alarm rings.\"" << endl;

    cout << "\nA cold hand pushes you forward." << endl;
    cout << "The room disappears above you." << endl;

    cout << "\nBEEP... BEEP... BEEP..." << endl;
    cout << "You wake up on the floor of a hotel room." << endl;
}