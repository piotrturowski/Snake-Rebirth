#include "Gra.hpp"
#include <iostream>


Game::Game(bool tryb_multiplayer)
    :   mapa(20,20,30)
    ,   waz(5,5,this->mapa)
    ,   waz2(15,15,this->mapa)
    ,   pkt(this->mapa.X,this->mapa.Y)
    ,   Ruchoma(this->mapa)
    ,   laser(this->mapa)
{
    this->tryb_multi = tryb_multiplayer;
    this->Funkcje.tryb_multi = tryb_multiplayer;
    if(tryb_multiplayer == false)
    {
        this->waz.wynik.setPosition(275,225);
        this->waz.Text_WorL.setPosition(230,330);
    }
    if(tryb_multiplayer == true)
    {
        this->waz.wynik.setPosition(160,225);
        this->waz2.wynik.setPosition(415,225);
        this->waz.Text_WorL.setPosition(110,330);
        this->waz2.Text_WorL.setPosition(370,330);
    }
}

Game::~Game()
{

}

void Game::run(Aplikacja& App)
{
    while(App.okno.isOpen())
    {
        this->Funkcje.sterowanie(App,this->waz,this->waz2);
        if(this->czas.dodawanie_czasu(this->waz.pkt))
        {
            this->waz.Sterowanie(this->mapa);
            if(this->tryb_multi == true)
            {
                this->waz2.Sterowanie(this->mapa);
            }
            this->waz.dodaj_punkt(this->pkt,this->mapa);
            if(this->tryb_multi == true)
            {
                this->waz2.dodaj_punkt(this->pkt,this->mapa);
            }
            if(this->Ruchoma.kasuj_sciane(this->mapa))
            {
                this->Ruchoma.losuj(mapa);
            }
            this->Ruchoma.ruch_sciany();
            this->laser.koniec(this->mapa);
            this->laser.ruch(mapa);
        }
        this->Funkcje.ustaw_ID_na_mapie(this->mapa,this->waz,this->pkt,this->Ruchoma,this->laser,this->waz2);
        this->Funkcje.draw(App,this->mapa,this->waz,this->pkt,this->Ruchoma,this->laser,this->waz2);
        this->Funkcje.kolizje(App,this->waz,this->mapa,this->pkt,this->Ruchoma,this->laser,this->waz2);
    }
}
