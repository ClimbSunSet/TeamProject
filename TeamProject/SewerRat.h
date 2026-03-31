// SewerRat.h

#pragma once

#include <iostream>
#include <string>

#include "Monster.h"

class SewerRat : public Monster
{
public:
	SewerRat(int level) : Monster(level, std::string("Ω√±√¡„")) {}

	void Attack() override;
private:
	
};

