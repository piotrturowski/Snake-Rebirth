#include <SFML/Graphics.hpp>
#ifndef czas_HPP
#define czas_HPP

class czaS
{
public:
    sf::Time time;
    float czas;
    bool czas_na_1s;
    sf::Clock clock;

    czaS();
    ~czaS();
    bool dodawanie_czasu(float punkt);
    float przyspiesz(float punkt);
};

#endif
