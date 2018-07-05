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
    std::cout << "." << std::endl;
    while(App.okno.isOpen())
    {
        this->sterowanie(App);
        this->ustaw_ID_na_mapie();
        this->draw(App);
        //this->mapa.show();
    }
}

bool Game::wyjscie(Aplikacja& App)
{
    if(this->event.type == sf::Event::Closed)
    {
        App.okno.close();
        return true;
    }
    return false;
}

void Game::sterowanie(Aplikacja& App)
{
    while(App.okno.pollEvent(this->event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
            switch(this->event.key.code)
                {
                case sf::Keyboard::W:
                    {
                        waz.aktualny_znak = 119;
                        if(waz.aktualny_znak != waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            waz.znak = 119;
                        }
                        break;
                    }
                case sf::Keyboard::S:
                    {
                        waz.aktualny_znak = 115;
                            if(waz.aktualny_znak != waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            waz.znak = 115;
                        }
                        break;
                    }
                case sf::Keyboard::A:
                    {
                        waz.aktualny_znak = 97;
                        if(waz.aktualny_znak != waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            waz.znak = 97;
                        }
                        break;
                    }
                case sf::Keyboard::D:
                    {
                        waz.aktualny_znak = 100;
                        if(waz.aktualny_znak != waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            waz.znak = 100;
                        }
                        break;
                    }
                }
            }
            switch(this->event.type)
            {

                case sf::Event::Closed:
                {
                    App.okno.close();
                    break;
                }
            }
        }
}

void Game::draw(Aplikacja& App)
{
    App.okno.clear(sf::Color::Green);
    for(int i = 0; i<=this->mapa.X; i++)
        {
            for(int j = 0; j<=this->mapa.Y; j++)
            {
                switch(this->mapa.tab[i][j])
                {
                case 2:
                    {
                        this->waz.Sprite_cialo.setPosition(i * this->mapa.wielkosc_grafik, j * this->mapa.wielkosc_grafik);
                        App.okno.draw(this->waz.Sprite_cialo);
                        break;
                    }
                    /*
                case 3:
                    {
                        for(int k = 0 ; k<=waz.pkt+1;k++)
                        {
                            if(waz.X_ogonu[k] == i && waz.Y_ogonu[k] == j)
                            {
                                sprite_cialo.setPosition(i * mapa.wielkosc_grafik,j * mapa.wielkosc_grafik);
                                scena.draw(sprite_cialo);
                            }
                        }
                        sprite_punkt.setPosition(i * mapa.wielkosc_grafik,j * mapa.wielkosc_grafik);
                        scena.draw(sprite_punkt);
                        break;
                    }
                    */

                case 4:
                    {
                        this->mapa.Sprite.setPosition(i * this->mapa.wielkosc_grafik,j * this->mapa.wielkosc_grafik);
                        //std::cout << (i * this->mapa.wielkosc_grafik) << std::endl << (j * this->mapa.wielkosc_grafik) << std::endl << std::endl;
                        App.okno.draw(this->mapa.Sprite);
                        break;
                    }

                    /*
                case 5:
                    {
                        sprite_przeszkoda.setPosition(Ruchoma_sciana->X*mapa.wielkosc_grafik + Ruchoma_sciana->blad_ruchu_X,Ruchoma_sciana->Y*mapa.wielkosc_grafik + Ruchoma_sciana->blad_ruchu_y);
                        scena.draw(sprite_przeszkoda);
                        break;
                    }
                    */
                case 1:
                    {
                        this->waz.Sprite_glowa.setPosition(i * this->mapa.wielkosc_grafik + this->waz.blad_ruchu_X ,j * this->mapa.wielkosc_grafik + this->waz.blad_ruchu_Y);
                        App.okno.draw(this->waz.Sprite_glowa);
                        break;
                    }

                }
                //std::cout << i << std::endl << j << std::endl << std::endl;
            }

        }
        App.okno.display();


}

void Game::ustaw_ID_na_mapie()
{
    mapa.zeruj();//czyszczenie mapy
    int XX;
    int YY;
    this->mapa.tab[waz.X][waz.Y] = this->waz.ID;//ustawianie ID glowy snake
    for(int i = 0; i<=this->waz.pkt+1; i++)
    {
        XX = this->waz.X_ogonu[i];
        YY = this->waz.Y_ogonu[i];
        this->mapa.tab[XX][YY] = this->waz.ogon_ID; // ustawianie ID ciala snake
    }

    //this->mapa.tab[pkt.pkt_x][pkt.pkt_y] = 3; // ustawianie ID punktu

    for(int j =  0; j<= this->mapa.X; j++)
    {
        for(int k = 0; k<=this->mapa.Y; k++)
        {
            if(j==0||j==this->mapa.X||k==0||k==this->mapa.Y)
            {
                this->mapa.tab[j][k] = 4; // scian
            }

        }
    }
    /*
    if(this->mapa.ilosc_przeszkod == 1)
    {
        this->mapa.tab[Ruchoma_sciana->X][Ruchoma_sciana->Y] = Ruchoma_sciana->ID; // ustawianie ID przeszkody
    }
    */
}
