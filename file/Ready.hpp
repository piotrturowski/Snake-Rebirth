#include <string>
#include <SFML/Graphics.hpp>
#ifndef READY_HPP_INCLUDED
#define READY_HPP_INCLUDED

class Ready
{
public:
    float X;
    float Y;
    sf::Texture Texture;
    sf::Sprite Sprite;
    std::string nazwa;
    Ready();
    ~Ready();
    bool jestAktywny();
    void nadaj_teksture(std::string n,float x,float y);
    void ustaw_pozycje();
};

#endif // READY_HPP_INCLUDED
