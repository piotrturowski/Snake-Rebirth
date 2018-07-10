#include "Punkty.hpp"
#include <iostream>


Punkty::Punkty(int x, int y)
{
     if(!this->Texture.loadFromFile("file/art/punkt.png"))
    {
        std::cout << "brak obrazek " << "file/art/punkt.png" << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->Sprite.setScale(0.5,0.5);
    this->losuj(x,y);
    this->ID = 3;
}

Punkty::~Punkty()
{

}

void Punkty::losuj(int x, int y)
{
    this->X = rand() % (x-1)+1;
    this->Y = rand() % (y-1)+1;
}
