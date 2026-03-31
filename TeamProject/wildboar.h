// WildBoar.h

#pragma once

#include <iostream>
#include <string>

#include "Monster.h"

class WildBoar : public Monster
{
public:
	WildBoar(int level) : Monster(level, std::string("¸äµÅÁö")) {};

	void Attack() override;
private:

};

