#include "SFML/Graphics.hpp"
#ifndef Tablice_hpp
#define Tablice_hpp

class Tablice
{
public:
    int X;
    int Y;
    int ** tab;
    int wielkosc_grafik;
    sf::Texture Texture;
    sf::Sprite Sprite;
    void create(int x, int y);
    void show();
    void zeruj();
    Tablice(int x,int y,int wielkosc);
    Tablice(int x,int y,int wielkosc,std::string adres);
    ~Tablice();
};

#endif
