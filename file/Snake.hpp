#include <string>
#include <SFML/Graphics.hpp>
#include "Tablice.hpp"
#include "Punkty.hpp"
#include "Ruchoma.hpp"
#include <iostream>
#include <sstream>
#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

class Snake
{

public:
    int X,Y;
    int blad_ruchu_X;
    int blad_ruchu_Y;
    int ID;
    int ogon_ID;

    int dlugosc_ogonu;
    int pkt;

    int aktualny_znak;
    int znak;
    int znak_do_bledu_podwojnego_klawisza;

    int* X_ogonu;
    int* Y_ogonu;

    std::string WorL;
    std::string liczba_wyniku;
    sf::Font font;
    sf::Text wynik;
    sf::Text Text_WorL;
    sf::Texture Texture_glowa;
    sf::Texture Texture_cialo;
    sf::Sprite Sprite_glowa;
    sf::Sprite Sprite_cialo;


    bool kolizja_z_ogonem(int x, int y);

    bool kolizja_ogony_z_ruchoma_siana(Sciana& Ruchoma);
//sterowanie
    void Sterowanie(Tablice& mapa);
//rekurencja ruchu ogona
    void ruch_ogona(int licznik);
//
    void aktualizuj_wynik();

    void dodaj_punkt(Punkty& pkt,Tablice& mapa);

    void dodaj_wzrost_weza();

    void zmiana_int_na_string();



//konstruktor domyslny
    Snake();
//konstruktor
    Snake(int x,int y,Tablice& mapa);
//destruktor
    ~Snake();

};


#endif // SNAKE_HPP_INCLUDED
