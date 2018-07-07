#include "funkcjeGry.hpp"


bool funkcje::wyjscie(Aplikacja& App)
{
    if(this->event.type == sf::Event::Closed)
    {
        App.okno.close();
        return true;
    }
    return false;
}

void funkcje::sterowanie(Aplikacja& App,Game& Gra)
{
    while(App.okno.pollEvent(this->event))
        {
            if(this->event.type == sf::Event::KeyPressed)
            {
            switch(this->event.key.code)
                {
                case sf::Keyboard::W:
                    {
                        Gra.waz.aktualny_znak = 119;
                        if(Gra.waz.aktualny_znak != Gra.waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            Gra.waz.znak = 119;
                        }
                        break;
                    }
                case sf::Keyboard::S:
                    {
                        Gra.waz.aktualny_znak = 115;
                            if(Gra.waz.aktualny_znak != Gra.waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            Gra.waz.znak = 115;
                        }
                        break;
                    }
                case sf::Keyboard::A:
                    {
                        Gra.waz.aktualny_znak = 97;
                        if(Gra.waz.aktualny_znak != Gra.waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            Gra.waz.znak = 97;
                        }
                        break;
                    }
                case sf::Keyboard::D:
                    {
                        Gra.waz.aktualny_znak = 100;
                        if(Gra.waz.aktualny_znak != Gra.waz.znak_do_bledu_podwojnego_klawisza)
                        {
                            Gra.waz.znak = 100;
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

void funkcje::draw(Aplikacja& App,Game& Gra)
{
    App.okno.clear(sf::Color::Green);
    for(int i = 0; i<=Gra.mapa.X; i++)
        {
            for(int j = 0; j<=Gra.mapa.Y; j++)
            {
                switch(Gra.mapa.tab[i][j])
                {
                case 2:
                    {
                        Gra.waz.Sprite_cialo.setPosition(i * Gra.mapa.wielkosc_grafik, j * Gra.mapa.wielkosc_grafik);
                        App.okno.draw(Gra.waz.Sprite_cialo);
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
                        Gra.mapa.Sprite.setPosition(i * Gra.mapa.wielkosc_grafik,j * Gra.mapa.wielkosc_grafik);
                        //std::cout << (i * Gra.mapa.wielkosc_grafik) << std::endl << (j * Gra.mapa.wielkosc_grafik) << std::endl << std::endl;
                        App.okno.draw(Gra.mapa.Sprite);
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
                        Gra.waz.Sprite_glowa.setPosition(i * Gra.mapa.wielkosc_grafik + Gra.waz.blad_ruchu_X ,j * Gra.mapa.wielkosc_grafik + Gra.waz.blad_ruchu_Y);
                        App.okno.draw(Gra.waz.Sprite_glowa);
                        break;
                    }

                }
                //std::cout << i << std::endl << j << std::endl << std::endl;
            }

        }
        App.okno.display();


}

void funkcje::ustaw_ID_na_mapie(Game& Gra)
{
    Gra.mapa.zeruj();//czyszczenie mapy
    int XX;
    int YY;
    Gra.mapa.tab[Gra.waz.X][Gra.waz.Y] = Gra.waz.ID;//ustawianie ID glowy snake
    for(int i = 0; i<=Gra.waz.pkt+1; i++)
    {
        XX = Gra.waz.X_ogonu[i];
        YY = Gra.waz.Y_ogonu[i];
        Gra.mapa.tab[XX][YY] = Gra.waz.ogon_ID; // ustawianie ID ciala snake
    }

    //Gra.mapa.tab[pkt.pkt_x][pkt.pkt_y] = 3; // ustawianie ID punktu

    for(int j =  0; j<= Gra.mapa.X; j++)
    {
        for(int k = 0; k<=Gra.mapa.Y; k++)
        {
            if(j==0||j==Gra.mapa.X||k==0||k==Gra.mapa.Y)
            {
                Gra.mapa.tab[j][k] = 4; // scian
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

void funkcje::kolizje(Aplikacja& App,Game& Gra)
{
    if(Gra.waz.kolizja()||this->kolizja(Gra))
    {
        App.okno.close();
    }

}

bool funkcje::kolizja(Game& Gra)
{
//kolizja z koncem mapy
    if(Gra.waz.X == Gra.mapa.X || Gra.waz.Y == Gra.mapa.Y || Gra.waz.X == 0 || Gra.waz.Y == 0)
    {
        return true;
    }
    return false;
}

