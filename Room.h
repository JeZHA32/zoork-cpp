#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "NPC.h" // Include NPC header
#include "Location.h"
#include <map>
#include <vector>

class Passage;

class Room : public Location {
public:
    Room(const std::string &, const std::string &);

    Room(const std::string &, const std::string &, std::shared_ptr<Command>);

    void addItem(Item*);
    void removeItem(const std::string&);
    Item* retrieveItem(const std::string&);
    void addCharacter(Character*);
    void removeCharacter(const std::string&);
    Character* getCharacter(const std::string&);

    void addNPC(NPC*);
    void removeNPC(const std::string&);
    NPC* getNPC(const std::string&);

    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void removePassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string &);

    class Item* getItem(const std::string& name);

protected:
    std::vector<Item*> items;
    std::vector<Character*> characters;
    std::vector<NPC*> npcs; // Add a vector to store NPCs
    std::map<std::string, std::shared_ptr<Passage>> passageMap;
};

#endif //ZOORK_ROOM_H
