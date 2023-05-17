#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
using std::string;
using std::cout;
using std::endl;
namespace ariel{
    class Character{
        private:
        string _name;
        Point _location;
        int _hp;
        public:
        //constructor:
        Character(string name, Point location, int hp);
        //gettes
        string getName() const;
        Point getLocation() const;
        int getHp() const;
        //settes for Ninja class (move func)
        void setLocation(Point location);
        //functions
         bool isAlive() const;
         double distance(Character *destCharacter) const;
         void hit (int hitPoints);
         string print() const;

    };
}
#endif
