// MiniPig.h

#pragma once

#include <iostream>
#include <string>

#include "Monster.h"

class MiniPig : public Monster
{
public:
    MiniPig(int level) : Monster(level, std::string("미니피그")) {}

	void Attack() override;
private:

};
