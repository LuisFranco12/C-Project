#include <iostream>
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

    cout << "You wake up on the floor of a hotel room." << endl;
    cout << "Your head is pounding." << endl;
    cout << "You do not remember your name or how you got here." << endl;

    ghostArt();

    cout << "\nA small ghost floats near the door." << endl;
    cout << "\"You're awake,\" she says. \"We need to move.\"" << endl;

    printLine();
}

void describeRules() {
    cout << "\nHOW TO PLAY:" << endl;
    cout << "- This is a starter version of the game." << endl;
    cout << "- Locations are already stored in a vector." << endl;
    cout << "- Each location has a name, description, monster, and hiding spots." << endl;
    cout << "- More gameplay functions will be added later." << endl;
}