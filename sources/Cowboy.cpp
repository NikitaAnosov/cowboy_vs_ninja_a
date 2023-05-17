#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), _bulletsAmount(6){}
void Cowboy::shoot(Character *enemy) 
{
    if (this == enemy)
    {
        throw std::exception();
    }
    if (isAlive() == false && enemy->isAlive() == false)
    {
        throw std::exception();
    }
    if (hasboolets())
    {
        enemy->hit(10);
        _bulletsAmount--;
    }
    
}
bool Cowboy::hasboolets() const {return (_bulletsAmount > 0);}
void Cowboy::reload() {_bulletsAmount = 6 ;}
int Cowboy::getBullets() const {return _bulletsAmount;}
