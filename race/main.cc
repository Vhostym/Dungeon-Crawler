#include <vector>
#include <iostream>
#include <string>
#include "race.h"

using namespace std;

int main() {
    try {
        Shade s{};
        Drow d{};
        Vampire v{};
        Troll t{};
        Goblin g{};
        cout << "All player races spawned successfully" << endl;
    } catch (...) {
        cerr << "A player race failed to spawn" << endl;
    }
    
    try {
        Human eh{};
        Dwarf ed{};
        Elf elf{};
        Orc eo{};
        Dragon edragon{};
        Merchant em{};
        Halfling ha{};
        cout << "All enemy races spawned successfully" << endl;
    } catch (...) { cerr << "An enemy race failed to spawn" << endl; }
   
    try {
    Shade s{};
    Drow d{};
    Vampire v{};
    Troll t{};
    Goblin g{};
    Human h{};
    Dwarf dw{};
    Elf e{};
    Orc o{};
    Dragon dragon{};
    Merchant m{};
    Halfling ha{};
    if (s.getHP() != 125) cerr << "shade health = " << s.getHP() << endl;
    if (s.getAtk() != 25) cerr << "shade atk = " << s.getHP() << endl;
    if (s.getDef() != 25) cerr << "shade def = " << s.getHP() << endl;
    if (d.getHP() != 150) cerr << "drow health = " << d.getHP() << endl;
    if (d.getAtk() != 25) cerr << "drow atk = " << d.getHP() << endl;
    if (d.getDef() != 15) cerr << "drow def = " << d.getHP() << endl;
    if (v.getHP() != 50) cerr << "vampire health = " << v.getHP() << endl;
    if (v.getAtk() != 25) cerr << "vampire atk = " << v.getHP() << endl;
    if (v.getDef() != 25) cerr << "vampire def = " << v.getHP() << endl;
    if (t.getHP() != 120) cerr << "troll health = " << t.getHP() << endl;
    if (t.getAtk() != 25) cerr << "troll atk = " << t.getHP() << endl;
    if (t.getDef() != 15) cerr << "troll def = " << t.getHP() << endl;
    if (g.getHP() != 110) cerr << "goblin health = " << g.getHP() << endl;
    if (g.getAtk() != 15) cerr << "goblin atk = " << g.getHP() << endl;
    if (g.getDef() != 20) cerr << "goblin def = " << g.getHP() << endl;
    if (h.getHP() != 140) cerr << "human health = " << h.getHP() << endl;
    if (h.getAtk() != 20) cerr << "human atk = " << h.getHP() << endl;
    if (h.getDef() != 20) cerr << "human def = " << h.getHP() << endl;
    if (dw.getHP() != 100) cerr << "dwarf health = " << dw.getHP() << endl;
    if (dw.getAtk() != 20) cerr << "dwarf atk = " << dw.getHP() << endl;
    if (dw.getDef() != 30) cerr << "dwarf def = " << dw.getHP() << endl;
    if (e.getHP() != 140) cerr << "elf health = " << e.getHP() << endl;
    if (e.getAtk() != 30) cerr << "elf atk = " << e.getHP() << endl;
    if (e.getDef() != 10) cerr << "elf def = " << e.getHP() << endl;
    if (o.getHP() != 180) cerr << "orc health = " << o.getHP() << endl;
    if (o.getAtk() != 30) cerr << "orc atk = " << o.getHP() << endl;
    if (o.getDef() != 25) cerr << "orc def = " << o.getHP() << endl;
    if (dragon.getHP() != 150) cerr << "dragon health = " << dragon.getHP() << endl;
    if (dragon.getAtk() != 20) cerr << "dragon atk = " << dragon.getHP() << endl;
    if (dragon.getDef() != 20) cerr << "dragon def = " << dragon.getHP() << endl;
    if (m.getHP() != 30) cerr << "merchant health = " << m.getHP() << endl;
    if (m.getAtk() != 70) cerr << "merchant atk = " << m.getHP() << endl;
    if (m.getDef() != 5) cerr << "merchant def = " << m.getHP() << endl;
    if (ha.getHP() != 100) cerr << "halfling health = " << ha.getHP() << endl;
    if (ha.getAtk() != 15) cerr << "halfling atk = " << ha.getHP() << endl;
    if (ha.getDef() != 20) cerr << "halfling def = " << ha.getHP() << endl;
    } catch (...) { cerr << "exception thrown during race stat assessment" << endl;}

    vector<Race> players = {Shade{}, Drow{}, Troll{}, Goblin{}};
    Race enemies[7] = {Human{}, Dwarf{}, Elf{}, Orc{}, Dragon{}, Merchant{}, Halfling{}};
    int val = 0;
    for (auto player : players) {
        for (auto enemy : enemies) {
            val = player.attack(enemy);
            if (val != 0) cerr << player.getId() << " failed against " << enemy.getId() << endl;
        }
    }
    Vampire v{};
    for (auto enemy : enemies) {
        val = v.attack(enemy);
        if (val != 5 && enemy.getId() != "dwarf") cerr << "vampire failed against " << enemy.getId() << endl;
        if (val != -5 && enemy.getId() == "dwarf") cerr << "vampire failed against dwarf" << endl;
    }
    
    players.emplace_back(Vampire{});
    int val1, val2;
    for (auto player : players) {
        for (auto enemy : enemies) {
            do {
                val1 = player.getAttacked(enemy);
                val2 = enemy.getAttacked(player);
            } while (val1 == 0 || val2 == 0);
            cout << val1 << " is for " << enemy.getId() << " attacking " << player.getId() << endl;
            cout << val2 << " is for " << player.getId() << " attacking " << enemy.getId() << endl;
        }
    }
}
