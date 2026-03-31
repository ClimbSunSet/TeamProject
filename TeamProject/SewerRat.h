// SewerRat.h

#pragma once

#include <iostream>
#include <string>

#include "Monster.h"

class SewerRat : public Monster
{
public:
    SewerRat(int level) : Monster(level, std::string("시궁쥐")) {}

	void Attack() override;
private:
	
};

