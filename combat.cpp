#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include <iomanip>
#include <fstream>
Combat::Combat()
{

}

void Combat::PlayerTurn(Zombie z[], int& i, int& death, string& name, char answer)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    system("CLS");
    if(answer=='b')
    {
        for(int j=1; j<=5; j++)
        {
            z[j].health=100;
            z[j].dead=false;
        }
    }

    for(i=1; i<=5; i++)
    {
        if(i==1 && z[i].dead==false)
        {
            DisplayHealth(z, name);
            cout<<name<<" it's your turn!"<<endl;
            myfile<<name<<" it's your turn!"<<endl;
            UserMove(z, n, name, answer, death, i);
        }
        else if((i==2 && z[i].dead==false) || (i==3 && z[i].dead==false) || (i==4 && z[i].dead==false) || (i==5 && z[i].dead==false))
        {
            if(z[1].dead==true)
            {
                system("CLS");
                DisplayHealth(z, name);
                CPUMove(z, n, i, name, answer, death);
            }
            else
            {
                cout<<endl<<"It's Player "<<i<<"'s turn!"<<endl;
                myfile<<endl<<"It's Player "<<i<<"'s turn!"<<endl;
                CPUMove(z, n, i, name, answer, death);
            }
        }
    }
    system("Pause");
    system("CLS");
    if(death<=5)
    {
        if(death==4)
            Winner(z, death, name);
        PlayerTurn(z, i, death, name, answer);
    }
    answer='c';
    myfile.close();
}

void Combat::UserMove(Zombie z[], int& n, string& name, char answer, int& death, int& i)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    myfile<<name<<", which zombie do you want to attack?"<<endl;
    myfile<<"Please choose zombie 2, 3, 4 or 5 & a zombie which is not dead"<<endl;
    cout<<name<<", which zombie do you want to attack?"<<endl;
    cout<<"Please choose zombie 2, 3, 4 or 5 & a zombie which is not dead"<<endl;
    cin>>n;
    while((n<2 || z[n].dead==true) || (n>5 || z[n].dead==true))
    {
        myfile<<"Please enter a value between 2 and 5 & a zombie which is not dead"<<endl;
        cout<<"Please enter a value between 2 and 5 & a zombie which is not dead"<<endl;
        cin>>n;
    }
    z[n].attack=25+(rand()%25);
    cout<<endl<<name<<" decides to Attack Player "<<n<<"!"<<endl;
    myfile<<endl<<name<<" decides to Attack Player "<<n<<"!"<<endl;

    cout<<name;
    myfile<<name;
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<" Attacks ";
    myfile<<" Attacks ";
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
    cout<<"with "<<z[n].attack<<" damage!"<<endl;
    myfile<<"with "<<z[n].attack<<" damage!"<<endl;

    cout<<"Player "<<n;
    myfile<<"Player "<<n;
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<" Health ";
    myfile<<" Health ";
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
    cout<<"is reduced from "<<z[n].health;
    myfile<<"is reduced from "<<z[n].health;
    z[n].health=z[n].health-z[n].attack;
    if(z[n].health<0)
        z[n].health=0;
    cout<<" to "<<z[n].health<<"!"<<endl<<endl;
    myfile<<" to "<<z[n].health<<"!"<<endl<<endl;

    IsDead(z, n, death, name, answer, i);
    myfile.close();
}

void Combat::CPUMove(Zombie z[], int& n, int& i, string& name, char answer, int& death)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    n=1+(rand()%5); //Randomly decides which opponent to attack
    while(i==n || z[n].dead==true) //It cant attack itself //It cant attack a dead enemy
        n=1+(rand()%5);
    z[i].attack=25+(rand()%25);
    if(n==1)
        {cout<<"Player "<<i<<" decides to Attack "<<name<<"!"<<endl;
        myfile<<"Player "<<i<<" decides to Attack "<<name<<"!"<<endl;}
    else
        {cout<<"Player "<<i<<" decides to Attack Player "<<n<<"!"<<endl;
        myfile<<"Player "<<i<<" decides to Attack Player "<<n<<"!"<<endl;}

    cout<<"Player "<<i;
    myfile<<"Player "<<i;
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<" Attacks ";
    myfile<<" Attacks ";  //Attack color is Blue
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
    cout<<"with "<<z[i].attack<<" damage!"<<endl; //Player's Attack
    myfile<<"with "<<z[i].attack<<" damage!"<<endl;

    if(n==1)
        {cout<<name;
        myfile<<name;}
    else
        {cout<<"Player "<<n;
        myfile<<"Player "<<n;}
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<" Health ";
    myfile<<" Health ";    // Health Color is Green
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
    cout<<"is reduced from "<<z[n].health;
    myfile<<"is reduced from "<<z[n].health; //Opponent's Health
    z[n].health=z[n].health-z[i].attack;
    if(z[n].health<0)
        z[n].health=0;
    cout<<" to "<<z[n].health<<"!"<<endl<<endl;
    myfile<<" to "<<z[n].health<<"!"<<endl<<endl;

    IsDead(z, n, death, name, answer, i);
    myfile.close();
}

