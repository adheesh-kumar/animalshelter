#pragma once
#include "Animals.h"			//including the animal file


/*
child class dog which inherits from parent class animal
*/
class Dog : public Animal
{
//private access specifier
private:
	//dogs kill function
	void kill(SuperArray<Animal*>& animals, int animalCount);

	//dogs play function
	void play(SuperArray<Animal*>& animals, int animalCount);

//using a public access specifier
public:

	//type of animal
	string DOG = "Dog";

	//size of shelter dog
	static const int DOG_SIZE = 3;

	//the dogs kill chance
	const int KILL_CHANCE = 30;

	//the dog constructor 
	Dog(string name, int hunger, int happiness);

	//dogs unique do something function
	void doSomething(SuperArray<Animal*>& animals, int animalCount);

};