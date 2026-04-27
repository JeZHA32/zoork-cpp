#include "Player.h"

Player* Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::removeItem(const std::string& itemName) {
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(), [&](Item* item) {
        return item->getName() == itemName;
    }), inventory.end());
}

Item* Player::retrieveItem(const std::string& itemName) {
    Item* item = getItem(itemName);
    if (item) {
        removeItem(itemName);
    }
    return item;
}

Item* Player::getItem(const std::string& itemName) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](Item* item) {
        return item->getName() == itemName;
    });
    return it != inventory.end() ? *it : nullptr;
}