#include "Aplikacja.hpp"
#include "Tablice.hpp"
#include "Snake.hpp"
#include "Punkty.hpp"
#include "Ruchoma.hpp"
#include "Laser.hpp"
#include <SFML/Graphics.hpp>

#ifndef funkcjeGry_HPP
#define funkcjeGry_HPP

class Game;

class funkcje
{
public:
    bool tryb_multi;
    sf::Event event;

    void sterowanie(Aplikacja& App,Snake& waz,Snake& waz2);
    void kolizje(Aplikacja& App, Snake& waz,Tablice& mapa,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2);
    bool kolizja(Snake& waz,Tablice& mapa);
    bool wygrana();
    bool wyjscie(Aplikacja& App);
    void draw(Aplikacja& App,Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2);
    void ustaw_ID_na_mapie(Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2);
    void ustawianie_weza(Tablice& mapa,Snake& waz);
};

#endif
