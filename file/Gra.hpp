#include "Aplikacja.hpp"
#include "Tablice.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#ifndef Gra_hpp
#define Gra_hpp

class Game
{
public:
    void sterowanie(Aplikacja& App);
    sf::Event event;
    bool tryb_multi;
    Tablice mapa;
    Snake waz;
    void run(Aplikacja& App);
    bool wygrana();
    bool wyjscie(Aplikacja& App);
    void draw(Aplikacja& App);
    void ustaw_ID_na_mapie();
    Game(bool tryb_multiplayer);
    ~Game();

};

#endif
