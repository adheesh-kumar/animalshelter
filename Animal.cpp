#include "Animals.h"						//including the animal header file

/*
this is the consturctor for animal
@param1 the name
@param2 the hungerlevel
@param3 the happiness level
@param4 the size of the animal
*/
Animal::Animal(string name, int hungerLevel, int happinessLevel, int size, string type)
//using an initialization list to set each attribute
	:
	_name(name),							//name
	_hungerLevel(hungerLevel),				//hunger
	_happinessLevel(happinessLevel),		//hapiness
	_size(size),							//size
	_type(type)								//type
{
}

/*
this function of type void increases the animals hunger
*/
void 
Animal::increaseHunger()
{
	//increasing the hunger level
	_hungerLevel++;

	//if statement to check if the level is over the max
	if (_hungerLevel > MAX_HUNGER)
	{
		//setting level to max
		_hungerLevel = MAX_HUNGER;
	}
}

/*
this function decreases the animals hunger
*/
void 
Animal::decreaseHunger()
{
	//decreasing the animals hunger
	_hungerLevel--;


	//checking if the level is lower than min
	if (_hungerLevel < MIN_HUNGER)
	{
		//setting hunger to min
		_hungerLevel = MIN_HUNGER;
	}
}

/*
this increases the hapiness level by 1
*/
void 
Animal::increaseHappiness()
{
	//increasing happiness
	_happinessLevel++;

	//checking if over max
	if (_happinessLevel > MAX_HAPPINESS)
	{
		//setting level to max
		_happinessLevel = MAX_HAPPINESS;
	}
}

/*
this function decreases the animals happiness by 1
*/
void 
Animal::decreaseHappiness()
{
	//decreasing happiness
	_happinessLevel--;

	//checking if lower than min
	if (_happinessLevel < MIN_HAPPINESS)
	{
		//setting level to min
		_happinessLevel = MIN_HAPPINESS;
	}
}


/*
This function is a function of type void which updates animals
which has not had anything happen to them i.e. walk, feed etc.
*/
void
Animal::update()
{
	//increasing their hunger level
	increaseHunger();

	//decreasing their happiness level
	decreaseHappiness();
}

/*
*this function of type void makes the animal play by itself
*/
void
Animal::play()
{
	//printing a statement letting the user know they played
	cout << _name << " played by themselves, they are happier, however they are hungrier from the fun\n" << endl;
	
	_getch();

	//increasing their hunger twice
	increaseHunger();
	increaseHunger();

	//increasing their happiness
	increaseHappiness();
}


/*
*this function checks if an animal has died of starvation
*/
void
Animal::dieOfStarvationCheck()
{
	//checking their hunger level
	if (_hungerLevel == MAX_HUNGER)
	{
		//setting dead to true
		_dead = true;
	}
	else
	{
		//setting dead to false
		_dead = false;
	}
}


/*
* this function decides if the animal is going to run away
*/
void
Animal::ranAway()
{
	//checking if their happiness and hunger levels are bad enough for the animal to runaway
	if (_happinessLevel < LOW_HAPPINESS_LEVEL && _hungerLevel > HIGH_HUNGER_NUMS)
	{
		//generating a random number to randomly decide if the animal is going to run away
		int randomRunAway = rand() % RUN_AWAY_CHANCE_RANGE;

		//checking if the number generated is within range to run away
		if (randomRunAway < RUN_AWAY_CHANCE)
		{

			cout << _name << " has ran away :(" << endl;

			//setting dead to true
			_dead = true;

			//setting ran Away to true
			_ranAway = true;
		}
		else
		{
			//setting dead to false
			_dead = false;

			//setting ran away to false
			_ranAway = false;
		}
	}
	//incase the animal is happy and healthy
	else
	{
		//setting dead to false
		_dead = false;
		
		//setting ran away to false
		_ranAway = false;
	}
}

/*
*this function of type int returns the animals hunger level
*/
int
Animal::getHunger()
{
	//returning hunger level
	return _hungerLevel;
}

/*
*this function of type int returns the animals happiness level
*/
int
Animal::getHappiness()
{
	//returning happiness level
	return _happinessLevel;
}

/*
*this function of type string returns the animals name level
*/
string
Animal::getName()
{
	//returning name
	return _name;
}

/*
*this function of type bool returns the animals death status
*/
bool
Animal::getDead()
{
	//returning their dead status
	return _dead;
}

/*
this function returns the animals killed status
*/
bool
Animal::getKilled()
{
	//returning their killed status
	return _killed;
}

/*
this function returns the animals run away status
*/
bool
Animal::getRanAway()
{
	//returning their killed status
	return _ranAway;
}

/*
this function gets if the animal was adopted
*/
bool
Animal::getAdopted()
{
	return _adopted;
}

/*
*this function of type int returns the animals size
*/
int
Animal::getSize()
{
	//returning the size
	return _size;
}

string
Animal::getType()
{
	return _type;
}

/*
*this function of type void walks the animal and changes their hapiness level
*/
void
Animal::walk()
{
	//increasing their happiness
	increaseHappiness();

	//printing a statement which shows that they have been walked
	cout << _name << " is a little happier now because you took them for a walk!\n" << endl;
	_getch();
}

/*
*this function of type void pets the animal and changes their happiness level
*/
void
Animal::pet()
{
	//increasing their happiness
	increaseHappiness();

	//printing a report
	cout << _name << " is a little happier now because you pet them!\n" << endl;
	_getch();
}

/*
*this function of type void feeds the animal and changes their hunger level
*/
void
Animal::feed()
{
	//decreasing their hunger
	decreaseHunger();

	//printing a report
	cout << _name << " is a little less hungry now because you fed them!\n" << endl;
	_getch();
}

/*
this function sets the animal to dead or not
*/
void 
Animal::setDead(bool dead)
{
	//setting dead to the passed in variable
	_dead = dead;
}

/*
this functiion sets the animal to killed or not
*/
void 
Animal::setKilled(bool killed)
{
	//setting killed to the inputted variable
	_killed = killed;
}

/*
this function sets the animals adopted status
*/
void
Animal::setAdopted(bool adopted)
{
	_adopted = adopted;
}