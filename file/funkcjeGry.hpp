#include "Aplikacja.hpp"
#include "Tablice.hpp"
#include <SFML/Graphics.hpp>
#ifndef funkcjeGry_HPP
#define funkcjeGry_HPP

class Game;

class funkcje
{
public:
    sf::Event event;

    void sterowanie(Aplikacja& App,Game& Gra);
    void kolizje(Aplikacja& App, Game& Gra);
    bool kolizja(Game& Gra);
    bool wygrana();
    bool wyjscie(Aplikacja& App);
    void draw(Aplikacja& App,Game& Gra);
    void ustaw_ID_na_mapie(Game& Gra);

};

#endif
