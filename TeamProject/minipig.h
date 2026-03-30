//minipig.h

#pragma once
#include "Monster.h"

class minipig : public Monster
{
public:
	minipig(int playerLevel);
	void Attack() override;
};

