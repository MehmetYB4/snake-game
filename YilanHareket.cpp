#include <iostream>
#include <windows.h>
using namespace std;
enum YON
{
    YON_SAGA=1,
    YON_SOLA=2,
    YON_YUKARI=3,
    YON_ASAGI=4
};
struct YilanHucre
{
    int x;
    int y;
    YON yon;
    char karakter;
};
const int yukseklik=15;
const int genislik=60;
const int gecikme=35;
const char yilanKarakteri=219;
const int maxYilanUzunlugu = 100;
int kuyrukUzunulugu=0;
char sahne[genislik][yukseklik];
char tuslar[256];

enum RENK{
    RENK_SIYAH      = 0,
    RENK_KOYUMAVI   = 1,
    RENK_KOYUYESIL  = 2,
    RENK_AQUA       = 3,
    RENK_KAHVERENGI = 4,
    RENK_KOYUMOR    = 5,
    RENK_ACIKKAHVE  = 6,
    RENK_GRI        = 7,
    RENK_KOYUGRI    = 8,
    RENK_MAVI       = 9,
    RENK_YESIL      = 10,
    RENK_ACIKMAVI   = 11,
    RENK_KIRMIZI    = 12,
    RENK_MOR        = 13,
    RENK_SARI       = 14,
    RENK_BEYAZ      = 15,
};

void renkAta(RENK arkaplan, RENK yazirengi){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arkaplan * 16 + yazirengi);
}
YilanHucre yilanKuyrugu[maxYilanUzunlugu];
void yilanKuyrugunaEkle()
{
    if(maxYilanUzunlugu==kuyrukUzunulugu)
        return;
    int x=yilanKuyrugu[kuyrukUzunulugu-1].x;
    int y=yilanKuyrugu[kuyrukUzunulugu-1].y;
    YON yon=yilanKuyrugu[kuyrukUzunulugu-1].yon;
    char kr=yilanKuyrugu[kuyrukUzunulugu-1].karakter;

    switch(yilanKuyrugu[kuyrukUzunulugu-1].yon)
    {
    case YON_SAGA:
        x--;
        break;
    case YON_SOLA:
        x++;
        break;
    case YON_YUKARI:
        y--;
        break;
    case YON_ASAGI:
        y++;
        break;
    }

    yilanKuyrugu[kuyrukUzunulugu].x=x;
    yilanKuyrugu[kuyrukUzunulugu].y=y;
    yilanKuyrugu[kuyrukUzunulugu].yon=yon;
    yilanKuyrugu[kuyrukUzunulugu].karakter=kr;

    kuyrukUzunulugu++;
}
void yilanOlustur()
{
    kuyrukUzunulugu=1;
    yilanKuyrugu[0].x=12;
    yilanKuyrugu[0].y=4;
    yilanKuyrugu[0].yon=YON_SAGA;
    yilanKuyrugu[0].karakter=yilanKarakteri;
}

void yilaniSahneyeYerlestir()
{
    for(int i=0;i<kuyrukUzunulugu;i++)
    {
        int x= yilanKuyrugu[i].x;
        int y= yilanKuyrugu[i].y;
        sahne[x][y]=yilanKuyrugu[i].karakter;
    }
}
void yilaniHareketEttir()
{
    for(int i=0;i<kuyrukUzunulugu;i++)
    {
        switch(yilanKuyrugu[i].yon)
        {
        case YON_SAGA:
            yilanKuyrugu[i].x++;
            break;
        case YON_SOLA:
            yilanKuyrugu[i].x--;
            break;
        case YON_ASAGI:
            yilanKuyrugu[i].y++;
            break;
        case YON_YUKARI:
            yilanKuyrugu[i].y--;
            break;
        }
    }
    for(int i=kuyrukUzunulugu-1;i>0;i--)
    {
        yilanKuyrugu[i].yon=yilanKuyrugu[i-1].yon;
    }
}

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
void klavyeOku(char tuslar[])
{
    for (int x=0; x < 256; x++)
    {
        tuslar[x] = (char)(GetAsyncKeyState(x)>>8);
    }
}
void klavyeKontrol()
{
    klavyeOku(tuslar);
    if(tuslar['A']!=0)
    {
        yilanKuyrugu[0].yon= YON_SOLA;

    }
    if(tuslar['W']!=0)
    {
        yilanKuyrugu[0].yon= YON_YUKARI;

    }
    if(tuslar['S']!=0)
    {
        yilanKuyrugu[0].yon= YON_ASAGI;

    }
    if(tuslar['D']!=0)
    {
        yilanKuyrugu[0].yon= YON_SAGA;
    }
    if(tuslar['Y']!=0)
    {
        yilanKuyrugunaEkle();
    }
}

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
    yilanOlustur();

    int i=0;
    while(true)
    {
        renkAta(RENK_MAVI,RENK_KAHVERENGI);
        sahneyiTemizle();
        sinirlariOlustur();
        klavyeKontrol();
        yilaniHareketEttir();
        yilaniSahneyeYerlestir();

        gotoXY(0,0);
        sahneyiCiz();
        Sleep(gecikme);
        i++;
    }

    cin.get();
    return 0;
}

