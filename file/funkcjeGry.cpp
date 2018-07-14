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

void funkcje::sterowanie(Aplikacja& App,Snake& waz)
{
    while(App.okno.pollEvent(this->event))
        {
            if(this->event.type == sf::Event::KeyPressed)
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

void funkcje::draw(Aplikacja& App,Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma)
{
    App.okno.clear(sf::Color::Green);
    for(int i = 0; i<=mapa.X; i++)
        {
            for(int j = 0; j<=mapa.Y; j++)
            {
                switch(mapa.tab[i][j])
                {
                case 2:
                    {
                        waz.Sprite_cialo.setPosition(i * mapa.wielkosc_grafik, j * mapa.wielkosc_grafik);
                        App.okno.draw(waz.Sprite_cialo);
                        break;
                    }
                case 3:
                    {
                        for(int k = 0 ; k<=waz.pkt+1;k++)
                        {
                            if(waz.X_ogonu[k] == i && waz.Y_ogonu[k] == j)
                            {
                                waz.Sprite_cialo.setPosition(i * mapa.wielkosc_grafik,j * mapa.wielkosc_grafik);
                                App.okno.draw(waz.Sprite_cialo);
                            }
                        }
                        pkt.Sprite.setPosition(i * mapa.wielkosc_grafik,j * mapa.wielkosc_grafik);
                        App.okno.draw(pkt.Sprite);
                        break;
                    }
                case 4:
                    {
                        mapa.Sprite.setPosition(i * mapa.wielkosc_grafik,j * mapa.wielkosc_grafik);
                        //std::cout << (i * mapa.wielkosc_grafik) << std::endl << (j * mapa.wielkosc_grafik) << std::endl << std::endl;
                        App.okno.draw(mapa.Sprite);
                        break;
                    }
                case 5:
                    {
                        Ruchoma.Sprite.setPosition(Ruchoma.X*mapa.wielkosc_grafik + Ruchoma.blad_ruchu_X,Ruchoma.Y*mapa.wielkosc_grafik + Ruchoma.blad_ruchu_y);
                        App.okno.draw(Ruchoma.Sprite);
                        break;
                    }
                case 1:
                    {
                        waz.Sprite_glowa.setPosition(i * mapa.wielkosc_grafik + waz.blad_ruchu_X ,j * mapa.wielkosc_grafik + waz.blad_ruchu_Y);
                        App.okno.draw(waz.Sprite_glowa);
                        break;
                    }

                }
                //std::cout << i << std::endl << j << std::endl << std::endl;
            }

        }
        App.okno.display();


}

void funkcje::ustaw_ID_na_mapie(Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma)
{
    mapa.zeruj();//czyszczenie mapy
    int XX;
    int YY;
    mapa.tab[waz.X][waz.Y] = waz.ID;//ustawianie ID glowy snake
    for(int i = 0; i<=waz.pkt+1; i++)
    {
        XX = waz.X_ogonu[i];
        YY = waz.Y_ogonu[i];
        mapa.tab[XX][YY] = waz.ogon_ID; // ustawianie ID ciala snake
    }

    mapa.tab[pkt.X][pkt.Y] = pkt.ID; // ustawianie ID punktu

    for(int j =  0; j<= mapa.X; j++)
    {
        for(int k = 0; k<=mapa.Y; k++)
        {
            if(j==0||j==mapa.X||k==0||k==mapa.Y)
            {
                mapa.tab[j][k] = 4; // scian
            }

        }
    }
    mapa.tab[Ruchoma.X][Ruchoma.Y] = Ruchoma.ID; // ustawianie ID przeszkody


}

void funkcje::kolizje(Aplikacja& App,Snake& waz,Tablice& mapa,Punkty& pkt,Sciana& Ruchoma)
{
    if(waz.kolizja_z_ogonem()||this->kolizja(waz,mapa))
    {
        App.okno.close();
    }
    waz.kolizja_ogony_z_ruchoma_siana(Ruchoma);

}

bool funkcje::kolizja(Snake& waz,Tablice& mapa)
{
//kolizja z koncem mapy
    if(waz.X == mapa.X || waz.Y == mapa.Y || waz.X == 0 || waz.Y == 0)
    {
        return true;
    }

    return false;
}

