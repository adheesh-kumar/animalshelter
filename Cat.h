#pragma once
#include "Animals.h"				//inclduing the animal file

/*
child class cat ingerits from parent calss animal
*/
class Cat : public Animal
{
//private access specifier
private:

	//cats kill function
	void kill(SuperArray<Animal*>& animals, int animalCount);

	//cats play function
	void play(SuperArray<Animal*>& animals, int animalCount);


//public access specifier
public:

	//type of animal
	const string CAT = "Cat";

	//cats size
	const int CAT_SIZE = 2;

	//cats kill chance
	const int KILL_CHANCE = 25;

	//cats constuctor
	Cat(string name, int hunger, int happiness);
	
	//cats do something function
	void doSomething(SuperArray<Animal*>& animals, int animalCount);

};