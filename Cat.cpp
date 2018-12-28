#include "Cat.h"			//including the cat class file

/*
constructor for cat creates an animal with the size of a cat
*/
Cat::Cat(string name, int hunger, int happiness)
	:
	Animal(name, hunger, happiness, 2, "Cat")
{
}

/*
cats play function requires to know about the animals
@param1 array of animals
@param2 the num of animals
*/
void
Cat::play(SuperArray<Animal*>& animals, int animalCount)
{
	//generating a random kill chance
	int randomKill = rand() % 100;

	//checking if the cat is eligible to kill
	if (randomKill < KILL_CHANCE && _happinessLevel < LOW_HAPPINESS_LEVEL && _hungerLevel > HIGH_HUNGER_NUMS)
	{
		//killing an animal
		kill(animals, animalCount);
	}
	else
	{
		//otherwise just playing
		Animal::play();
	}
}

/*
cats kill function, needs to know about animals that could be killed by the cat
@param1 array of animals
@param2 num of animals
*/
void
Cat::kill(SuperArray<Animal*>& animals, int animalCount)
{
	//setting killed to false
	bool killed = false;

	//using a for loop to go through 
	for (int i = animalCount; i < animalCount && killed != true; i++)
	{
		//checking if the cat is bigger than the animal
		if (_size > animals[i]->getSize() && animals[i]->getDead() == false)
		{
			//killing the other animal
			animals[i]->setDead(true);
			animals[i]->setKilled(true);

			//decreasing the hunger level
			decreaseHunger();

			//printing a report
			cout << _name << " has killed, " << animals[i]->getName() << " and has eaten them. So sad, do a better job!" << endl;

			//pause the screen
			_getch();

			//setting killed to true
			killed = true;
		}
	}
}

/*
cats do something function which needs to know about the other animals
@param1 the array of animasl
@param2 the num of animals
*/
void 
Cat::doSomething(SuperArray<Animal*>& animals, int animalCount)
{
	//checking if the animal dies of starvation
	dieOfStarvationCheck();

	// checing if the animals ran away
	ranAway();

	//checking if the animal isnt dead
	if (_dead != true)
	{
		//generating a random number
		int randomNumber = rand() % 100;

		//cheching if the number is within range for an update
		if (randomNumber < UPDATE_CHANCE)
		{
			//updating the animal
			update();
		}
		else
		{
			//othewrwise calling the cats play function
			play(animals, animalCount);
		}
	}
}