//
// Created by Yx on 24-6-4.
//

#ifndef TALKCOMMAND_H
#define TALKCOMMAND_H

#include "NPC.h"

class TalkCommand {
public:
    TalkCommand(NPC* npc) : npc(npc) {}
    void execute() const {
        npc->talk();
    }

private:
    NPC* npc;
};

#endif // TALKCOMMAND_H
