//
// Created by Yx on 24-6-4.
//

#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>

class NPC {
public:
    NPC(const std::string& name, const std::string& description, const std::vector<std::string>& dialogues);
    const std::string& getName() const;
    void talk() const;
    const std::string& getDescription() const {
        return description;
    }

private:
    std::string name;
    std::string description;
    std::vector<std::string> dialogues;
};

#endif // NPC_H

