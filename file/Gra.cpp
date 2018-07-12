#include "Gra.hpp"
#include <iostream>


Game::Game(bool tryb_multiplayer)
    :   mapa(20,20,30)
    ,   waz(5,5,this->mapa)
    ,   pkt(this->mapa.X,this->mapa.Y)
    ,   Ruchoma(this->mapa)
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
            if(this->Ruchoma.kasuj_sciane(this->mapa))
            {
                this->Ruchoma.losuj(mapa);
            }
            this->Ruchoma.ruch_sciany();

        }
        this->Funkcje.ustaw_ID_na_mapie(this->mapa,this->waz,this->pkt,this->Ruchoma);
        this->Funkcje.draw(App,this->mapa,this->waz,this->pkt,this->Ruchoma);
        //this->mapa.show();
        this->Funkcje.kolizje(App,this->waz,this->mapa,this->pkt);
    }
}
