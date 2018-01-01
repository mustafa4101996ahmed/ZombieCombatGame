#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "Zombie.h"
#include "Combat.h"
using namespace std;

Zombie::Zombie()
{

}

void Zombie::IsDead(Zombie z[], int& n, int& death, string& name, char answer, int& i)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    if(z[n].health<=0)
        {
            z[n].dead=true;
            if(n==1)
                {cout<<name<<" is now";
                myfile<<name<<" is now";}
            else
                {cout<<"Player "<<n<<" is now";
                myfile<<"Player "<<n<<" is now";}

            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<<" DEAD";
            myfile<<" DEAD";
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
            cout<<"!"<<endl;
            myfile<<"!"<<endl;
            death++;
        }
    if(z[1].dead==true && death==4)
        {
            system("CLS");
            myfile<<"GAME OVER"<<endl;
            myfile<<name<<" is ";
            cout<<"GAME OVER"<<endl;
            cout<<name<<" is ";
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout<<"DEAD";
                myfile<<"DEAD";
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
                cout<<"!"<<endl;
                myfile<<"!"<<endl;

            myfile<<"Would You Like To Play Again, "<<name<<"?"<<endl;
            myfile<<"(Y / N)"<<endl;
            cout<<"Would You Like To Play Again, "<<name<<"?"<<endl;
            cout<<"(Y / N)"<<endl;
            cin>>answer;
            if(answer=='Y' || answer=='y')
            {
                system("CLS");
                death=0;
                answer='b';
                for(int j=1; j<=5; j++)
                {
                    z[j].health=100;
                    z[j].dead=false;
                }
                i=0;
                return;
            }
            else
                return;
        }
    myfile.close();
}
void Zombie::Winner(Zombie z[], int& death, string& name)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int n=1; n<=5; n++)
    {
        if(z[n].dead==false)
            {
                for(int c=0; c<10; c++)
                {
                    for(int k=10; k<16; k++)
                    {
                        DisplayHealth(z, name);
                        SetConsoleTextAttribute(h, k);
                        if(n==1)
                            {cout<<name<<" is the Winner!!!"<<endl;
                            myfile<<name<<" is the Winner!!!"<<endl;}
                        else
                            {cout<<"Player "<<n<<" is the Winner!!!"<<endl;
                            myfile<<"Player "<<n<<" is the Winner!!!"<<endl;}
                        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
                        cout<<endl<<"Thank you for Playing, this Program will now Terminate"<<endl;
                        myfile<<endl<<"Thank you for Playing, this Program will now Terminate"<<endl;
                        system("CLS");
                    }
                }
                myfile.close();
                exit(1);
            }
    }
}
void Zombie::DisplayHealth(Zombie z[], string& name)
{
    ofstream myfile;
    myfile.open ("assignment3data.txt", ostream::app);
    double life;
    for(int i=1; i<=5; i++)
    {
        life=ceil(z[i].health/10);
        if(i==1)
        {
            cout<<name<<"'s Health: ";
            myfile<<name<<"'s Health: ";
            if((name.length())<9)
            {
                int l=9-(name.length());
                cout<<setw(l);
                myfile<<setw(l);
            }
        }
        else
            {cout<<"Player "<<i<<"'s Health: ";
            myfile<<"Player "<<i<<"'s Health: ";}
        if(life==0)
        {
            HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<<"DEAD"<<endl;
            myfile<<"DEAD"<<endl;
            SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN );
        }
        else
        {
            for(int n=0; n<life; n++)
            {
                cout<<"*";
                myfile<<"*";
            }
            cout<<endl;
            myfile<<endl;
        }
    }
    cout<<endl;
    myfile<<endl;
    myfile.close();
}

