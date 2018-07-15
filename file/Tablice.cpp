#include "Tablice.hpp"
#include <iostream>
#include <string>

Tablice::Tablice(int x,int y,int wielkosc)
{
    this->create(x,y);
    this->wielkosc_grafik = wielkosc;
    if(!this->Texture.loadFromFile("file/art/sciana.png"))
    {
        std::cout << "brak obrazka: file/art/sciana.png" << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->Sprite.scale(0.5,0.5);
}

Tablice::Tablice(int x,int y,int wielkosc,std::string adres)
{
    this->create(x,y);
    this->wielkosc_grafik = wielkosc;
    if(!this->Texture.loadFromFile(adres))
    {
        std::cout << "brak obrazka " << adres << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->Sprite.scale(0.5,0.5);
}

Tablice::~Tablice()
{

}


void Tablice::create(int x, int y)
{
    this->tab = new int * [x];
    x--;
    for(int i=0; i<=x; i++)
    {
        this->tab[i] = new int [y];
    }
    y--;
    this->Y = y;
    this->X = x;
    this->zeruj();
}

void Tablice::show()
{
    for(int i=0; i<=X;i++)
    {
        for(int j=0; j<=Y;j++)
        {
            std::cout << this->tab[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Tablice::zeruj()
{
    for(int i=0; i<=X;i++)
    {
        for(int j=0; j<=Y;j++)
        {
           this->tab[i][j] = 0;
        }
    }
}
