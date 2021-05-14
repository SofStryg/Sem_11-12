#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;


class Hero {
public:
    string name;
    double max_health;
    double health;
    double strenght;
    void show_hp() {
        cout << name << " HP ";
        for (int i = 0; i < max_health; i += 5) {
            if (i <= health) {
                cout << "#";
            }
            else {
                cout << "_";
            }
        }
        cout << endl;
    }
    bool strike(Hero& enemy) {
        double damage = double((rand() % 30) + 1.0)/10 * strenght;
        enemy.health = enemy.health - damage;
        cout << name << " бьет " << enemy.name << " на " << damage << " урона" << endl << endl;

        if (enemy.health <= 0) {
            cout << enemy.name << " Умер" << endl << endl;
            return false;
        }
        return true;
    }
};

int main()
{   
    setlocale(0, "");
    srand(time(0));
    Hero one{ "Elf",100,100,12 };
    Hero two{ "Human",140 ,140,9 };
    cout << "Начинаем великую битву" << endl << endl;
    Sleep(2000);
    while (one.health > 0 && two.health > 0)
    {
        one.strike(two);
        cout << endl;
        one.show_hp();
        two.show_hp();
        Sleep(1000);
        system("cls");

        if (two.health > 0) {
            two.strike(one);
            cout << endl;
            one.show_hp();
            two.show_hp();
            Sleep(1000);
            system("cls");
        }
    }
}

