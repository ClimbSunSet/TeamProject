//wildboar.cpp

#include "wildboar.h"
#include <iostream>

wildboar::wildboar(int playerLevel) : Monster("멧돼지", playerLevel)
{

}

void wildboar::Attack()
{
	std::cout << "멧돼지가 전 미니피그와는 다르게 강한 박치기로 공격합니다. \n" << std::endl;
}
