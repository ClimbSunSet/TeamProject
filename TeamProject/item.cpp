#include "Item.h"
#include "Player.h"

using namespace std;

// [아이템 사전]
static map<string, pair<string, int>> ItemCreate = {
{"체력물약", {"1", 50}},
{"시궁창쥐", {"2", 0}},
{"미니피그", {"2", 0}}
};


Item* ItemCreater::CreateItem(string name, Monster* monster, int count) {
	auto it = ItemCreate.find(name);
	if (it == ItemCreate.end()) return nullptr;
	return new Item(name, it->second.first, it->second.second, 0, 0, count, monster);
}


void Item::Use(Player* player) {
	if (player == nullptr) return;

	if (type == "1") {
		cout << name << "을(를) 마셨습니다!" << endl;
		if (HP > 0) {
			player->SetHP(player->GetHP() + HP); // 스탯 전달 
			cout << " 체력이 " << HP << "만큼 회복되었습니다." << endl;
		}
	}
	else if (type == "2") {
		cout << "\n[능력 흡수] " << name << "의 능력를 흡수합니다!" << endl;
		if (MaxHP > 0) {
			player->SetMaxHp(player->GetMaxHp() + MaxHP); // 스탯 전달 
			cout << " >> 최대 체력이 " << MaxHP << " 증가했습니다." << endl;
		}
		if (ATK > 0) {
			player->SetAtk(player->GetAtk() + ATK); // 스탯 전달 
			cout << " >> 공격력이 " << ATK << " 증가했습니다." << endl;
		}
	}
}