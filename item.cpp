#include <Windows.h>
#include <iostream>
#include "Item.h"
#include "Consumables.h"
#include "Equipments.h"
#include "Inventory.h"

using namespace std;
// 테스트용 메인 함수
int main() {
	// 한글 깨짐 방지 설정
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "KOREAN");
	//테스트
	Inventory<Item*> myInven(10);


	myInven.AddItem(new HealthPotion());
	myInven.AddItem(new ManaPotion());
	myInven.AddItem(new OneHandSword());
	myInven.AddItem(new Cheongapot());
	myInven.AddItem(new TwoHandSword());

	int choice = 0;
	int index = -1;

	while (true) {
		system("cls"); // 화면 깔끔하게 지우기 (Windows 전용)이라하더라고요 자꾸한글이 깨져서ㅠ
		myInven.PrintAllItems();

		cout << "\n[1] 아이템 사용/장착  [2] 장비 해제  [0] 종료" << endl;
		cout << "메뉴 선택: ";
		cin >> choice;

		if (choice == 0) break;

		cout << "아이템 번호 입력 (0~9): ";
		cin >> index;

		switch (choice) {
		case 1:

			if (index >= 0 && index < 10) {

				//myInven.EquipItem(index);
			}
			break;

		case 2:

			cout << "\n--- 장비 해제 시도 ---" << endl;

			break;

		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}

		cout << "\n(계속하려면 아무 키나 누르세요...)" << endl;
		system("pause");
	}

	return 0;
}