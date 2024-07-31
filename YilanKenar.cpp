#include <iostream>
#include <windows.h>
using namespace std;
const int yukseklik=15;
const int genislik=60;
const int gecikme=30;
void gotoXY(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void cursorGizle()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out,&cursorInfo);
    cursorInfo.bVisible=false;
    SetConsoleCursorInfo(out,&cursorInfo);
}
char sahne[genislik][yukseklik];
void sahneyiCiz()
{
    for(int y=0;y<yukseklik;y++)
    {
        for(int x=0;x<genislik;x++)
        {
            cout<<sahne[x][y];
        }
        cout<<endl;
    }
}
void sahneyiTemizle()
{
    for(int y=0;y<yukseklik;y++)
    {
        for(int x=0;x<genislik;x++)
        {
            sahne[x][y]=' ';
        }
        cout<<endl;
    }
}
void sinirlariOlustur()
{
    for(int x=0;x<genislik;x++)
    {
        sahne[x][0]=219;
        sahne[x][yukseklik-1]=219;
    }
    for(int y=0;y<yukseklik;y++)
    {
        sahne[0][y]=219;
        sahne[genislik-1][y]=219;
    }

}
int main(void)
{
    sinirlariOlustur();
    cursorGizle();

    int i=0;
    while(true)
    {
        sahneyiTemizle();
        sinirlariOlustur();
        sahne[i+10][7]='x';


        gotoXY(0,0);
        sahneyiCiz();
        Sleep(gecikme);
        i++;
    }

    cin.get();
    return 0;
}
