// consumables.h

#pragma once
#include "Item.h"

//소모품 목록 

class HealthPotion : public Item {
public:
	HealthPotion() : Item("빨간 포션", 30, true) { effect_ = 50; }

	void Use() override {
		cout << ">> [사용] " << name_ << "을 사용했습니다! HP가 " << effect_ << " 회복됩니다." << endl;
	}
};

class ManaPotion : public Item {
public:
	ManaPotion() : Item("파란 포션", 100, true) { effect_ = 30; }

	void Use() override {
		cout << ">> [사용] " << name_ << "을 사용했습니다! MP가 " << effect_ << " 회복됩니다." << endl;
	}
};