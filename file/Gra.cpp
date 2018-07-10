#include "Gra.hpp"
#include <iostream>
Game::Game(bool tryb_multiplayer)
    :   mapa(20,20,30)
    ,   waz(5,5,this->mapa)
    ,   pkt(this->mapa.X,this->mapa.Y)
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
        this->Funkcje.sterowanie(App,this->waz);
        if(this->czas.dodawanie_czasu(this->waz.pkt))
        {
            this->waz.Sterowanie(this->mapa);
            this->waz.dodaj_punkt(this->pkt,this->mapa);
        }
        this->Funkcje.ustaw_ID_na_mapie(this->mapa,this->waz,this->pkt);
        this->Funkcje.draw(App,this->mapa,this->waz,this->pkt);
        //this->mapa.show();
        this->Funkcje.kolizje(App,this->waz,this->mapa,this->pkt);
    }
}
