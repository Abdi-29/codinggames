#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define MONSTER 0
#define MYHERO 1
#define ENEMY 2

typedef enum data {
        ID,
        TYPE,
        X,
        Y,
        HEALTH,
        VX,
        VY,
        NEAR_BASE,
        THREAD_FOR
}   data;

class Input
{
public:
    int id; // Unique identifier
    int type; // 0=monster, 1=your hero, 2=opponent hero
    int x; // Position of this entity
    int y;
    int shield_life; // Ignore for this league; Count down until shield spell fades
    int is_controlled; // Ignore for this league; Equals 1 when this entity is under a control spell
    int health; // Remaining health of this monster
    int vx; // Trajectory of this monster
    int vy;
    int near_base; // 0=monster with no target yet, 1=monster targeting a base
    int threat_for; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither

    void    getInput()
    {
        cin >> id >> type >> x >> y >> shield_life >> is_controlled >> health >> vx >> vy >> near_base >> threat_for; cin.ignore();
    }
};

int getSize(std::vector<Input> target)
{
    int len = 0;
    for (std::vector<Input>::iterator it = target.begin(); it != target.end(); it++)
    {
        len++;
    }
    return len;
}

int main()
{
    Input input;
    int base_x; // The corner of the map representing your base
    int base_y;
    cin >> base_x >> base_y; cin.ignore();
    int heroes_per_player; // Always 3
    cin >> heroes_per_player; cin.ignore();
    int  enemy_base[2];
    if (!base_x)
    {
        enemy_base[0] = 17630;
        enemy_base[1] = 9000;
    }
    else
    {
        enemy_base[0] = 0;
        enemy_base[1] = 0;
    }

    // game loop
    while (1) {
        std::vector<Input> monsters;
        std::vector<Input> heroes;
        std::vector<Input> enemies;
        int monsterLen = 0;

        for (int i = 0; i < 2; i++) {
            int health; // Your base health
            int mana; // Ignore in the first league; Spend ten mana to cast a spell
            cin >> health >> mana; cin.ignore();
        }
        int entity_count; // Amount of heros and monsters you can see
        cin >> entity_count; cin.ignore();
        for (int i = 0; i < entity_count; i++) {
            input.getInput();
            if (input.type == MONSTER)
                monsters.push_back(input);
            else if (input.type == MYHERO)
                heroes.push_back(input);
            else if (input.type == ENEMY)
                enemies.push_back(input);
        }

        for (int i = 0; i < heroes_per_player; i++) {
    // cerr << "Im here" << endl;

            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;

            // In the first league: MOVE <x> <y> | WAIT; In later leagues: | SPELL <spellParams>;
        cerr << "im herejjfjjijieiirttit2222" << endl;
            std::vector<Input> target;

            int te = 0;
            if (getSize(monsters) > 0)
            {
                target.assign(monsters.begin(), monsters.end());
                int stop = (i % getSize(target));
                int start = 0;
                cerr << "id.................... = " << input.id << "    " << i << endl;
                for (std::vector<Input>::iterator it = target.begin(); it != target.end(); it++)
                {
                    if ((*it).health == 0)
                        break;
                    if (start  == stop)
                    {
                        if ((*it).near_base == 0 || (*it).threat_for != 1)
                        {
                            if ((*it).threat_for == 1 && (*it).health > 0)
                            {
                                te = 1;
                                cout << "SPELL WIND " << enemy_base[0] << " " << enemy_base[1] << endl;
                            }
                            break;
                        }
                        else if ((*it).near_base == 1 && (*it).threat_for == 1)
                            cout << "MOVE " << (*it).x << " " << (*it).y << " hello" << endl;
                        te = 1;
                        break;
                    }
                    start++;
                }
                // cout << (*monsters.begin()).x << " " << (*monsters.begin()).y << endl;
            }
            if(te == 0)
                cout << "WAIT" << endl;
        }
    }
}

