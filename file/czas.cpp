#include "czas.hpp"
#include <iostream>

czaS::czaS()
{

}

czaS::~czaS()
{

}




float czaS::przyspiesz(float punkt)
{
    if((1-(punkt/20)) <= 0.3)
    {
        return 0.3;
    }
    else
    {

        punkt = (1-(punkt/20));

        return punkt;
    }

}

bool czaS::dodawanie_czasu(float punkt)
{
    this->time = clock.getElapsedTime();
    this->clock.restart().asSeconds();

//dodawanie czasu do 1s;
    if(this->czas >= this->przyspiesz(punkt))
    {
        this->czas = 0;
        return true;
    }
    else
    {
        this->czas = this->czas + this->time.asSeconds();
        return false;
    }
    return false;
}
