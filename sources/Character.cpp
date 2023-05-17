#include "Character.hpp"
using namespace ariel;

Character::Character(string name, Point location, int hp) : _name(name), _location(location), _hp(hp) {}

string Character::getName() const { return _name; }
Point Character::getLocation() const { return _location; }
int Character::getHp() const{ return _hp;}
bool Character::isAlive() const { return (_hp > 0); }
double Character::distance(Character *destCharacter) const
{
    return _location.distance(destCharacter->getLocation());
}
void Character::hit(int hitPoints) { _hp -= hitPoints; }
string Character::print() const
{
    string print = "";
    print += "name: " + _name + ", hp: " + to_string(getHp()) + ", location: " + _location.print() ;
    return print;
}
 
 void Character::setLocation(Point location) {_location = location;}
