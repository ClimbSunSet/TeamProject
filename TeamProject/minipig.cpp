//minipig.cpp

#include "minipig.h"
#include <iostream>

minipig::minipig(int playerLevel) : Monster("귀여운미니피그", playerLevel)
{

}

void minipig::Attack()
{
	std::cout << "미니피그가 소심한 박치기로 공격했습니다! \n" << std::endl;
}
