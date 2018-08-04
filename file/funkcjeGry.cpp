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

void funkcje::sterowanie(Aplikacja& App,Snake& waz,Snake& waz2)
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
                    if(this->tryb_multi == true)
                    {
                    case sf::Keyboard::Up:
                        {
                            waz2.aktualny_znak = 119;
                            if(waz2.aktualny_znak != waz2.znak_do_bledu_podwojnego_klawisza)
                            {
                                waz2.znak = 119;
                            }
                            break;
                        }
                    case sf::Keyboard::Down:
                        {
                            waz2.aktualny_znak = 115;
                            if(waz2.aktualny_znak != waz2.znak_do_bledu_podwojnego_klawisza)
                            {
                                waz2.znak = 115;
                            }
                            break;
                        }
                    case sf::Keyboard::Left:
                        {
                            waz2.aktualny_znak = 97;
                            if(waz2.aktualny_znak != waz2.znak_do_bledu_podwojnego_klawisza)
                            {
                                waz2.znak = 97;
                            }
                            break;
                        }
                    case sf::Keyboard::Right:
                        {
                            waz2.aktualny_znak = 100;
                            if(waz2.aktualny_znak != waz2.znak_do_bledu_podwojnego_klawisza)
                            {
                                waz2.znak = 100;
                            }
                            break;
                        }
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

void funkcje::draw(Aplikacja& App,Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2)
{
    App.okno.clear(sf::Color::Green);
    App.okno.draw(waz.wynik);
    if(this->tryb_multi == true)
    {
        sf::RectangleShape line(sf::Vector2f(5, 540));
        line.setPosition(300,30);
        App.okno.draw(line);
        App.okno.draw(waz2.wynik);
    }
    for(int i = 0; i<=mapa.X; i++)
        {
            for(int j = 0; j<=mapa.Y; j++)
            {
                switch(mapa.tab[i][j])
                {
                case 1:
                    {

                        break;
                    }
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

                case 6:
                    {
                        laser.Sprite.setPosition(i * mapa.wielkosc_grafik ,j * mapa.wielkosc_grafik);
                        App.okno.draw(laser.Sprite);
                        break;
                    }


                }
                //std::cout << i << std::endl << j << std::endl << std::endl;
            }


        }
        waz.Sprite_glowa.setPosition(waz.X * mapa.wielkosc_grafik + waz.blad_ruchu_X ,waz.Y * mapa.wielkosc_grafik + waz.blad_ruchu_Y);
        App.okno.draw(waz.Sprite_glowa);
        if(this->tryb_multi==true)
        {
            waz2.Sprite_glowa.setPosition(waz2.X * mapa.wielkosc_grafik + waz2.blad_ruchu_X ,waz2.Y * mapa.wielkosc_grafik + waz2.blad_ruchu_Y);
            App.okno.draw(waz2.Sprite_glowa);
        }
        App.okno.display();


}

void funkcje::ustaw_ID_na_mapie(Tablice& mapa,Snake& waz,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2)
{
    mapa.zeruj();//czyszczenie mapy

    this->ustawianie_weza(mapa,waz);
    if(this->tryb_multi)
    {
        this->ustawianie_weza(mapa,waz2);
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
    laser.ustaw_ID(mapa);
}

void funkcje::kolizje(Aplikacja& App,Snake& waz,Tablice& mapa,Punkty& pkt,Sciana& Ruchoma,Laser& laser,Snake& waz2)
{
    if(waz.kolizja_z_ogonem(waz.X,waz.Y)||this->kolizja(waz,mapa)) //kolizja z mapa i ogonem
    {
        waz.Przegrana();
        if(this->tryb_multi == true)
        {
            waz2.Wygrana();
        }
        this->koniec_gry(App,waz,waz2);
        App.okno.close();
    }
    if(waz.kolizja_ogony_z_ruchoma_siana(Ruchoma)) // kolizja z ruchoma sciana
    {
        waz.Przegrana();
        if(this->tryb_multi == true)
        {
            waz2.Wygrana();
        }
        this->koniec_gry(App,waz,waz2);
        App.okno.close();
    }
    if(laser.kolizja(waz.X,waz.Y)) //kolizja glowy weza z laserem
    {
        waz.Przegrana();
        if(this->tryb_multi == true)
        {
            waz2.Wygrana();
        }
        this->koniec_gry(App,waz,waz2);
        App.okno.close();
    }
    if(laser.kolizja_z_ogonem(waz.X_ogonu,waz.pkt+1)||laser.kolizja_z_ogonem(waz.Y_ogonu,waz.pkt+1))
    {
        waz.odejmij_punkt();

    }
    if(this->tryb_multi == true)
    {
        if(waz2.kolizja_z_ogonem(waz2.X,waz2.Y)||this->kolizja(waz2,mapa))
        {
            waz2.Przegrana();
            if(this->tryb_multi == true)
            {
                waz2.Wygrana();
            }
            this->koniec_gry(App,waz,waz2);
            App.okno.close();
        }
        if(waz2.kolizja_ogony_z_ruchoma_siana(Ruchoma))
        {
            waz2.Przegrana();
            if(this->tryb_multi == true)
            {
                waz2.Wygrana();
            }
            this->koniec_gry(App,waz,waz2);
            App.okno.close();
        }
        if(laser.kolizja(waz2.X,waz2.Y))
        {
            waz2.Przegrana();
            if(this->tryb_multi == true)
            {
                waz2.Wygrana();
            }
            this->koniec_gry(App,waz,waz2);
            App.okno.close();
        }
        if(waz.X == waz2.X && waz.Y == waz2.Y)
        {
            waz2.Przegrana();
            if(this->tryb_multi == true)
            {
                waz2.Wygrana();
            }
            this->koniec_gry(App,waz,waz2);
            App.okno.close();
        }
        if(waz.kolizja_z_ogonem(waz2.X,waz2.Y)||waz2.kolizja_z_ogonem(waz.X,waz.Y))
        {
            waz2.Przegrana();
            if(this->tryb_multi == true)
            {
                waz2.Wygrana();
            }
            this->koniec_gry(App,waz,waz2);
            App.okno.close();
        }
        if(laser.kolizja_z_ogonem(waz2.X_ogonu,waz2.pkt+1)||laser.kolizja_z_ogonem(waz2.Y_ogonu,waz2.pkt+1))
        {
            waz2.odejmij_punkt();
        }
    }
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

void funkcje::ustawianie_weza(Tablice& mapa,Snake& waz)
{
    int XX;
    int YY;
    mapa.tab[waz.X][waz.Y] = waz.ID;//ustawianie ID glowy snake
    for(int i = 0; i<=waz.pkt+1; i++)
    {
        XX = waz.X_ogonu[i];
        YY = waz.Y_ogonu[i];
        mapa.tab[XX][YY] = waz.ogon_ID; // ustawianie ID ciala snake
    }
}

void funkcje::koniec_gry(Aplikacja& App,Snake& waz, Snake& waz2)
{
    App.okno.draw(waz.Text_WorL);
    App.okno.draw(waz2.Text_WorL);
    App.okno.display();
    while(!App.okno.pollEvent(this->event))
    {
        if(this->event.type == sf::Event::KeyPressed)
        {
            break;
        }
    }
}

void funkcje::maxpkt(Aplikacja& App,Snake& waz, Snake& waz2)
{
    if(waz.pkt == this->maksymalna_ilosc_punktow)
    {
        waz.Wygrana();
        if(this->tryb_multi == true)
        {
            waz2.Przegrana();
        }
        this->koniec_gry(App,waz,waz2);
        App.okno.close();
    }
    if(waz2.pkt == this->maksymalna_ilosc_punktow && this->tryb_multi == true)
    {
        waz.Przegrana();
        waz2.Wygrana();
        this->koniec_gry(App,waz,waz2);
        App.okno.close();
    }
}

