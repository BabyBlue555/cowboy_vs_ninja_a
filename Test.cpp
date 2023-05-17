#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cmath> // for test of distance function
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
// #include "sources/Team2.hpp"
#include <random>
#include <chrono>
#include <iostream>
using namespace ariel;
using namespace std;


/* helping function for creating multiple characters and add them to a team in iteration
*/
double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}


const int MAX_TEAM = 10;

TEST_CASE("1-Point Class"){
    Point p1(3,5),p2(3.0,3.5),p3(-6,-3);

    CHECK_EQ(p1.getX(),3);
    CHECK_EQ(p2.getY(),5);
    CHECK_EQ(p1.getX(),3.0);
    CHECK_EQ(p2.getY(),5.0);
    CHECK_EQ(p1.distance(p2),0.0);
    CHECK_EQ(p1.distance(p1),0);
    CHECK_EQ(p1.distance(p3),sqrt(145));
    
    double distance = p1.distance(p3);
    double half_p = distance / 2;
    double third_p = distance / 3;
    CHECK_NOTHROW(Point::moveTowards(p1, p3, third_p));
    CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1),std::invalid_argument);

}

TEST_CASE("2-Characters Initialization"){
    Cowboy cowboy("Mac", Point(2, 3));
    CHECK_EQ(cowboy.getName(),"Mac");
    CHECK(cowboy.hasboolets());
    CHECK_EQ(cowboy.getLocation().distance(Point(2,3)),0);
    CHECK(cowboy.isAlive());

    OldNinja O_ninja("Salvador",Point(2,3));
    CHECK_EQ( O_ninja.getLocation().distance(Point(2,3)),0);
    CHECK( O_ninja.isAlive());

    TrainedNinja T_ninja("Syn",Point(-2,3));
    CHECK_EQ( T_ninja.getLocation().distance(Point(-2,3)),0);
    CHECK( T_ninja.isAlive());

    YoungNinja Y_ninja("Salma",Point(-2,3));
    CHECK_EQ( T_ninja.getLocation().distance(Point(-2,3)),0);
    CHECK( T_ninja.isAlive());

}

TEST_CASE("3- Team initialization"){
    Cowboy *cowboy= new Cowboy("Mac",Point(2, 3));
    Team team1(cowboy);
    CHECK_EQ(team1.stillAlive(), 1);
    OldNinja *O_ninja= new OldNinja("Salvador",Point(2,3));
    TrainedNinja *T_ninja=new TrainedNinja("Syn",Point(-2,3));
    YoungNinja *Y_ninja= new YoungNinja("Salma",Point(-2,3));

    Team2 team2(O_ninja);
    CHECK_EQ(team2.stillAlive(), 1);

    team1.add(Y_ninja);
    team2.add(T_ninja);

    CHECK_EQ(team1.stillAlive(), 2);
    CHECK_EQ(team2.stillAlive(), 2);

    for(int i=0;i<MAX_TEAM-2;i++){
        Cowboy *cowboy= new Cowboy("Mac",Point(random_float(), random_float()));
        OldNinja *O_ninja= new OldNinja("Salvador",Point(random_float(), random_float()));
        team1.add(cowboy);
        team2.add(O_ninja);
        CHECK_EQ(team1.stillAlive(), i+3);
        CHECK_EQ(team2.stillAlive(), i+3);
    }   

    Cowboy *cowboy_full= new Cowboy("Mac",Point(random_float(), random_float()));
    // maximum size of team is 10
    CHECK_EQ(team1.getSize(),10);
    CHECK_THROWS_AS(team1.add(cowboy_full),std::runtime_error);
    CHECK_THROWS_AS(team2.add(cowboy_full),std::runtime_error);
    // since cowboy_full is not in any team, we have to delete it manually
    delete cowboy_full;

}

TEST_CASE("4-Adding the same Charachter to two teams"){
    Cowboy *cowboy= new Cowboy("Mac",Point(random_float(), random_float()));
    OldNinja *O_ninja= new OldNinja("Salvador",Point(random_float(), random_float()));
    Team team1(cowboy);
    Team team2(O_ninja);
    CHECK_THROWS_AS(team1.add(O_ninja),std::runtime_error);
}


TEST_CASE("5-Cowboy shoots Ninja"){
    Cowboy *cowboy= new Cowboy("Mac",Point(2, 3));
    YoungNinja *y_ninja=new YoungNinja("Sally",Point(0,1));
    for(int i=0;i<6;i++){
        cowboy->shoot(y_ninja);
        CHECK_EQ(y_ninja->getHP(),100-10*(i+1)); //10 HP lost after each shot
    }
    CHECK_FALSE(cowboy->hasboolets());
    CHECK_NOTHROW(cowboy->shoot(y_ninja)); // This should not damage the enemy
    cowboy->reload(); // add 6 bullets

    for(int i=0;i<4;i++){
        cowboy->shoot(y_ninja);
        CHECK_EQ(y_ninja->getHP(),100-10*(i+1)); //10 HP lost after each shot
    }
    CHECK_THROWS(y_ninja->isAlive());

    // delete manually - they are not in a team
    delete cowboy;
    delete y_ninja;
    
}


TEST_CASE("6-Team1 attacks Team2"){
    Cowboy *cow_1=new Cowboy("Don",Point(0,0));
    Cowboy *cow_2=new Cowboy("Danny",Point(-2,-2));
    OldNinja *O_ninja=new OldNinja("Bon",Point(-4,-4));
    TrainedNinja *T_ninja=new TrainedNinja("Mia",Point(1,1));
    Cowboy *cow_3=new Cowboy("Shawn",Point(2,2));
    YoungNinja *Y_ninja =new YoungNinja("Dina",Point(-3,-3));

    Team team1(cow_1);
    Team *team2=new Team(O_ninja);

    team1.add(T_ninja);
    team1.add(cow_2);
    (*team2).add(Y_ninja);
    (*team2).add(cow_3);

    CHECK_EQ(team1.stillAlive(), 3);
    CHECK_EQ((*team2).stillAlive(), 3);

    team1.attack(team2);

    CHECK_FALSE(cow_1->isAlive()); // Bon- leader of team2 should be dead

    team1.attack(team2);





}
