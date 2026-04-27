#include "ZOOrkEngine.h"
#include "TalkCommand.h"
#include <sstream>
#include <algorithm>
#include <utility>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start) {
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();

}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go") {
            handleGoCommand(arguments);
        } else if ((command == "look") || (command == "inspect")) {
            handleLookCommand(arguments);
        } else if ((command == "take") || (command == "get")) {
            handleTakeCommand(arguments);
        } else if (command == "drop") {
            handleDropCommand(arguments);
        } else if (command == "talk") {
            handleTalkCommand(arguments);
        } else if (command == "quit") {
            handleQuitCommand(arguments);
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north") {
        direction = "north";
    } else if (arguments[0] == "s" || arguments[0] == "south") {
        direction = "south";
    } else if (arguments[0] == "e" || arguments[0] == "east") {
        direction = "east";
    } else if (arguments[0] == "w" || arguments[0] == "west") {
        direction = "west";
    } else if (arguments[0] == "u" || arguments[0] == "up") {
        direction = "up";
    } else if (arguments[0] == "d" || arguments[0] == "down") {
        direction = "down";
    } else {
        direction = arguments[0];
    }

    Room* currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    player->setCurrentRoom(passage->getTo());
    passage->enter();
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        // see the current room
        std::cout << player->getCurrentRoom()->getDescription() << "\n";
    } else {
        // View the specified object
        std::string objectName = arguments[0];
        Item* item = player->getCurrentRoom()->getItem(objectName);
        if (item) {
            std::cout << item->getDescription() << "\n";
        } else {
            std::cout << "you did not see " << objectName << "。\n";
        }
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "You need to specify the item you want to pick up.\n";
    } else {
        std::string itemName = arguments[0];
        Room* currentRoom = player->getCurrentRoom();
        Item* item = currentRoom->retrieveItem(itemName);
        if (item) {
            player->addItem(item);
            std::cout << "You picked up " << item->getName() << "\n";
        } else {
            std::cout << "You didn't see " << itemName << "\n";
        }
    }
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "You need to specify the item you want to drop.\n";
    } else {
        std::string itemName = arguments[0];
        Item* item = player->getItem(itemName);
        if (item) {
            player->removeItem(itemName);
            player->getCurrentRoom()->addItem(item);
            std::cout << "You dropped up " << item->getName() << "\n";
        } else {
            std::cout << "You dont have " << itemName << "\n";
        }
    }
}

void ZOOrkEngine::handleTalkCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "You need to specify who you want to talk to.\n";
    } else {
        std::string npcName = arguments[0];
        NPC* npc = player->getCurrentRoom()->getNPC(npcName);
        if (npc) {
            std::cout << npc->getDescription() << "\n";
            std::cout << " " << "\n";
            std::cout << "The voice echoes throughout the room ~  " << "\n";
            TalkCommand talkCmd(npc);
            talkCmd.execute();
        } else {
            std::cout << "You don't see anyone named " << npcName << ".\n";
        }
    }
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        gameOver = true;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
