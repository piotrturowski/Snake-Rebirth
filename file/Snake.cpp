#include "Snake.hpp"
#include <iostream>

using namespace std;

class Tablice;

Snake::Snake(int x,int y,Tablice& mapa)
{
    this->ID = 1;
    this->ogon_ID = 2;
    this->X = x;
    this->Y = y;
    this->dlugosc_ogonu = 2;
    this->pkt = 0;
    this->blad_ruchu_X = 0;
    this->blad_ruchu_Y = 0;
    this->znak = 0;
    if(!this->font.loadFromFile("file/Base/Times.ttf"))
    {
        cout << "error" << endl << endl;
    }
    this->wynik.setFont(font);
    this->Text_WorL.setFont(font);
    this->liczba_wyniku = "0";
    this->wynik.setString(this->liczba_wyniku);
    this->wynik.setCharacterSize(90);
    this->Text_WorL.setCharacterSize(35);
    this->wynik.setColor(sf::Color::White);
    this->Text_WorL.setColor(sf::Color::White);


    this->znak_do_bledu_podwojnego_klawisza = 100;
    this->X_ogonu = new int [this->pkt+2];
    this->Y_ogonu = new int [this->pkt+2];
    for(int i=0;i<=pkt+1;i++)
    {
        this->X_ogonu[i] = this->X+i+1;
        this->Y_ogonu[i] = this->Y;
        mapa.tab[this->X][this->Y] = 2;
    }
    if(!this->Texture_glowa.loadFromFile("file/art/glowa.png"))
    {
        std::cout << "brak obrazek " << "file/art/glowa.png" << std::endl;
    }
    this->Sprite_glowa.setTexture(this->Texture_glowa);
    this->Sprite_glowa.scale(0.5,0.5);
    if(!this->Texture_cialo.loadFromFile("file/art/cialo.png"))
    {
        std::cout << "brak obrazek " << "file/art/cialo.png" << std::endl;
    }
    this->Sprite_cialo.setTexture(this->Texture_cialo);
    this->Sprite_cialo.scale(0.5,0.5);
}

Snake::~Snake()
{
    //moze jakas animacje umierania

}
void Snake::aktualizuj_wynik()
{
    this->zmiana_int_na_string();
    this->wynik.setString(this->liczba_wyniku);
}

void Snake::Sterowanie(Tablice& mapa)
{
    switch(this->znak)
    {
    case 119:
        {
            this->ruch_ogona(0);
            this->Y = this->Y-1;
//przesuwanie grafiki o blad w wyniku obrotu
            this->blad_ruchu_X = mapa.wielkosc_grafik;
            this->blad_ruchu_Y = 0;
//obrot grafiki
            this->Sprite_glowa.setRotation(90);
            this->znak_do_bledu_podwojnego_klawisza = 115;
            break;
        }
    case 115:
        {
            this->ruch_ogona(0);
            this->Y ++;
//przesuwanie grafiki o blad w wyniku obrotu
            this->blad_ruchu_X = 0;
            this->blad_ruchu_Y = mapa.wielkosc_grafik;
//obrot grafiki
            this->Sprite_glowa.setRotation(270);
            this->znak_do_bledu_podwojnego_klawisza = 119;
            break;
        }
    case 97:
        {
            this->ruch_ogona(0);
            this->X --;
//przesuwanie grafiki o blad w wyniku obrotu
            this->blad_ruchu_X = 0;
            this->blad_ruchu_Y = 0;
//obrot grafiki
            this->Sprite_glowa.setRotation(0);
            this->znak_do_bledu_podwojnego_klawisza = 100;
            break;
        }
    case 100:
        {
            this->ruch_ogona(0);
            this->X ++;
//przesuwanie grafiki o blad w wyniku obrotu
            this->blad_ruchu_Y = mapa.wielkosc_grafik;
            this->blad_ruchu_X = mapa.wielkosc_grafik;
//obrot grafiki
            this->Sprite_glowa.setRotation(180);
            this->znak_do_bledu_podwojnego_klawisza = 97;
            break;
        }
    }

}
void Snake::ruch_ogona(int licznik)
{
    if(this->pkt+1 >= licznik)
    {
        this->ruch_ogona(licznik+1);
        //ruch ogona
        if(licznik != 0)
        {
            this->X_ogonu[licznik] = this->X_ogonu[licznik-1];
            this->Y_ogonu[licznik] = this->Y_ogonu[licznik-1];
        }
        else
        {
            this->X_ogonu[0] = this->X;
            this->Y_ogonu[0] = this->Y;
        }
    }
}

bool Snake::kolizja_z_ogonem(int x,int y)
{
    for(int i = 0 ; i <= this->pkt+1 ; i++)
    {
//kolizja glowy z ogonem
        if(x == this->X_ogonu[i]&& y == Y_ogonu[i])
        {
            return true;
        }
    }

    return false;
}

void Snake::dodaj_punkt(Punkty& pkt,Tablice& mapa)
{
    if(this->X == pkt.X && this->Y == pkt.Y)
    {
        this->pkt++;
        this->dodaj_wzrost_weza();
        pkt.losuj(mapa.X,mapa.Y);

    }
    this->aktualizuj_wynik();
}

void Snake::dodaj_wzrost_weza()//-1
{

//tworzy do skopiowania tablice
        std::cout << "tworze tablice" << endl << pkt << endl;
        int X_ogonu2[this->pkt+1];//0
        int Y_ogonu2[this->pkt+1];
//petla kopiujaca +1 wzrost
        for(int i = 0; i <= this->pkt+1 ; i++)//2
        {
//kopiuje ostatni element
            if(this->pkt <= i)//1<=i
            {
                std::cout << "kopiuje 1" << endl << pkt << endl;
                X_ogonu2[i] = this->X_ogonu[i-1];
                Y_ogonu2[i] = this->Y_ogonu[i-1];
            }
//kopiuje elementy drugiej tablicy
            else//1>=i
            {
                std::cout << "kopiuje 2" << endl << pkt << endl;
                X_ogonu2[i] = this->X_ogonu[i];
                Y_ogonu2[i] = this->Y_ogonu[i];

            }
        }
        std::cout << "kasuje" << endl << pkt << endl;
        delete[] this->X_ogonu;
        delete[] this->Y_ogonu;

        std::cout << "tworze tablice" << endl << pkt << endl;
        this->X_ogonu = new int [this->pkt+2];//3
        this->Y_ogonu = new int [this->pkt+2];//3


        for(int i = 0; i <= this->pkt+1 ; i++)//2
        {
            std::cout << "przypisuje" << endl << pkt << endl;
            this->X_ogonu[i] = X_ogonu2[i];
            this->Y_ogonu[i] = Y_ogonu2[i];
        }
}



bool Snake::kolizja_ogony_z_ruchoma_siana(Sciana& Ruchoma)
{

    for(int i = 0; i<=this->pkt+1; i++)
    {
        if(this->X_ogonu[i] == Ruchoma.X && this->Y_ogonu[i] == Ruchoma.Y)
        {
            if(pkt == 0)
            {
                return true;
            }
            this->odejmij_punkt();
        }
    }
    if(this->X == Ruchoma.X && this->Y == Ruchoma.Y)
    {
        return true;
    }
    return false;
}

void Snake::zmiana_int_na_string()
{
        stringstream sso;
        sso << this->pkt;
        sso >> this->liczba_wyniku;
}

void Snake::odejmij_punkt()
{
    if(this->pkt > 0)
    {
        pkt--;
    }
}

void Snake::Wygrana()
{
    this->WorL = "Wygrana";
    this->Text_WorL.setString(this->WorL);
}
void Snake::Przegrana()
{
    this->WorL = "Przegrana";
    this->Text_WorL.setString(this->WorL);
}
void Snake::Remis()
{
    this->WorL = "Remis";
    this->Text_WorL.setString(this->WorL);
}
