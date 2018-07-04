#include "Menu.hpp"
#include "Ready.hpp"
#include "Gra.hpp"

Menu::Menu(Aplikacja& App)
{
//wczytanie plikow
    this->jeden_gracz.nadaj_teksture("file/art/jeden gracz.png",((App.szerokosc/2)-90),((App.wysokosc/2)-90));
    this->dwoch_graczy.nadaj_teksture("file/art/Dwoch graczy.png",((App.szerokosc/2)-90),(App.wysokosc/2)-30);
    this->wyjscie.nadaj_teksture("file/art/Wyjscie.png",((App.szerokosc/2)-90),((App.wysokosc/2)+30));
}

Menu::~Menu()
{

}

void Menu::run(Aplikacja& App,Menu& menu)
{
//petla z opcjami pojedynczy gracz dwoch graczy opcje oraz wyjscie
    while(App.okno.isOpen())// poki okno aplikacji jest otwarte
    {
        sterowanie(App);
        this->rysuj(App);
    }
}

void Menu::rysuj(Aplikacja& App)
{
    App.okno.clear(sf::Color::Green);
    App.okno.draw(this->jeden_gracz.Sprite);
    App.okno.draw(this->dwoch_graczy.Sprite);
    App.okno.draw(this->wyjscie.Sprite);
    App.okno.display();

}

void Menu::sterowanie(Aplikacja& App)
{
    while(App.okno.pollEvent(this->event))
        {
            switch(this->event.type)
            {
            case sf::Event::MouseButtonPressed:
                {
                    switch(this->event.key.code)
                    {
                    case sf::Mouse::Left:
                        {
                            if(App.mysz_X >= 210&&  App.mysz_X <= 390)
                            {
                                if(App.mysz_Y >= 200 && App.mysz_Y <=260)
                                {
                                    //gra pojedyncza
                                    this->run_gra(App,0);
                                }
                                if(App.mysz_Y >= 260 && App.mysz_Y <=320)
                                {
                                    //gra multi
                                    this->run_gra(App,1);
                                }
                                if(App.mysz_Y >=320 && App.mysz_Y<=380)
                                {
                                    //wyjscie
                                    App.okno.close();
                                }
                            }
                            break;
                        }
                    }

                    break;
                }
            case sf::Event::MouseMoved:
                {
                    App.mysz_X= this->event.mouseMove.x;
                    App.mysz_Y= this->event.mouseMove.y;
                    break;
                }
            case sf::Event::Closed:
                {
                    App.okno.close();
                    break;
                }
            }
        }
}

void Menu::run_gra(Aplikacja& App, bool tryb_multiplayer)
{
    // tworzona klasa w funkcji aby skasowac gdy wyjdzie
    Game Gra(tryb_multiplayer);
    Gra.run(App);
}
