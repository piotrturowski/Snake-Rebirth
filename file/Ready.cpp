#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Ready.hpp"

Ready::Ready()
{

}

Ready::~Ready()
{

}

bool Ready::jestAktywny()
{

}

void Ready::nadaj_teksture(std::string n,float x,float y)
{
    this->X = x;
    this->Y = y;
    this->nazwa = n;
    if(!this->Texture.loadFromFile(this->nazwa))
    {
        std::cout << "brak obrazek " << this->nazwa << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
    this->ustaw_pozycje();
}

void Ready::ustaw_pozycje()
{
    this->Sprite.setPosition(this->X,this->Y);
}


