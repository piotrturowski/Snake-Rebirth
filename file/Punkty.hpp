#include <SFML/Graphics.hpp>
#ifndef Punkty_hpp
#define Punkty_hpp

class Snake;
class Punkty
{
public:
    int X;
    int Y;
    int ID;
    sf::Texture Texture;
    sf::Sprite Sprite;

    void losuj(int x, int y);

    Punkty(int x,int y);
    ~Punkty();

};

#endif
