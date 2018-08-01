#include <SFML/Graphics.hpp>
#include "Aplikacja.hpp"
#include "Ready.hpp"
#ifndef Menu_hpp
#define Menu_hpp

class Menu
{
    sf::Event event;
public:
    Ready jeden_gracz;
    Ready dwoch_graczy;
    Ready wyjscie;
    Ready tlo;

    void run(Aplikacja& App, Menu& menu);
    void rysuj(Aplikacja& App);
    void sterowanie(Aplikacja& App);
    void run_gra(Aplikacja& App, bool tryb_multiplayer);
    Menu(Aplikacja& App);
    ~Menu();
};

#endif
