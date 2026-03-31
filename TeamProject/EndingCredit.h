#pragma once
#include <string>
#include <vector>

// 역할과 이름을 묶어주는 구조체
struct CreditItem
{
    std::string role;
    std::string name;
};

class EndingCredit
{
public:
    EndingCredit();
    // 상속을 고려하여 virtual 소멸자 권장 (기존 코드 유지)
    virtual ~EndingCredit();

    // 엔딩 크레딧을 화면에 출력하는 함수
    void ShowCredit();

private:
    // 팀원 정보를 담는 벡터
    std::vector<CreditItem> credits;

    // 콘솔 제어를 위한 내부 유틸리티 함수
    void gotoxy(int x, int y);
    void setColor(int color);
};
