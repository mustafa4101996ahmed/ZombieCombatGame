#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Zombie
{
    private:
    protected:
    public:
        Zombie();
        double health;
        int attack;
        bool dead;
        int n;
        void IsDead(Zombie[], int&, int&, string&, char, int&);
        void Winner(Zombie[], int&, string&);
        void DisplayHealth(Zombie[], string&);
};
#endif // ZOMBIE_H

