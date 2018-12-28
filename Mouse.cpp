#include "Mouse.h"					//including the mouse header file

/*
constructor for mouse which constructs the animal aswell
*/
Mouse::Mouse(string name, int hunger, int hapiness)
	:
	Animal(name, hunger, hapiness, 1, "Mouse")
{
}

/*
mouses do something function which needs to know about the animals
@param1 the array of animals
@param2 the num of animals
*/
void
Mouse::doSomething(SuperArray<Animal*>& animals, int animalCount)
{
	//checking if the mouse died of starvation
	dieOfStarvationCheck();

	//checking if the mouse ran away
	ranAway();

	//checking if the mouse hasnt died
	if (_dead != true)
	{
		//generating a random number from 0 - 99
		int randomNumber = rand() % 100;

		//checking if the number is in the update range
		if (randomNumber < UPDATE_CHANCE)
		{
			//updating the mouse
			update();
		}
		else
		{
			//otherwise playing
			play();
		}
	}
}