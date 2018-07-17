#include <SFML/Graphics.hpp>
#include "Tablice.hpp"
#include "Snake.hpp"
#ifndef Laser_hpp
#define Laser_hpp

class Laser
{
public:
    int X;
    int Y;
    int ID;
    bool kierunek;
    int do_7;

    bool pion;

    sf::Texture Texture;
    sf::Sprite Sprite;

    bool kolizja(Snake& waz);
    void ruch(Tablice& mapa);
    bool koniec(Tablice& mapa);
    void losuj(Tablice& mapa);
    void ustaw_ID(Tablice& mapa);
    Laser(Tablice& mapa);
    ~Laser();
};

#endif
