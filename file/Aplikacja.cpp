#include "Aplikacja.hpp"
#include "Menu.hpp"


Aplikacja::Aplikacja()
{
    srand (time(NULL));
    this->wysokosc = 600;
    this->szerokosc = 600;
    this->nazwa = "Snake Rebirth";
    this->okno.create(sf::VideoMode(this->wysokosc,this->szerokosc),this->nazwa);
    this->mysz_X=0;
    this->mysz_Y=0;
}

Aplikacja::~Aplikacja()
{

}

void Aplikacja::run(Aplikacja& App)
{
    Menu menu(App);
    menu.run(App,menu);


}
