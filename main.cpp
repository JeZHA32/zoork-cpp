#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "NPC.h"
#include "TalkCommand.h"

int main() {
    std::shared_ptr<Room> start = std::make_shared<Room>("start-room",
                                                         "You are standing in an open field west of a white house, with a boarded front door.\n"
                                                         "No one is here except one Guard \n");

    std::shared_ptr<Room> south_of_house = std::make_shared<Room>("south-of-house",
                                                                  "You are facing the south side of a white house. There is no door here, and all the windows are barred.\n"
                                                                  "No one is here except one Farmer \n");

    std::shared_ptr<Room> behind_house = std::make_shared<Room>("behind-house",
                                                                "You are behind the white house. A path leads into the forest to the east. In one corner of the house there is a small window which is slightly ajar.\n"
                                                                "No one is here except one OldMan \n");

    std::shared_ptr<Room> forest_path = std::make_shared<Room>("forest-path",
                                                               "You are now in a dense forest. The path is dark and dense, with vines and branches hanging down.\n"
                                                               "No one is here except one Ranger \n");

    std::shared_ptr<Room> dark_forest = std::make_shared<Room>("dark-forest",
                                                               "You are in a dark forest. There is a faint light in the distance, but you cannot see what it is.\n"
                                                               "No one is here except one Hermit \n");

    std::shared_ptr<Room> old_temple = std::make_shared<Room>("old-temple",
                                                              "You have reached an old temple. The walls are crumbling, and the doors are hanging off their hinges.\n"
                                                              "No one is here except one TemplePriest \n");

    std::shared_ptr<Room> ancient_ruins = std::make_shared<Room>("ancient-ruins",
                                                                 "You are in the ancient ruins of a long-lost civilization. There are many crumbling structures and artifacts.\n"
                                                                 "No one is here except one Historian \n");

    std::shared_ptr<Room> hidden_chamber = std::make_shared<Room>("hidden-chamber",
                                                                  "You have found a hidden chamber deep in the ruins. There is a treasure chest in the center of the room.\n"
                                                                  "No one is here except one TreasureHunter \n");

    std::shared_ptr<Room> beach = std::make_shared<Room>("beach",
                                                         "You are standing on a sandy beach. The sun is setting, and the waves are crashing against the shore.\n"
                                                         "No one is here except one BeachComber \n");

    std::shared_ptr<Room> rocky_cliff = std::make_shared<Room>("rocky-cliff",
                                                               "You are standing on a rocky cliff. The wind is blowing strongly, and you can see the sea stretching out to the horizon.\n"
                                                               "No one is here except one Climber \n");

    std::shared_ptr<Room> sea_cave = std::make_shared<Room>("sea-cave",
                                                            "You are in a sea cave. The water is calm, and the cave is lit by a faint glow.\n"
                                                            "No one is here except one Sailor \n");


    Passage::createBasicPassage(start.get(), south_of_house.get(), "south", true);
    Passage::createBasicPassage(south_of_house.get(), behind_house.get(), "east", true);
    Passage::createBasicPassage(behind_house.get(), forest_path.get(), "east", true);
    Passage::createBasicPassage(forest_path.get(), dark_forest.get(), "east", true);
    Passage::createBasicPassage(dark_forest.get(), old_temple.get(), "north", true);
    Passage::createBasicPassage(old_temple.get(), ancient_ruins.get(), "east", true);
    Passage::createBasicPassage(ancient_ruins.get(), hidden_chamber.get(), "north", true);
    Passage::createBasicPassage(hidden_chamber.get(), beach.get(), "west", true);
    Passage::createBasicPassage(beach.get(), rocky_cliff.get(), "west", true);
    Passage::createBasicPassage(rocky_cliff.get(), sea_cave.get(), "west", true);

    // create some items
    std::shared_ptr<Item> key = std::make_shared<Item>("key", "A small silver key.");
    std::shared_ptr<Item> amulet = std::make_shared<Item>("amulet", "A magical amulet that can guide the player through darkness.");
    std::shared_ptr<Item> rock = std::make_shared<Item>("rock", "A heavy rock that could be used as a weapon.");
    std::shared_ptr<Item> compass = std::make_shared<Item>("compass", "A compass to help navigate the dark forest.");
    std::shared_ptr<Item> mushroom = std::make_shared<Item>("mushroom", "A glowing mushroom providing dim light.");
    std::shared_ptr<Item> dagger = std::make_shared<Item>("dagger", "A sacrificial dagger used in ancient rituals.");
    std::shared_ptr<Item> orb = std::make_shared<Item>("orb", "A mystical orb emitting mysterious light.");
    std::shared_ptr<Item> tome = std::make_shared<Item>("tome", "An ancient tome containing secrets of the lost civilization.");
    std::shared_ptr<Item> bottle = std::make_shared<Item>("bottle", "A message in a bottle washed ashore.");
    std::shared_ptr<Item> telescope = std::make_shared<Item>("telescope", "A telescope for observing distant ships and rocks.");
    std::shared_ptr<Item> pearl = std::make_shared<Item>("pearl", "A glowing pearl hidden deep within the cave.");

    // add Item into Room
    start->addItem(key.get());
    south_of_house->addItem(amulet.get());
    behind_house->addItem(rock.get());
    forest_path->addItem(compass.get());
    dark_forest->addItem(mushroom.get());
    old_temple->addItem(dagger.get());
    ancient_ruins->addItem(orb.get());
    hidden_chamber->addItem(tome.get());
    beach->addItem(bottle.get());
    rocky_cliff->addItem(telescope.get());
    sea_cave->addItem(pearl.get());

    // create NPCs
    std::vector<std::string> GuardDialogues = {
            "Hello, adventurer.",
            "Beware of the dangers ahead.",
            "Maybe you're looking for keys?"
    };
    NPC* Guard = new NPC("guard","This is a loyal guard.",GuardDialogues);
    start->addNPC(Guard);

    std::vector<std::string> FarmerDialogues = {
            "Hello, Traveler",
            "Maybe you're looking for Amulet"
    };
    NPC* Farmer  = new NPC("farmer","A friendly farmer in simple work clothes",FarmerDialogues);
    south_of_house->addNPC(Farmer);

    std::vector<std::string> OldmanDialogues = {
            "Ah, young man",
            "I remember there's a rock somewhere here, can you find it?"
    };
    NPC* Oldman = new NPC("oldman", "An elderly man with a gray beard",OldmanDialogues);
    behind_house->addNPC(Oldman);

    std::vector<std::string> RangerDialogues = {
            "Be careful on this forest path, adventurer."
            "There are many dangerous wild animals here.",
            "The compass will guide you"
    };
    NPC* Ranger = new NPC("ranger","A swift ranger in a green cape",RangerDialogues);
    forest_path->addNPC(Ranger);

    std::vector<std::string> HermitDialogues = {
            "Welcome to the forest.",
            "This place is full of secrets.",
            "There is a small mushroom on the ground"
    };
    NPC* Hermit = new NPC("hermit","A mysterious forest hermit.",HermitDialogues);
    dark_forest->addNPC(Hermit);

    std::vector<std::string> TemplepriestDialogues = {
            "This ancient temple hides countless treasures.",
            "Be careful of the trap here.",
            "A dagger is stuck in the stone tablet for offering to Buddha"
    };
    NPC* Templepriest = new NPC("templepriest","A solemn priestess, in white vestments",TemplepriestDialogues);
    old_temple->addNPC(Templepriest);

    std::vector<std::string> HistorianDialogues = {
            "These ancient ruins hold many legends.",
            "Would you like to hear one of them?",
            "A pale orb of hazy reddish light"
    };
    NPC* Historian = new NPC("historian","A knowledgeable historian wearing round-framed glasses",HistorianDialogues);
    ancient_ruins->addNPC(Historian);

    std::vector<std::string> TreasureHunterDialogues = {
            "Did you find this hidden room?",
            "Let's explore the secrets here together",
            "by the way do you tome?"
    };
    NPC* TreasureHunter = new NPC("treasurehunter","A savvy treasure hunter in handy expedition gear",TreasureHunterDialogues);
    hidden_chamber->addNPC(TreasureHunter);

    std::vector<std::string> BeachComberDialogues = {
            "Have you discovered the secret in this bottle?",
            "There are many treasures waiting to be discovered by the sea.",
            "Be careful of the dangerous rocky cliffs."
    };
    NPC* BeachComber = new NPC("beachcomber","A man who scavenges on the beach all year round.",BeachComberDialogues);
    beach->addNPC(BeachComber);

    std::vector<std::string> ClimberDialogues = {
            "This rock face is very dangerous, but the scenery is beautiful",
            "Do you dare to climb up with me?",
            "After we climb up, we can use the telescope to see the magnificent scenery."
    };
    NPC* Climber = new NPC("climber","A brave climber with a great body",ClimberDialogues);
    rocky_cliff->addNPC(Climber);

    std::vector<std::string> SailorDialogues = {
            "This sea cave hides many mysterious treasures.",
            "For example, this pearl",
            "Do you have the courage to explore?"
    };
    NPC* Sailor = new NPC("sailor","An experienced sailor in a blue and white striped sailor suit",SailorDialogues);
    sea_cave->addNPC(Sailor);



    ZOOrkEngine zoork(start);

    zoork.run();

    return 0;
}
