#include <SFML/Graphics.hpp>
#ifndef czas_HPP
#define czas_HPP

class czaS
{
public:
    sf::Time time;
    float czas;
    sf::Clock clock;

    czaS();
    ~czaS();
    bool dodawanie_czasu(float punkt);
    float przyspiesz(float punkt);
};

#endif
