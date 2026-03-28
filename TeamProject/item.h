#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Monster.h"

using namespace std;

class Player;

class Item {
protected:
	string name;
	string type; // "1": 물약, "2": 전리품
	int HP, MaxHP, ATK, count;

public:
	// [20% 공식]
	Item(string name, string type, int HP, int MaxHP, int ATK, int count, Monster* monster = nullptr)
		: name(name), type(type), count(count)
	{
		if (type == "2" && monster != nullptr)
		{
			this->MaxHP = (int)(monster->GetMaxHP() * 0.2);
			this->ATK = (int)(monster->GetATK() * 0.2);
			this->HP = 0;
		}
		else
		{
			this->HP = HP;
			this->MaxHP = MaxHP;
			this->ATK = ATK;
		}
	}

	virtual ~Item() {}

	string getName() const { return name; }
	string getType() const { return type; }
	int getCount() const { return count; }
	void addCount(int n) { count += n; }
	void subCount(int n) { if (count >= n) count -= n; }

	void Use(Player* player);
	void ShowInfo() const { cout << name << "|" << count << "개" << endl; }
};

class ItemCreater {
public:

	static Item* CreateItem(string name, Monster* monster, int count = 0);
};