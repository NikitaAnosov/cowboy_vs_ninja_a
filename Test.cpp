#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Point Test")
{
    CHECK_NOTHROW(Point(1, 2));
    Point p(3, 4), q(4, 4);
    CHECK(p.getX() == 3);
    CHECK(p.getY() == 4);
    CHECK(q.distance(p) == 1);
    CHECK(p.distance(q) == 1);
    CHECK_NOTHROW(p.print());
    CHECK_NOTHROW(p.moveTowards(p, q, 5));
    Point s = p.moveTowards(p, q, 5);
    CHECK(s.getX() == q.getX());
    CHECK(s.getY() == q.getY());
}

TEST_CASE("Character Test")
{
    CHECK_NOTHROW(Character("nik", Point(1, 2), 70));
    Character c1("nik", Point(1, 2), 70);
    CHECK(c1.getName() == "nik");
    CHECK(c1.getLocation().getX() == 1);
    CHECK(c1.getLocation().getY() == 2);
    CHECK(c1.getHp() == 70);
    CHECK(c1.isAlive() == true);
    CHECK_NOTHROW(c1.print());
    c1.hit(20);
    CHECK(c1.getHp() == 50);
    Character *c2 = new Character("bob", Point(1, 4), 70);
    double dist = c1.distance(c2);
    CHECK(dist == 2);
    c1.hit(50);
    CHECK(c1.isAlive() == false);
}

TEST_CASE("Ninja Test")
{
    Point a(32, 44), b(34, 44);
    CHECK_NOTHROW(Ninja("tom", a, 40, 30));
    Ninja c1("tom", a, 40, 30);
    Ninja *c2 = new Ninja("tom", b, 60, 30);
    CHECK(c1.getName() == "tom");
    CHECK(c1.getLocation().getX() == 32);
    CHECK(c1.getLocation().getY() == 44);
    CHECK(c1.getHp() == 40);
    CHECK(c1.getSpeed() == 30);
    CHECK(c1.isAlive() == true);
    CHECK_NOTHROW(c1.move(c2));
    CHECK_NOTHROW(c1.slash(c2));
}

TEST_CASE("YoungNinja / TrainedNinja / OldNinja")
{
    Point a(32, 44), b(34, 44);
    CHECK_NOTHROW(YoungNinja("sushi", a));
    CHECK_NOTHROW(TrainedNinja("sushi", b));
    CHECK_NOTHROW(OldNinja("sushi", b));

    YoungNinja *young = new YoungNinja("p1", a);
    TrainedNinja *trained = new TrainedNinja("p2", b);
    OldNinja *old = new OldNinja("p3", b);

    CHECK(young->getName() == "p1");
    CHECK(trained->getName() == "p2");
    CHECK(old->getName() == "p3");

    CHECK(young->getSpeed() == 14);
    CHECK(trained->getSpeed() == 12);
    CHECK(old->getSpeed() == 8);

    CHECK(young->getHp() == 100);
    CHECK(trained->getHp() == 120);
    CHECK(old->getHp() == 150);

    CHECK_NOTHROW(young->move(trained));
    CHECK_NOTHROW(old->move(young));
    CHECK_NOTHROW(trained->move(old));

    CHECK_NOTHROW(young->slash(trained));
    CHECK_NOTHROW(old->slash(young));
    CHECK_NOTHROW(trained->slash(old));
}


TEST_CASE("move / slash / shoot")
{
    Point a(1, 2), b(3, 2);
    Cowboy *c1 = new Cowboy("p1", a);
    Cowboy *c2 = new Cowboy("p2", b);
    CHECK(c1->getName() == "p1");
    CHECK(c1->getHp() == 110);
    CHECK(c1->getBullets() == 6);
    c1->shoot(c2);
    CHECK(c2->getHp() == 100);
    CHECK_NOTHROW(c1->shoot(c2));
    CHECK_NOTHROW(c1->reload());
    CHECK(c1->getBullets() == 6);
    for (int i = 0; i < 6; i++)
    {
        c1->shoot(c2);
    }
    CHECK_THROWS(c1->shoot(c2));
    CHECK(c1->hasboolets() == false);

}

TEST_CASE("move / slash / shoot")
{
    Point a(1, 2), b(3, 2), c(10, 10);
    YoungNinja *p1 = new YoungNinja("p1", a);
    TrainedNinja *p2 = new TrainedNinja("p2", b);
    OldNinja *p3 = new OldNinja("p3", c);
    Cowboy *c4 = new Cowboy("p3", b);
    p1->slash(p3);
    p1->slash(p2);
    CHECK(p2->getHp() == 80); // 120 - 40 = 80
    CHECK(p3->getHp() == 150); // 150 - 0 = 150
    c4->shoot(p1);
    CHECK(p1->getHp() == 90);// 100 - 10 = 90
    CHECK(c4->hasboolets() == true);
    CHECK(c4->getBullets() == 5);
    c4->reload();
    CHECK(c4->getBullets() == 6);
    p1->slash(p2);
    CHECK(p2->getHp() == 40); 
    p1->slash(p2);
    CHECK(p2->isAlive() == false);
    //p2 dead
    CHECK_THROWS(p1->slash(p2));
    CHECK_THROWS(p3->slash(p3));
    CHECK_THROWS(p2->slash(p1));
    CHECK_THROWS(c4->shoot(p2));
    CHECK_THROWS(p1->move(p2));
    CHECK_THROWS(p2->move(p1));
    CHECK_THROWS(p3->move(p3));
}

TEST_CASE("Team")
{
    Point a(1, 2), b(3, 2), c(10, 10);
    YoungNinja *p1 = new YoungNinja("p1", a);
    TrainedNinja *p2 = new TrainedNinja("p2", b);
    OldNinja *p3 = new OldNinja("p3", c);
    Cowboy *c4 = new Cowboy("p3", b);
    Team team(p1);
    team.add(p2);
    CHECK(team.stillAlive() == 2);
    CHECK(team.getLeader() == p1);
    YoungNinja *n1 = new YoungNinja("n1", b);
    TrainedNinja *n2 = new TrainedNinja("n2", b);
    Team team2(n1);
    team2.add(n2);
    //120 - 40 - 40 = 40
    team2.attack(&team);
    //TrainedNinja dead
    team2.attack(&team);
    CHECK(team.stillAlive() == 1);
    //100 - 40 -40 = 20
    team2.attack(&team);
    // YoungNinja dead
    team2.attack(&team);
    CHECK_THROWS(team.attack(&team2));
    CHECK_THROWS(team2.attack(&team));
    CHECK_THROWS(team.add(p1));
}