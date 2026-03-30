//goblin.cpp

#include "goblin.h"
#include <iostream>

goblin::goblin(int playerLevel) : Monster("고블린", playerLevel)
{

}
void goblin::Attack()
{
	std::cout << "고블린이 야만의 뭉둥이로 야만적이게 공격합니다! \n" << std::endl;
}
