#include <SFML/Graphics.hpp>
#include <string>
#ifndef Aplikacja_hpp
#define Aplikacja_hpp

class Aplikacja
{
public:
//okno Aplikacji
    sf::RenderWindow okno;
    int wysokosc;
    int szerokosc;
    std::string nazwa;
    int mysz_X;
    int mysz_Y;

//uruchomienie Aplikacji
    void run(Aplikacja& App);

    Aplikacja();
    ~Aplikacja();

};

#endif
