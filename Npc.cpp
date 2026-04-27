//
// Created by Yx on 24-6-4.
//
#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& description, const std::vector<std::string>& dialogues)
        : name(name), description(description), dialogues(dialogues) {}

const std::string& NPC::getName() const {
    return name;
}

void NPC::talk() const {
    for (const auto& dialogue : dialogues) {
        std::cout << dialogue << std::endl;
    }
}
