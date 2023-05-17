#include "Team.hpp"
using namespace ariel;

Team::Team(Character *leader) : _leader(leader)
{
    _teamMembers.push_back(leader);
}

Team::~Team()
{
}
Character *Team::getLeader() const { return _leader; }

void Team::add(Character *charater)
{
    // if ()
    // {
    //     /* code */
    // }
    _teamMembers.push_back(charater);
}
void Team::attack(Team *enemyTeam) {}
int Team::stillAlive() const
{
    int teamSIZE = _teamMembers.size();
    int countStillAlive = 0;
    // for (int i = 0; i < teamSIZE; i++)
    // {
    //     // check all members in the team if they alive
    //     if (_teamMembers.at(i)->isAlive())
    //     {
    //         ++countStillAlive;
    //     }
    // }
    return countStillAlive;
}

void Team::print() const {}