#include "Ruchoma.hpp"
#include <iostream>

using namespace std;



void Sciana::ruch_sciany()
{
    if(this->kierunek == "up")
    {
        this->Y = this->Y - 1;

    }
    if(this->kierunek == "down")
    {
        this->Y = this->Y + 1;
    }
    if(this->kierunek == "left")
    {
        this->X = this->X - 1;
    }
    if(this->kierunek == "right")
    {
        this->X = this->X + 1;
    }
    //cout << this->X << endl << this->Y << endl << endl;
}

bool Sciana::kasuj_sciane(Tablice& mapa)
{
    if(this->kierunek == "up" && this->Y == 0)
    {
        return true;
    }
    if(this->kierunek == "down" && this->Y == mapa.Y)
    {
        return true;
    }
    if(this->kierunek == "left" && this->X == 0)
    {
        return true;
    }
    if(this->kierunek == "right" && this->X == mapa.X)
    {
        return true;
    }
    return false;
}

Sciana::Sciana(Tablice& mapa)
{
    if(!this->Texture.loadFromFile("file/art/Ruchoma.png"))
    {
        cout << "textura Ruchoma.png nie zostala zaladowana" << endl << endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->Sprite.setScale(0.5,0.5);
    this->ID = 5;
    this->losuj(mapa);

}



Sciana::~Sciana()
{

}

void Sciana::losuj(Tablice& mapa)
{
    switch(rand() % 4+0)
    {
//przeszkoda porusza sie w gore
    case 0:
        {
            this->X = rand () % (mapa.X-2) + 1;
            this->Y = mapa.Y;
            kierunek = "up";
            this->blad_ruchu_X = 0;
            this->blad_ruchu_y = mapa.wielkosc_grafik;
            this->Sprite.setRotation(270);
            break;
        }
//przeszkoda porusza sie w dol
    case 1:
        {
            this->X = rand () % (mapa.X-2) + 1;
            this->Y = 0;
            if(this->Y == 0)
            {
                kierunek = "down";
                this->blad_ruchu_X = mapa.wielkosc_grafik;
                this->blad_ruchu_y = 0;
                this->Sprite.setRotation(90);
            }
            break;
        }
//przeszkoda porusza sie w lewo
    case 2:
        {
            this->Y = rand () % (mapa.Y-2) + 1;
            this->X = mapa.X;
            if(this->X == mapa.X)
            {
                kierunek = "left";
                this->blad_ruchu_X = mapa.wielkosc_grafik;
                this->blad_ruchu_y = mapa.wielkosc_grafik;
                this->Sprite.setRotation(180);
            }

            break;
        }
//przeszkoda porusza sie w
    case 3:
        {
            this->Y = rand () % (mapa.Y-2) + 1;
            this->X = 0;
            if(this->X == 0)
            {
                kierunek = "right";
                this->blad_ruchu_X = 0;
                this->blad_ruchu_y = 0;
                this->Sprite.setRotation(0);
            }
            break;
        }
    }
}
