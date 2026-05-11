#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "classes.h"
#include "functions.h"

using namespace std;

int main() {
    
    /*
        Add:
        - 7 more notes, so there are 8 total
        - 17 more locations, so there are 20 total
        - 17 more monsters, so each location has one
        - 4 hiding spots for every location
        - Better creepy descriptions for each area and mosnter descriptions
        - write ghost diaolgue
        gfdgdfg
    */

    srand(time(0));

    Player player;


    // create more mosnters here, using similar format
    Monster thinMan(
        "The Thin Man",
        "A tall figure with arms too long for its body. Its head scrapes the ceiling when it moves."
    );

    Monster bellhop(
        "The Bellhop",
        "A faceless hotel worker dragging a suitcase that leaks black liquid."
    );

    Monster smilingClerk(
        "The Smiling Clerk",
        "A clerk whose smile is carved too wide into his face."
    );
    
    Monster lazyBullsEye(
        "The Lazy BullsEye",
        "A figure who never misses his throwing stuffs is too lazy to throw."
    );
    


    // create more notes usng simialr format
    vector<Note> notes = {

        Note("I woke up here before.")

    };



    // create more locations here, using similar format
    vector<Location> locations = {

        Location(

            "Hotel Room",

            "You begin in a dusty hotel room. The mirror is cracked.",

            thinMan.monsterName,

            thinMan.monsterDescription,

            "Stay quiet. It hears breathing.",

            "Under the bed",
            "Inside the closet",
            "Behind the curtains",
            "In the bathtub"
        ),

        Location(

            "Hotel Hallway",

            "The hallway stretches farther than it should.",

            bellhop.monsterName,

            bellhop.monsterDescription,

            "Don't look at its face. Just hide.",

            "Behind a luggage cart",
            "Inside room 206",
            "Behind the ice machine",
            "Under the torn carpet"
        ),

        Location(

            "Hotel Lobby",

            "The front desk is empty. A silver bell rings by itself.",

            smilingClerk.monsterName,

            smilingClerk.monsterDescription,

            "It knows we are here. Move carefully.",

            "Behind the front desk",
            "Inside the elevator",
            "Behind a dead plant",
            "Under a lobby table"
        )

    };



    // GAME START
    hotelArt();

    intro();

    describeRules();



    // CURRENT LOCATIONS
    cout << "\nCURRENT LOCATIONS LOADED:" << endl;

    for (int i = 0; i < locations.size(); i++) {

        printLine();

        cout << "Location " << i + 1 << ": "
             << locations[i].locationName << endl;

        cout << locations[i].locationDescription << endl;

        cout << "Monster: "
             << locations[i].monsterName << endl;

        cout << "Monster Description: "
             << locations[i].monsterDescription << endl;

        cout << "Ghost: \""
             << locations[i].ghostDialogue << "\"" << endl;


        cout << "\nHiding spots:" << endl;

        cout << "1. "
             << locations[i].hidingSpot1 << endl;

        cout << "2. "
             << locations[i].hidingSpot2 << endl;

        cout << "3. "
             << locations[i].hidingSpot3 << endl;

        cout << "4. "
             << locations[i].hidingSpot4 << endl;
    }

    printLine();

    cout << "\nStarter version finished successfully." << endl;

    return 0;
}