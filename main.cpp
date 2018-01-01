#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>
#include "Zombie.h"
#include "Combat.h"
using namespace std;
int main()
{
    srand(time(0));
    string name;
    int j=1;
    int i;
    int death=0;
    char answer='a';
    ofstream myfile;
    myfile.open ("assignment3data.txt");
    cout<<endl<<"\t Welcome to Mustafa's Zombie Combat Game!"<<endl;
    cout<<"\t You are about to fight 4 other zombies"<<endl;
    cout<<"\t Until the last zombie is left standing"<<endl<<endl;
    myfile<<endl<<"\t Welcome to Mustafa's Zombie Combat Game!"<<endl;
    myfile<<"\t You are about to fight 4 other zombies"<<endl;
    myfile<<"\t Until the last zombie is left standing"<<endl<<endl;
    Zombie z[5];
    Combat game;
    myfile<<"What is your name?"<<endl;
    cout<<"What is your name?"<<endl;
    cin>>name;
    myfile.close();
    for(j=1; j<=5; j++)
        {
            z[j].health=100;
            z[j].dead=false;
        }
    do
        game.PlayerTurn(z, i, death, name, answer);
    while(answer=='b');
    return 0;
}

