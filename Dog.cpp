#include "Dog.h"			//including the dog header file containg child class

//setting the dog constructor
Dog::Dog(string name, int hunger, int happiness)
	:
	Animal(name, hunger, happiness, 3, "Dog")
{
}

/*
this function is the dogs tdo something fucntion which requires knowing about the other animals
@param1 array of animals
@param2 num of animals
*/
void 
Dog::doSomething(SuperArray<Animal*>& animals, int animalCount)
{
	//checking for starvation
	dieOfStarvationCheck();

	//ran away check
	ranAway();

	//checking if the animal is dead from the checks
	if (_dead != true)
	{
		//generating a random number from 0 - 99
		int randomNumber = rand() % 100;

		//checking if the random number is below the update chance
		if (randomNumber < UPDATE_CHANCE)
		{
			//updating the animal
			update();
		}
		else
		{
			//calling the play function if the animal does not update
			play(animals, animalCount);
		}
	}
}

/*
dogs play function needs to know about the other animals
@param1 array of animals
@param2 num of animals
*/
void
Dog::play(SuperArray<Animal*>& animals, int animalCount)
{
	//generating a random kill chance number
	int randomKill = rand() % 100;

	//checking if the animal is in a state to kill
	if (randomKill < KILL_CHANCE && _happinessLevel < LOW_HAPPINESS_LEVEL && _hungerLevel > HIGH_HUNGER_NUMS)
	{
		//killing an animal in the array
		kill(animals, animalCount);
	}
	else
	{
		//otherwise just regularly playing
		Animal::play();
	}
}

/*
dogs kill function needss to know about all animals
@param1 animals
@param2 num of animals
*/
void
Dog::kill(SuperArray<Animal*>& animals, int animalCount)
{
	//setting a bool to false
	bool killed = false;

	//using a for loop to go through each animal to kill one
	for (int i = 0; i < animalCount && killed != true; i++)
	{
		//checking if the dogs size is larger than the animal
		if (_size > animals[i]->getSize() && animals[i]->getDead() == false)
		{	
			//killing the other animal
			animals[i]->setDead(true);
			animals[i]->setKilled(true);

			//decreasing the dogs hunger
			decreaseHunger();			

			//printing a report
			cout << _name << " has killed, " << animals[i]->getName() << " and has eaten them. So sad, do a better job!" << endl;

			//pausing the system
			_getch();

			//setting killed to true
			killed = true;
		}
	}
}