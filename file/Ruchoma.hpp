#ifndef Ruchoma_hpp
#define Ruchoma_hpp
#include "Tablice.hpp"


class Sciana
{
public:

    int X;
    int Y;
    int ID;
    int blad_ruchu_X;
    int blad_ruchu_y;
    sf::Sprite Sprite;
    sf::Texture Texture;
    std::string kierunek;

    void losuj(Tablice& mapa);
    void ruch_sciany();
    bool kasuj_sciane(Tablice& mapa);
    Sciana(Tablice& mapa);
    ~Sciana();
};

#endif // Snake_hpp
