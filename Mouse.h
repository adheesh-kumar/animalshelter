#pragma once
#include "Animals.h"				//including the animal file

/*
child class mouse which inherits from animal
*/
class Mouse: public Animal
{
//using a public access specifier
public:

	//type of animal
	const string MOUSE = "Mouse";

	//const int mouse size
	const int MOUSE_SIZE = 1;

	//mouse constructor
	Mouse(string name, int hunger, int happiness);
	
	//the mouses do something function
	void doSomething(SuperArray<Animal*>& animals, int animalCount);

};