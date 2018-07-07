#include "Gra.hpp"
#include <iostream>
Game::Game(bool tryb_multiplayer)
    :   mapa(20,20,30)
    ,   waz(5,5,this->mapa)
{
    this->tryb_multi = tryb_multiplayer;

}

Game::~Game()
{

}

void Game::run(Aplikacja& App)
{
    while(App.okno.isOpen())
    {
        this->Funkcje.sterowanie(App,Game);
        if(this->czas.dodawanie_czasu(this->waz.pkt))
        {
            this->waz.Sterowanie(this->mapa);
        }
        this->ustaw_ID_na_mapie();
        this->draw(App,this->mapa);
        //this->mapa.show();
        this->kolizje(App);
    }
}
