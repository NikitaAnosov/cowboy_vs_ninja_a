#ifndef TEAM_HPP
#define TEAM_HPP
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
using std::vector;
namespace ariel
{
    class Team
    {
    private:
        vector<Character *> _teamMembers;
        Character *_leader;

    public:
        // constructor:
        Team(Character *leader);
        ~Team();
        // getters
        Character* getLeader() const;
        // functions
        void add(Character *charater);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;
    };

    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
    };
}
#endif