// equipments.h //장비 착용 해제 기능하려면 나중에 방어구 무기로 한번더 나눠야할듯합니다

#pragma once
#include "Item.h"

// 아이템 목록

class OneHandSword : public Item {
public:
	OneHandSword() : Item("한손검", 300, false) { effect_ = 15; }

	void Use() override {
		cout << ">> [장착] " << name_ << "을 장착했습니다. 공격력 +" << effect_ << endl;
	}

	void Unequip() override {
		cout << ">> [해제] " << name_ << "을 해제했습니다. 공격력 -" << effect_ << endl;
	}
};
class TwoHandSword : public Item {
public:
	TwoHandSword() : Item("양손검", 500, false) { effect_ = 25; }

	void Use() override {
		cout << ">> [장착] " << name_ << "을 장착했습니다. 공격력 +" << effect_ << endl;
	}

	void Unequip() override {
		cout << ">> [해제] " << name_ << "을 해제했습니다. 공격력 -" << effect_ << endl;
	}
};

class Cheongapot : public Item {
public:
	Cheongapot() : Item("천 갑옷", 300, false) { effect_ = 10; }

	void Use() override {
		cout << ">> [장착] " << name_ << "를 장착했습니다. 방어력 +" << effect_ << endl;
	}

	void Unequip() override {
		cout << ">> [해제] " << name_ << "를 해제했습니다. 방어력 -" << effect_ << endl;
	}
};