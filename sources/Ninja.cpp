#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(string name, Point location, int hp, int speed) : Character(name, location, hp), _speed(speed) {}
void Ninja::move(Character *enemy)
{
    if (isAlive() == false)
    {
        throw std::exception();
    }
    Point dest = getLocation().moveTowards(this->getLocation(), enemy->getLocation(), _speed);
    setLocation(dest);
}
void Ninja::slash(Character *enemy)
{
    if (enemy->isAlive() == false && isAlive() == false)
    {
        throw std::exception();
    }

    if (this == enemy)
    {
        throw std::exception();
    }

    // if (distance(*enemy) <= 1) // min 1 meter from the enemy
    // {
        enemy->hit(40); // 20 damage
    // }
}

// string Ninja::print() const 
// { 
//     string print = "";
//     print += "Ninja: " + Character::print();
//     return print;
// }


int Ninja::getSpeed() const { return _speed; }

// charaters
YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {}
TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {}
OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {}
