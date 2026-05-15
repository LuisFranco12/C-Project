#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "classes.h"
#include "functions.h"

using namespace std;

/*
    Project: Wretched

    This game was inspired by Silent Hill.
    The classes, story, locations, monsters, and ghost dialogue were created Mainly by Faysal.

    I mainly worked on the main C++ structure and gameplay systems, including the
    inventory, random note placement, location selection, and hiding mechanic.

    AI was used only for help with a few complicated programming areas, mainly:
    - assigning the 5 notes randomly to different locations without duplicates
    - checking player input so invalid choices do not break the game
    - organizing the multi-file structure with classes.h, functions.h, and functions.cpp(It was really unorganized)
*/

/* 
    Resources We used:
    https://medium.com/%40fulton_shaun/building-my-first-c-text-adventure-game-part-1-the-bare-bones-setup-c1a3f801633c
    https://gamedev.net/forums/topic/692415-c-text-adventure-design/
    https://gamecodeschool.com/c-plus-plus/coding-a-simple-text-adventure-in-c/
    https://cplussplussatplay.blogspot.com/2012/11/text-adventure-games-c-part-1.html
    https://community.gamedev.tv/t/trying-to-make-a-simple-text-adventure-to-practice-c/108165

*/

int main() {
    srand(time(0));

    Player player;

    /*
        The monsters are separate objects so the locations stay easier to read.
        Each location uses one monster name and description.
    */
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

    Monster nurseWraith(
        "Nurse Wraith",
        "A nurse with no eyes, only stitched skin stretched over empty sockets."
    );

    Monster fogCrawler(
        "The Fog Crawler",
        "A low creature that moves flat against the ground and disappears into the fog."
    );

    Monster mirrorSelf(
        "The Mirror Self",
        "It looks like you, but its movements happen a few seconds too late."
    );

    Monster hollowPriest(
        "The Hollow Priest",
        "A robed figure with an empty chest. Something inside it reaches outward."
    );

    Monster finalWatcher(
        "The Final Watcher",
        "A shadow standing completely still, waiting for you to remember."
    );

    Monster ashWalker(
        "The Ash Walker",
        "A child-sized figure made of ash and teeth."
    );

    Monster drownedWoman(
        "The Drowning Woman",
        "A soaking wet figure that leaves puddles on dry floors."
    );

    Monster oldTeacher(
        "The Old Teacher",
        "A teacher whose neck bends backward while she writes on the board."
    );

    Monster graveKeeper(
        "The Grave Keeper",
        "A man digging graves that already have names carved into them."
    );

    /*
        The code digits are randomized here. The notes will reveal these digits
        and their positions. This makes the final lock puzzle different each run.
    */
    int digit1 = rand() % 10;
    int digit2 = rand() % 10;
    int digit3 = rand() % 10;
    int digit4 = rand() % 10;
    int digit5 = rand() % 10;

    vector<Note> notes = {
        Note("The first number is " + to_string(digit1) + ". I woke up here before.", 1, digit1),
        Note("The second number is " + to_string(digit2) + ". The town does not trap strangers. It traps the guilty.", 2, digit2),
        Note("The third number is " + to_string(digit3) + ". Someone begged me to stop.", 3, digit3),
        Note("The fourth number is " + to_string(digit4) + ". Every time I die, I forget again.", 4, digit4),
        Note("The fifth number is " + to_string(digit5) + ". I was never the victim.", 5, digit5)
    };

    /*
        We understand that it may seem a little weird that the player can leave the
        hotel room and hotel in general safely, while choosing to stay in the room
        or go into the hallway can cause a monster encounter to appear.

        We reused the hotel room and hallway to give us more locations/decision points
        because without them the notes appeared a little too quickly, and we could not
        think of many more unique locations for the project 😭
    */

    vector<Location> locations = {
        Location(
            "Hotel Room",
            "You stand in the hotel room where you first woke up. The mirror is cracked.",
            thinMan.monsterName,
            thinMan.monsterDescription,
            "Stay quiet. It hears breathing.",
            "Under the bed",
            "Inside the closet",
            "Behind the curtains",
            "In the bathtub",
            2
        ),

        Location(
            "Hotel Hallway",
            "The hallway stretches farther than it should. The carpet is stained dark red.",
            bellhop.monsterName,
            bellhop.monsterDescription,
            "Do not look at its face. Just hide.",
            "Behind a luggage cart",
            "Inside room 206",
            "Behind the ice machine",
            "Under the torn carpet",
            1
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
            "Under a lobby table",
            1
        ),

        Location(
            "Hospital Entrance",
            "The hospital doors slide open before you touch them.",
            nurseWraith.monsterName,
            nurseWraith.monsterDescription,
            "She moves when you stop watching.",
            "Behind the reception desk",
            "Inside the supply closet",
            "Under the waiting room chairs",
            "Behind the vending machine",
            2
        ),

        Location(
            "Foggy Alley",
            "The alley is narrow and filled with fog so thick you can barely see.",
            fogCrawler.monsterName,
            fogCrawler.monsterDescription,
            "The fog is not hiding it. The fog is part of it.",
            "Behind the dumpster",
            "Inside the broken doorway",
            "Under the fire escape stairs",
            "Behind stacked crates",
            3
        ),

        Location(
            "Mirror Shop",
            "Every mirror shows the same room, but none of them show you correctly.",
            mirrorSelf.monsterName,
            mirrorSelf.monsterDescription,
            "If it catches up to your reflection, run.",
            "Behind the tall mirror",
            "Inside the back storage room",
            "Under the checkout counter",
            "Behind the broken display",
            2
        ),

        Location(
            "Church",
            "The church is burned, but candles still glow along the aisle.",
            hollowPriest.monsterName,
            hollowPriest.monsterDescription,
            "This place was never holy.",
            "Behind the altar",
            "Inside the confession booth",
            "Under a pew",
            "Behind the organ",
            2
        ),

        Location(
            "School Hallway",
            "Lockers slam open and shut by themselves.",
            oldTeacher.monsterName,
            oldTeacher.monsterDescription,
            "Some lessons repeat until they are learned.",
            "Inside a locker",
            "Behind the trophy case",
            "Under a desk",
            "Beside the exit doors",
            1
        ),

        Location(
            "Burned Playground",
            "Ash covers the slide like snow. The swings move even though there is no wind.",
            ashWalker.monsterName,
            ashWalker.monsterDescription,
            "Small things can still be dangerous.",
            "Inside the plastic tunnel",
            "Behind the swing set",
            "Under the slide",
            "Behind the dead tree",
            3
        ),

        Location(
            "Flooded Basement",
            "Black water covers the floor. Something moves beneath the surface.",
            drownedWoman.monsterName,
            drownedWoman.monsterDescription,
            "Do not let her hear you breathe.",
            "Behind the boiler",
            "Inside the storage closet",
            "Under the staircase",
            "Behind the washing machine",
            1
        ),

        Location(
            "Graveyard",
            "Every grave has the same date carved into it.",
            graveKeeper.monsterName,
            graveKeeper.monsterDescription,
            "He is still making room for you.",
            "Behind a tombstone",
            "Inside an open grave",
            "Behind a dead tree",
            "Beside the iron gate",
            1
        ),

        Location(
            "Final Chamber",
            "The town ends here. The walls are covered in notes written by your own hand.",
            finalWatcher.monsterName,
            finalWatcher.monsterDescription,
            "This is where you always remember.",
            "Behind the stone pillar",
            "Inside the broken doorway",
            "Under the altar",
            "There is nowhere to hide",
            4
        )
    };

    vector<int> visitedLocations(locations.size(), 0);

    vector<int> noteLocations = assignNotesToLocations(notes.size(), locations.size());

    hotelArt();
    intro();
    describeRules();

    /*
        The main loop continues until the player finds all 5 notes.
        After that, the final locked door puzzle starts.
    */
    while (!allNotesFound(player, notes.size())) {
        int choice = chooseLocation(locations, visitedLocations);

        if (choice == (int)locations.size() + 1) {
            showInventory(player);
        }
        else if (choice == (int)locations.size() + 2) {
            showStats(player);
        }
        else {
            int locationIndex = choice - 1;

            bool survived = playLocation(
                player,
                locations[locationIndex],
                notes,
                noteLocations,
                visitedLocations,
                locationIndex
            );

            if (!survived) {
                gameOver();
                return 0;
            }
        }
    }

    bool unlockedDoor = lockedDoorPuzzle(player, notes);

    if (!unlockedDoor) {
        gameOver();
        return 0;
    }

    ending(player);

    return 0;
}