#include <iostream>
#include <string>

using namespace std;

class Character {
private:
    const int Min_Level = 1;
    const int Max_Level = 10;

    std::string Name;
    int Level;
    int HP;
    int MaxHP;
    int ATK;
    int EXP;
    int MaxExp;
    int LUCK;

public:
    Character(string name)
        : Name(name), Level(1), MaxHP(200), HP(200), ATK(30), EXP(0), MaxExp(100), LUCK(2) {
    }

    void GetExp(int amount) {
        if (amount <= 0) return;

        if (Level < Min_Level) Level = Min_Level;
        if (Level >= Max_Level) return;

        EXP += amount;
        cout << Name << " Get " << amount << " EXP\n";

        while (EXP >= MaxExp && Level < Max_Level) {
            LevelUp();
        }
    }

private:
    void LevelUp() {
        EXP -= MaxExp;
        Level++;

        if (Level < Min_Level) Level = Min_Level;
        if (Level > Max_Level) Level = Max_Level;

        MaxHP += Level * 20;
        ATK += Level * 5;
        LUCK += 2;
        HP = MaxHP;
        MaxExp += 50;

        cout << "Level UP! -> Lv." << Level << endl;
        cout << "MaxHP : " << MaxHP << " / ATK : " << ATK << endl;

        if (Level >= Max_Level) {
            Level = Max_Level;
            EXP = 0;
            cout << "Max Level!" << endl;
        }
    }
};
