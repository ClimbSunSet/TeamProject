#pragma once
#include <vector>
#include <string>
#include "Item.h"    

using namespace std;

class Inventory {
private:

	vector<Item*> items;

public:
	Inventory();
	~Inventory();

	// 아이템 추가
	void addItem(Item* newItem);

	// 2. 아이템 사용
	void RemoveItem(const string& itemName, Player* player = nullptr);

	// 전리품만 출력
	void MonsterOnly() const;

	// 4. 포션만 출력 
	void PotionsOnly() const;

	// 5.전체 아이템 출력
	void AllItems() const;
};
