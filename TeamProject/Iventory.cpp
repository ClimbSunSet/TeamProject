#include "Inventory.h"
#include "Player.h"
#include <iostream>

using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {
	for (Item* item : items) delete item;
	items.clear();
}

void Inventory::addItem(Item* newItem) {
	for (Item* item : items) {
		if (item->getName() == newItem->getName()) {
			item->addCount(newItem->getCount());
			delete newItem;
			return;
		}
	}
	items.push_back(newItem);
}

void Inventory::RemoveItem(const string& itemName, Player* player) {
	bool isFound = false;
	for (auto it = items.begin(); it != items.end(); ++it) {
		if ((*it)->getName() == itemName) {
			isFound = true;
			(*it)->Use(player);
			(*it)->subCount(1);
			if ((*it)->getCount() <= 0) {
				delete* it;
				items.erase(it);
			}
			return;
		}
	}

	if (!isFound) {
		cout << "[가방 안내] '" << itemName << "'은(는) 가방에 없습니다." << endl;
	}
}


void Inventory::MonsterOnly() const { for (Item* i : items) if (i->getType() == "2") i->ShowInfo(); }
void Inventory::PotionsOnly() const { for (Item* i : items) if (i->getType() == "1") i->ShowInfo(); }
void Inventory::AllItems()    const { for (Item* i : items) i->ShowInfo(); }

