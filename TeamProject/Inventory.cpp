#include "Inventory.h"
#include "Player.h"
#include <iostream>

using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {
	for (Item* item : items) delete item;
	items.clear();
}
int Inventory::UsePotionAuto() {
	for (int i = 0; i < items.size(); ++i) {
		// 타입이 1 물약인 아이템을 찾음
		if (items[i] != nullptr && items[i]->getType() == "1") {
			int healValue = items[i]->getHP(); // 아이템의 회복량 가져오기
			string pName = items[i]->getName();
			RemoveItem(pName); // 아이템 사용 후 제거
			return healValue;
		}
	}
	return 0; // 물약이 없으면 0 반환
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
	for (auto it = items.begin(); it != items.end(); ++it) {
		if ((*it)->getName() == itemName) {

			if ((*it)->getCount() <= 0) {
				cout << "[가방 안내] '" << itemName << "'의 남은 개수가 없습니다!" << endl;
				return;
			}

			if ((*it)->getType() == "2") {
				if (rand() % 2 == 0) {

					(*it)->Use(player);
					cout << "아이템 흡수 성공!" << endl;
				}
				else {
					cout << "아이템 흡수에 실패했습니다." << endl;
				}


				(*it)->Use(player);
			}



			(*it)->subCount(1);
			if ((*it)->getCount() <= 0) {
				delete* it;
				items.erase(it);
			}
			return;
		}
	}
	cout << "[가방 안내] '" << itemName << "'은(는) 가방에 없습니다." << endl;
}



void Inventory::MonsterOnly() const { for (Item* i : items) if (i->getType() == "2") i->ShowInfo(); }
void Inventory::PotionsOnly() const { for (Item* i : items) if (i->getType() == "1") i->ShowInfo(); }
void Inventory::AllItems()    const { for (Item* i : items) i->ShowInfo(); }

