// Inventory.h
#pragma once
#include <iostream>
#include "Item.h"

template<typename T>
class Inventory {
public:
	// 기본용량
	Inventory(int capacity = 5) {
		capacity_ = (capacity <= 0) ? 1 : capacity;
		size_ = 0;
		pItems_ = new T[capacity_]; // T는 Item
		for (int i = 0; i < capacity_; ++i) {
			pItems_[i] = nullptr;
		}
	}
	//가방 기동식
	~Inventory() {
		if (pItems_ != nullptr) {

			delete[] pItems_;
			pItems_ = nullptr;
		}
	}

	bool AddItem(const T& item) {
		if (size_ < capacity_) {
			pItems_[size_] = item;
			size_++;
			return true;
		}
		cout << " *[경고] 인벤토리에 자리가 없습니다!* " << endl;
		return false;
	}


	void UseItem(int index) {
		if (index < 0 || index >= size_ || pItems_[index] == nullptr) {
			cout << " *[경고] 물건이 없습니다!* " << endl;
			return;
		}

		// 1. 아이템 효과 발동
		pItems_[index]->Use();

		// 2. 소모품 판단 및 삭제
		if (pItems_[index]->IsConsumable()) {
			cout << pItems_[index]->GetName() << " 사용 " << endl;

			delete pItems_[index];
			for (int i = index; i < size_ - 1; ++i) {
				pItems_[i] = pItems_[i + 1];
			}
			pItems_[size_ - 1] = nullptr;
			size_--;
		}
		else {
			cout << pItems_[index]->GetName() << " 장착 중 " << endl;
		}
	}

	void PrintAllItems() const {
		cout << " \n*소지품 목록* (" << size_ << "/" << capacity_ << ") " << endl;
		for (int i = 0; i < capacity_; ++i) {
			cout << "[" << i << "] ";
			if (pItems_[i]) pItems_[i]->PrintInfo();
			else cout << "(비어 있음)" << endl;
		}
	}
	//*재미나이가 만들어줬음*(기동은됩니다)void EquipItem(int index) {
	if (index < 0 || index >= size_ || pItems_[index] == nullptr) return;

	// 소모품은 장착 불가 체크
	if (pItems_[index]->IsConsumable()) {
		cout << " [오류] 소모품은 장착할 수 없습니다! " << endl;
		return;
	}

	// 1. 새로 장착할 무기를 변수에 담기
	T newWeapon = pItems_[index];

	// 2. 원래 끼고 있던 무기가 있다면? -> 다시 인벤토리에 넣기
	if (equippedWeapon_ != nullptr) {
		equippedWeapon_->Unequip();
		pItems_[index] = equippedWeapon_; // 빈자리에 기존 무기 반환
	}
	else {
		// 원래 낀 게 없었다면? -> 인벤토리 칸 한 칸 줄이기 (당기기)
		for (int i = index; i < size_ - 1; ++i) {
			pItems_[i] = pItems_[i + 1];
		}
		pItems_[size_ - 1] = nullptr;
		size_--;
	}

	// 3. 새 무기 장착 
	equippedWeapon_ = newWeapon;
	equippedWeapon_->Use(); // "장착했습니다" 메시지 출력
}


private:
	T* pItems_;
	T equippedWeapon_;
	int capacity_;
	int size_;
};