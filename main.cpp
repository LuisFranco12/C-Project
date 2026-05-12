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
        - Added 7 more notes, so there are 8 total, 
        - Added 17 more locations, so there are 20 total,
        - Added 17 more monsters, so each location has one
        - 4 hiding spots for every location
        - Better creepy descriptions for each area and mosnter descriptions
        - write ghost diaolgue
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
        "A bloated figure covered in painted target circles. It never moves — but whatever it stares at begins to bleed."
    );
    
    Monster nurseWraith(
        "Nurse Wraith",
        "A nurse with no eyes, only sutured skin stretched over empty sockets. She moves only when you stop watching her."
    );

    Monster pyramidShadow(
        "Pyramid Shadow",
        "A massive shape dragging a rusted blade across the floor. Its helmet is fused to its skull. It does not hunt — it arrives."
    );

    Monster ashWalker(
        "The Ash Walker",
        "A child-sized figure made entirely of compacted ash and teeth. It crumbles slightly with every step, leaving a trail of bone dust."
    );

    Monster mirrorSelf(
        "The Mirror Self",
        "It looks exactly like you — but its movements lag two seconds behind. When it catches up, it won't stop."
    );

    Monster chainedDoctor(
        "The Chained Doctor",
        "A doctor suspended mid-air by hooks through his coat. He swings slowly, writing diagnoses in the air with a broken finger."
    );

    Monster fogCrawler(
        "The Fog Crawler",
        "A low, wide creature that moves flat against the ground. It is only visible in the fog. The fog is everywhere."
    );

    Monster stillMother(
        "The Still Mother",
        "A woman seated in a rocking chair that moves on its own. Her head is always turned away. If you see her face, she has already seen yours."
    );

    Monster hollowPriest(
        "The Hollow Priest",
        "A robed figure with a cavity where its chest should be. Inside the cavity, something small moves and reaches outward."
    );

    Monster rustTwin(

        "The Rust Twin",
        "Two bodies fused at the spine, walking in opposite directions. They are always arguing in a language made of static."
    );

    Monster inkChild(
        "The Ink Child",
        "A small figure that leaves black handprints on every surface it touches. It has been here longer than the building has."
    );

    Monster wardensGhost(
        "The Warden's Ghost",
        "A translucent figure in a guard's uniform carrying keys that open nothing. He patrols the same path he walked in life — in 1962."
    );

    Monster fleshLibrarian(

        "The Flesh Librarian",
        "A librarian whose body has been replaced with stacked books, all written in the same handwriting — yours."
    );

    Monster drowningWoman(
        "The Drowning Woman",
        "A woman perpetually soaking wet, leaving puddles on dry floors. Her mouth is always open. She is always mid-scream."
    );

    Monster bellTower(
        "The Bell Tower",
        "A creature shaped like a bell with human legs. When it rings, time in the room skips forward by three minutes."
    );

    Monster orderSoldier(
        "The Order Soldier",
        "A soldier in the cult's armor, moving with mechanical precision. His helmet visor reflects a version of this room that no longer exists."
    );

    Monster sealedJanitor(. 
        "The Sealed Janitor",
        "A janitor whose mouth and eyes have been sewn shut with thick thread. He mops the floor endlessly, cleaning blood that reappears behind him."
    );


    // create more notes usng simialr format
    vector<Note> notes = {

        Note("I woke up here before. I think I've been waking up here for years."),
        Note("The fog doesn't come from outside. It comes from inside the walls. I've seen it breathe."),
        Note("Hotel Room is always locked. I can hear someone pacing inside. The footsteps are too heavy to be human."),
        Note("Don't use the elevator. The doors open on a floor that isn't on any map."),
        Note("I found my own handwriting in a journal I've never owned. It says: 'You already know how this ends.'"),
        Note("The nurses know something is wrong with them. I saw one stop in the hallway and press her hands to her head like she was trying to remember who she was."),
        Note("The church bells ring at 3am even though the church burned down in 1976. I've counted. They always ring seven times."),
        Note("If you find the basement — don't go in. I went in. I left something down there that used to be part of me.")
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
        ),

        Location(
            "Hotel Basement",
            "Pipes groan overhead like something living. The boiler room is lit by a single orange emergency light, casting everything in the color of a dying fire. Water drips from the ceiling but never reaches the floor.",
            lazyBullsEye.monsterName,
            lazyBullsEye.monsterDescription,
            "Don't let it see you. Whatever it looks at long enough starts to break open.",
            "Behind the rusted boiler",
            "Inside the storage cage",
            "Under the collapsed shelving unit",
            "Behind the broken circuit panel"
        ),

        Location(
            "Hospital Entrance",
             "The automatic doors are frozen half-open, groaning against the wind that doesn't exist outside. Wheelchairs are stacked against the walls in formations that look almost intentional. The reception desk has been written on in black marker — the same word, hundreds of times: REMEMBER.",
            nurseWraith.monsterName,
             nurseWraith.monsterDescription,
             "Close your eyes briefly when you move. She only advances when watched.",
             "Behind the reception desk",
             "Inside a toppled wheelchair stack",
             "Behind the vending machine",
             "Under the waiting room bench"
        ),

        Location(
            "Hospital Corridor — Ward C",
            "Every door in Ward C has been sealed from the outside with nails and boards. The boards have been broken from the inside on three of them. Fluorescent lights buzz in morse code. No one has translated it.",
            pyramidShadow.monsterName,
            pyramidShadow.monsterDescription,
            "It doesn't rush. Hide before it rounds the corner.",
            "Inside a sealed supply closet",
            "Behind a collapsed patient gurney",
            "Inside an overturned linen cart",
            "Flat inside an empty patient room"
        ),

        Location(
            "Hospital Operating Theater",
            "The operating table sits under a surgical light that still functions, humming with clean white light that makes everything below it look exposed. Instruments are laid out in perfect order on a tray. A patient gown is draped on the table, still warm.",
            chainedDoctor.monsterName,
            chainedDoctor.monsterDescription,
            "It will diagnose you if it finds you. Don't be found.",
            "Behind the equipment cabinet",
            "Under the operating table",
            "Inside the scrub room",
            "Behind the anesthesia cart"
        ),

        Location(
            "Hospital Rooftop",
            "The fog sits so thick up here that the edges of the roof are invisible. The city below — if it still exists — cannot be seen or heard. A child's shoe sits at the center of the roof for no reason anyone has left behind.",
            ashWalker.monsterName,
            ashWalker.monsterDescription,
            "It leaves a trail. Don't step in the ash — it will know.",
            "Behind the rooftop access shed",
            "Inside the dead water tower",
            "Behind a cluster of HVAC units",
            "Flat against the low parapet wall"
        ),

        Location(
            "Brookhaven Psychiatric Ward",
            "Cells line both sides of a narrow corridor, each with a small window reinforced by wire glass. In many of them, the glass has been broken from inside. Crayon drawings cover every wall — all of them depicting the same figure standing in fog.",
            mirrorSelf.monsterName,
            mirrorSelf.monsterDescription,
            "Don't look at it directly. It learns from watching you.",
            "Inside an empty cell",
            "Behind the nurse's station desk",
            "Inside the medication storage room",
            "Under a toppled patient bed"
        ),

        Location(
            "Silent Hill Police Station",
            "The front desk is scattered with cold coffee and unfinished reports. A radio in the back emits static that occasionally breaks into something almost intelligible — a name, repeated. The holding cells are all open. One smells like it was recently occupied.",
            wardensGhost.monsterName,
            wardensGhost.monsterDescription,
            "It follows its old patrol route. Learn the route. Stay out of it.",
            "Inside an open holding cell",
            "Behind the evidence locker",
            "Under the dispatch desk",
            "Inside the locker room"
        ),

        Location(
            "Fog-Covered Main Street",
            "Businesses line both sides of the street, their windows dark and signage faded. Cars sit at odd angles, some with doors open, engines dead. The fog rolls in from the lake in waves. Nothing moves — but the fog shifts as if something just passed through it.",
            fogCrawler.monsterName,
            fogCrawler.monsterDescription,
            "It travels below your line of sight. Stay elevated if you can.",
            "Inside an abandoned storefront",
            "Behind a cluster of stopped cars",
            "Inside a toppled newspaper stand",
            "In a recessed building doorway"
        ),

        Location(
            "Lakeside Diner",
            "A half-eaten meal sits at the counter, fork still balanced on the plate. The jukebox in the corner plays a song from 1983 on a loop — the same eight seconds, over and over. The kitchen door swings slowly on its own.",
            stillMother.monsterName,
            stillMother.monsterDescription,
            "Don't let her face your direction. Back into your hiding spot slowly.",
            "Inside the walk-in freezer",
            "Under the counter",
            Inside the kitchen storage pantry",
            "Behind the jukebox"
        ),

        Location(
            "Toluca Lake Shore",
            "The lake is perfectly still and perfectly black. No wind moves its surface. The dock extends into the fog until it disappears. Chains hang from a rusted post at the water's edge — not anchoring anything. Just hanging.",
            drowningWoman.monsterName,
            drowningWoman.monsterDescription,
            "She follows water sounds. Don't splash. Don't cross puddles quickly.",
            "Behind the boathouse wall",
            "Inside the old boathouse",
            "Behind a cluster of dead reeds",
            "Beneath the rotted dock planks"
        ),

        Location(
            "Silent Hill Elementary School",
            "Desks are arranged in perfect rows as if class is still in session. The blackboard has a math problem written on it that never resolves — the chalk answer has been erased and rewritten so many times the board is worn smooth. A child's laughter loops somewhere in the vents.",
            inkChild.monsterName,
            inkChild.monsterDescription,
            "It follows handprints. Don't touch the walls.",
            "Inside the supply closet off room 3",
            "Under the teacher's desk",
            "Behind the gym equipment curtain",
            "Inside the darkroom in the art wing"
        ),

        Location(
            "Midwich Elementary — Basement Level",
            "The basement was converted into something that doesn't have a clean name. The boiler is covered in painted symbols. Hooks hang from the ceiling at different heights. A single child-sized chair sits in the center of the room facing a wall.",
            hollowPriest.monsterName,
            hollowPriest.monsterDescription,
            "Don't stand between it and the symbols on the wall.",
            "Behind the old boiler",
            "Inside a storage closet",
            "Under a collapsed shelf",
            "Behind a hanging curtain of chains"
        ),

        Location(
            "Alchemilla Hospital — Pharmacy",
            "Pill bottles cover every shelf, labels all typed with the same patient name. The pharmacist's log has entries that go back sixty years but the handwriting never changes. A radio on the shelf plays static that sounds like breathing.",
            fleshLibrarian.monsterName,
            fleshLibrarian.monsterDescription,
            "It reads. While it reads, it doesn't move. Find cover before it finishes the page.",
            "Behind the pharmacy counter",
            "Inside the locked drug cabinet",
            "Under the rolling medication cart",
            "Behind the tall shelving unit"
        ),

        Location(
            "The Grand Hotel Ballroom",
            "The ballroom is perfectly preserved under a layer of dust thick enough to show footprints — footprints in a waltz pattern that lead to the center of the floor and stop. The chandelier overhead holds two hundred unlit candles. They smell recently blown out.",
            rustTwin.monsterName,
            rustTwin.monsterDescription,
            "They argue constantly. Use the noise to mask your movement.",
            "Behind the stage curtain",
            "Under the bandstand",
            "Inside the coat check room",
            "Behind the bar counter"
        ),

        Location(
            "Silent Hill Church",
            "Pews are arranged facing an altar that holds no religious symbol — only a mirror, angled slightly downward. Candles burn without being lit by anyone. The stained glass windows depict scenes from no scripture anyone has identified.",
            orderSoldier.monsterName,
            orderSoldier.monsterDescription,
            "It moves in response to sound, not sight. Step with the organ music.",
            "Inside the confession booth",
            "Behind the altar",
            "In the bell tower stairwell",
            "Under a collapsed pew"
        ),

        Location(
            "Silent Hill Historical Society",
            "Display cases line the room, each containing objects from the town's past — a doll, a key, a photograph face-down. The plaques beneath each item are written in a language that looks like English until you try to read it. A grandfather clock ticks in the corner. It has no hands.",
            bellTower.monsterName,
            bellTower.monsterDescription,
            When it rings, stop moving entirely. Time will skip. Be somewhere safe before it does.",
            "Inside the archive storage room",
            "Behind a display case",
            "Under the curator's desk",
            "Inside the map room"
        ),

        Location(
            "Nowhere — The Final Room",
            "The walls are made of something that isn't quite flesh and isn't quite concrete. The ceiling breathes. Every door in this room leads back to a place you've already been. In the center is a chair, a lamp, and a note that says: 'You should not have come back here. You always come back here.'",
            sealedJanitor.monsterName,
            sealedJanitor.monsterDescription,
            "It cleans obsessively. Let it finish its loop before you cross the room.",
            "Behind the pulsing wall membrane",
            "Inside the door-shaped void in the corner",
            "Under the sinking floor panel",
            "Behind the only real door — which is locked"
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