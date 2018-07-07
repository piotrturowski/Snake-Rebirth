#include "Aplikacja.hpp"
#include "Tablice.hpp"
#include "Snake.hpp"
#include "czas.hpp"
#include "funkcjeGry.hpp"
#include <SFML/Graphics.hpp>
#ifndef Gra_hpp
#define Gra_hpp

class Game
{
public:

    bool tryb_multi;
    Tablice mapa;
    Snake waz;
    czaS czas;
    funkcje Funkcje;

    void run(Aplikacja& App);

    Game(bool tryb_multiplayer);
    ~Game();

};

#endif
