#include "Room.h"
#include "NullPassage.h"
#include <algorithm>
#include <utility>

Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}

std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

void Room::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(), [&](Item* item) {
        return item->getName() == itemName;
    }), items.end());
}

Item* Room::getItem(const std::string& itemName) {
    auto it = std::find_if(items.begin(), items.end(), [&](Item* item) {
        return item->getName() == itemName;
    });
    return it != items.end() ? *it : nullptr;
}

Item* Room::retrieveItem(const std::string& itemName) {
    Item* item = getItem(itemName);
    if (item) {
        removeItem(itemName);
    }
    return item;
}

void Room::addCharacter(Character* character) {
    characters.push_back(character);
}

void Room::removeCharacter(const std::string& characterName) {
    characters.erase(std::remove_if(characters.begin(), characters.end(), [&](Character* character) {
        return character->getName() == characterName;
    }), characters.end());
}

Character* Room::getCharacter(const std::string& characterName) {
    auto it = std::find_if(characters.begin(), characters.end(), [&](Character* character) {
        return character->getName() == characterName;
    });
    return it != characters.end() ? *it : nullptr;
}

void Room::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

void Room::removeNPC(const std::string& npcName) {
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [&](NPC* npc) {
        return npc->getName() == npcName;
    }), npcs.end());
}

NPC* Room::getNPC(const std::string& npcName) {
    auto it = std::find_if(npcs.begin(), npcs.end(), [&](NPC* npc) {
        return npc->getName() == npcName;
    });
    return it != npcs.end() ? *it : nullptr;
}
