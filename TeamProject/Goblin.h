// Goblin.h

#pragma once

#include <iostream>
#include <string>

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level) : Monster(level, std::string("°íºí¸°")) {}

	void Attack() override;
private:

};

