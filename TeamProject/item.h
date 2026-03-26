// item.h  //나중에 effect_ 부분 수정해야됨 능력치로
#pragma once
#include <iostream> 
#include <string>

using namespace std;

// 기본

class Item {
public:
	Item(const string& name = "", int price = 0, bool consumable = true)
		: name_(name), price_(price), isConsumable_(consumable), effect_(0) {
	}

	virtual ~Item() {}

	const string& GetName() const { return name_; }
	int GetPrice() const { return price_; }
	bool IsConsumable() const { return isConsumable_; }

	void Clear() { name_ = ""; price_ = 0; isConsumable_ = true; }

	virtual void PrintInfo() const {
		if (name_ == "") cout << "[비어 있음]" << endl;
		else {
			string type = isConsumable_ ? "[소모품]" : "[장비]";
			cout << type << " " << name_ << " / 가격: " << price_ << " G" << endl;
		}
	}


	virtual void Use() = 0;
	virtual void Unequip() {}

protected:
	string name_;
	int price_;
	int effect_;
	bool isConsumable_;
};