#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include "Item.h"
#include <vector>
#include <algorithm>

class Player : public Character {
public:
    static Player* instance() {
        if (!playerInstance) {
            playerInstance = new Player();
        }
        return Player::playerInstance;
    }

    void setCurrentRoom(Room*);
    Room* getCurrentRoom() const;
    void addItem(Item*);
    void removeItem(const std::string&);
    Item* retrieveItem(const std::string& itemName);

    // 将 getItem 方法声明为公有方法
    Item* getItem(const std::string& itemName);

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;


    bool hasItem(Item* item) {
        return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
    }

    void removeItem(Item* item) {
        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
        }
    }


private:
    static Player* playerInstance;
    Room* currentRoom;
    std::vector<Item*> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you."),
               currentRoom(new NullRoom()) {}
};

#endif //ZOORK_PLAYER_H