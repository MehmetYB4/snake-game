#include <iostream>
#include <windows.h>
using namespace std;
const int yukseklik=15;
const int genislik=60;
const int gecikme=40;

void gotoXY(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int main(void)
{
    for(int i=0;i<genislik;i++)
    {
        cout<<"x";
        Sleep(gecikme);
    }
    for(int i=0;i<yukseklik;i++)
    {
        gotoXY(genislik-1,i);
        cout<<"x";
        Sleep(gecikme);
    }
    for(int i=0;i<genislik;i++)
    {
        gotoXY(genislik-i-1,yukseklik-1);
        cout<<"x";
        Sleep(gecikme);
    }
    for(int i=0;i<yukseklik;i++)
    {
        gotoXY(0,yukseklik-i-1);
        cout<<"x";
        Sleep(gecikme);
    }
    cout<<"\n\n\n\n\n\n\n\t\t\tMEHMET YUSUF BIRCAN";
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    return 0;
}
