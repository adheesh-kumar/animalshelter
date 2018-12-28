#pragma once
#include <iostream>				//including iostream library
#include "SuperArray.h"			//including super array for controlling the entire shelter
#include <string>				//including the string library
#include <conio.h>				//for getch

using namespace std;			//using the standard namespace


/*
abstract parent class animal where each child class of animal is derived from
it includes member functions, virtual functions and abstract functions used in all child classes
*/
class Animal
{

//using a protected access specifier
protected:

	//the animals name attribute
	string _name = "";

	//the hungerlevel attribute
	int _hungerLevel = 0;
	
	//the happiness level attribute
	int _happinessLevel = 0;

	//the animals size
	int _size = 0;

	//the animals type
	string _type = "";

	//if the animal is dead or not
	bool _dead = false;

	//if they ran away
	bool _ranAway = false;

	//if they were killed
	bool _killed = false;

	//if they were adopted
	bool _adopted = false;


	/////////PROTECTED ANIMAL FUNCTIONS//////////////

	//increaseing the animals hunger
	void increaseHunger();

	//decreasing the animals hunger
	void decreaseHunger();

	//increasing the happiness
	void increaseHappiness();

	//decreasing the happiness
	void decreaseHappiness();
	//this function is a generic update function which is performed when no actions have been committed on an animal
	void update();

	//this function is a virtual play function which is changed depending on the animal its being called on
	virtual void play();

	//this function is to check if the animal has died from starvation
	void dieOfStarvationCheck();

	//decides if the animal runs away
	void ranAway();
	
//using a public access specifier
public:

	//update chance
	const int UPDATE_CHANCE = 95;
		
	//max and min range for happiness
	const int MAX_HAPPINESS = 20;
	const int MIN_HAPPINESS = 0;

	//max and min range for hunger
	const int MAX_HUNGER = 20;
	const int MIN_HUNGER = 0;

	//min happiness level to be considered for adoption
	const int ADOPTION_HAPPINESS_MIN = 17;

	//max hunger level to be considered for adoption
	const int ADOPTION_HUNGER_MAX = 3;

	//runaway and kill nums
	const int LOW_HAPPINESS_LEVEL = 4;
	const int HIGH_HUNGER_NUMS = 15;
	const int RUN_AWAY_CHANCE_RANGE = 100;
	const int RUN_AWAY_CHANCE = 50;
	
	//constructor for an animal
	Animal(string name, int hungerLevel, int happinessLevel, int size, string type);

	//pure virtual function which requires each animal to do something different, possibly with another animal i.e. kill
	virtual void doSomething(SuperArray<Animal*>& animals, int animalCount) = 0;

	//a function to get an animals hunger
	int getHunger();

	//a function to get an animals happiness
	int getHappiness();

	//a function to get an animals name
	string getName();

	//a function to check if they are dead or not
	bool getDead();

	//a function to check if the animal was killed
	bool getKilled();

	//a function to check if the animal ran away
	bool getRanAway();

	//a function to get an animals size
	int getSize();

	//a function to get an animals adopted position
	bool getAdopted();

	//a walk function
	void walk();

	//a pet function
	void pet();

	//a feed function
	void feed();
	
	//setting the animals death status
	void setDead(bool dead);

	//setting the animal killed status
	void setKilled(bool killed);

	//setting the adobted status
	void setAdopted(bool adopted);

	//to get the type of animal
	string getType();
};

