#pragma once
#include <string>

class Title {
public:
    Title();
    ~Title();

    // 타이틀 화면을 그리는 메인 함수
    void DrawTitle();

private:
    std::string gameTitle;

    // 콘솔 제어를 위한 내부 유틸리티 함수
    void gotoxy(int x, int y);
    void setColor(int color);
};
