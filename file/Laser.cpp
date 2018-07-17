#include "Laser.hpp"
#include <iostream>


Laser::Laser(Tablice& mapa)
{
    if(!this->Texture.loadFromFile("file/art/Laser.png"))
    {
        std::cout << "brak obrazeka file/art/Laser.png" << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->Sprite.setScale(0.5,0.5);
    this->ID = 6;
    this->losuj(mapa);
}

Laser::~Laser()
{

}

void Laser::losuj(Tablice& mapa)
{
    this->do_7 = 0;
    switch(rand() % 2+0)
    {
    case 0:
        {
            this->X = rand () % (mapa.X-2) + 1;
            this->Y = mapa.Y;
            this->pion = rand () % 2;
            this->kierunek = 0;
            break;
        }
    case 1:
        {
            this->X = 0;
            this->Y = rand () % (mapa.X-2) + 1;
            this->pion = rand () % 2;
            this->kierunek = 1;
            break;
        }
    }

}

void Laser::ustaw_ID(Tablice& mapa)
{
    if(this->pion)
    {
        for(int i = 1; i<=(mapa.Y-1);i++)
        {
            mapa.tab[this->X][i] = this->ID;
        }
    }
    else
    {
        for(int i = 1; i<=(mapa.X-1);i++)
        {
            mapa.tab[i][this->Y] = this->ID;
        }
    }
}

bool Laser::koniec(Tablice& mapa)
{
    if(do_7 == 7)
    {
        this->losuj(mapa);
    }
}

void Laser::ruch(Tablice& mapa)
{
    if(do_7 == 2 || do_7 == 4 || do_7 == 6)
    {
        switch(this->kierunek)
        {
        case 0: // w gore ruch i lewo
            {
                if(pion == true)// lewo
                {
                    if(this->X != 1)
                    {
                       this->X--;
                    }
                }
                else // gora
                {
                    if(this->Y != 1)
                    {
                       this->Y--;
                    }

                }
                break;
            }
        case 1: // w dol ruch i prawo
            {
                if(pion == true) // prawo
                {
                    if(this->X != mapa.X-1)
                    {
                       this->X++;
                    }
                }
                else // dol
                {
                    if(this->Y != mapa.Y-1)
                    {
                       this->Y++;
                    }
                }
                break;
            }
        }
    }
    this->do_7++;
}

bool Laser::kolizja(Snake& waz)
{
    switch(this->pion)
        {
        case 0: // gora dol
            {
                if(this->Y == waz.Y)
                {
                    return true;
                }
                break;
            }
        case 1: // lewo prawo
            {
                if(this->X == waz.X)
                {
                    return true;
                }
                break;
            }
        }
        return false;
}
