#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include <string>
#include <iomanip>
#include "zombie.h"

class Combat : public Zombie
{
    public:
        Combat();
        void PlayerTurn(Zombie[], int&, int&, string&, char);
        void UserMove(Zombie[], int&, string&, char, int&, int&);
        void CPUMove(Zombie[], int&, int&, string&, char, int&);
    protected:
    private:
};

#endif // COMBAT_H

