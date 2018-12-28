#include <iostream>					//including the iostream library
#include <string>					//including the string file
#include <time.h>					//including the time file
#include <fstream>					//including fstream file
#include <sstream>					//including sstream file
#include <conio.h>					//for getch
#include "Animals.h"				//including the animals file
#include "Dog.h"					//including the dog file
#include "Cat.h"					//including the cat file
#include "Mouse.h"					//including the mouse file
#include "SuperArray.h"				//including super array for controlling the entire shelter

using namespace std;				//using the standard namespace

//max and min range of adoption
const int RANDOM_ADOPTION_RANGE_MAX = 100;
const int RANDOM_ADOPTION_RANGE_MIN = 1;

//num of animals
const int TYPES_OF_ANIMALS = 3;

//chance of adoption
const int ADOPTION_CHANCE = 70;

//the starting number of animals
const int STARTING_NUM_OF_ANIMALS = 7;

//the animals starting hunger and happiness level
const int STARTING_HUNGER = 5;
const int STARTING_HAPPINESS = 15;

//the index where the command should be
const int COMMAND_INDEX = 0;

//the index where the name of the animal should be
const int NAME_INDEX = 1;

//the total number of words in a command
const int NUM_OF_TOKENS = 2;

//the number of turns before a new animal is added
const int ADD_NEW_ANIMAL = 10;

//the player commands possible
const string HELP_COMMAND = "help";
const string FEED_COMMAND = "feed";
const string WALK_COMMAND = "walk";
const string PET_COMMAND = "pet";

//the next name of the animal
int nameCount = 0;

/*
this function of type void prints out all the possible commands
it is called when the player types "help"
*/
void printHelp()
{
	//printing commands and their purposes
	cout << "Type: \"" << HELP_COMMAND << "\" to view this list again" << endl;
	cout << "Type: \"" << FEED_COMMAND << " <animal>\" to feed the animal selected" << endl;
	cout << "Type: \"" << WALK_COMMAND << " <animal>\" to walk the animal selected" << endl;
	cout << "Type: \"" << PET_COMMAND << " <animal>\" to pet the animal selected" << endl;

	//pausing the screen
	_getch();
}

/*
this function resizes an array of strings which is being tokenized
to make room for more strings to enter
@param1 the array being resized
@param2 the current size of the array
@param the max size of the array
*/
void reSize(string*& inputArray, int currentsize, int& maxsize)
{
	//creating a temp array with double the size
	string* tempArray = new string[maxsize * 2];

	//copying all string from original into the temp
	for (int i = 0; i < currentsize; i++)
	{
		tempArray[i] = inputArray[i];
	}

	//deleting the first array's content
	delete[] inputArray;

	//pointing the original to the temporary array
	inputArray = tempArray;

	//doubling the arrays max size
	maxsize *= 2;
}

/*
this function tokenizes a string and put each indivusal string into an array
@param1 the text ebing tokenized
@param2 the delimiter character
@param3 the number of tokens
*/
string* tokenize(string text, char delimiter, int& tokenCount)
{
	//creating a string stream
	stringstream ss;

	//setting the string to the ss
	ss << text;

	//a variable to take pieces of the ss
	string token;

	//number of tokens
	int maxtoken = NUM_OF_TOKENS;

	//creates an array of strings with max num of tokens
	string* strings = new string[maxtoken];

	//using a while loop to create the array
	while (getline(ss, token, delimiter))
	{
		//checking if the max number of tokens needs to increase
		if (tokenCount == maxtoken)
		{
			reSize(strings, tokenCount, maxtoken);
		}

		//setting the string into the tokencount spot
		strings[tokenCount] = token;

		//increasing the tokencount by 1
		tokenCount++;
	}

	//returing the array of strings
	return strings;
}

/*
this function of type animal pointer finds if an animal exists in the array of animals
@param1 the array of animals
@param2 the size of the array
@param3 the name its looking for
*/
Animal* findAnimal(SuperArray<Animal*> animals, int animalCount, string name)
{
	//using a for loop to find the animal
	for (int i = 0; i < animalCount; i++)
	{
		//checking if the animal is in the array
		if (animals[i]->getName() == name)
		{
			//returning the animal
			return animals[i];
		}
	}

	//otherwise returing NULL
	return NULL;

}


/*
this function of type bool checks if an animal is eligible for adoption and randomly
decides whether the animal is adopted or not
*/
void adoption(SuperArray <Animal*> & animals, int animalCount)
{
	for (int i = 0; i < animalCount; i++)
	{

		//checking if the animal is happy enough and not to hungry to be considered for adoption
		if ((animals[i]->getHappiness() > animals[i]->ADOPTION_HAPPINESS_MIN) && (animals[i]->getHunger() < animals[i]->ADOPTION_HUNGER_MAX))
		{

			//generating a random number between the max and min
			int randomChance = (rand() % RANDOM_ADOPTION_RANGE_MAX) + RANDOM_ADOPTION_RANGE_MIN;

			//checking if the random number is within the adoption chance
			if (randomChance <= ADOPTION_CHANCE)
			{
				//for spacing
				cout << endl << endl;

				//printing a statement to let the user know it has been adopted
				cout << animals[i]->getName() << " has been adopted to a loving family, good job!" << endl;

				//setting the animals dead and adopted to true
				animals[i]->setDead(true);
				animals[i]->setAdopted(true);
			}
		}
	}

}

/*
this function of type void prints the statistics of the animal shelter
@param1 the number of adoptions
@param2 the number of fatalities
@param3 the number of run aways
*/
void printStatistics(int adoptionCount, int fatalityCount, int runAwayCount)
{
	//printing the stats in a nice format
	cout << "Statistics" << endl;
	cout << "----------\n" << endl;
	cout << "Adopted: " << adoptionCount << endl;
	cout << "Fatalities: " << fatalityCount << endl;
	cout << "Run Aways: " << runAwayCount << endl;
}

//entry point to the program
int main()
{
	//seeding random number generator	
	srand((unsigned int)time(NULL));

	//opening the name file
	ifstream inFile("Pet Names.txt");

	//checking is the file opened succesfully
	if (inFile.is_open())
	{
		//creating a super array of animals
		SuperArray<Animal*> animals;

		//creating a super array of names
		SuperArray<string> names;
		
		//using a variable to transfer the names
		string name = "";

		//using a while loop to read each line of the file
		while (getline(inFile, name))
		{
			//inserting the names into the array
			names.pushBack(name);
		}

		//shuffling the array so it is in random order
		names.shuffle();

		//using a for loop to make the starting number of animals
		for (int i = 0; i < STARTING_NUM_OF_ANIMALS; i++)
		{
			//the random number generating the type of animal it becomes
			int dogCatOrMouse = rand() % TYPES_OF_ANIMALS;
			
			//checking the 1 of 3 options
			if (dogCatOrMouse == 0)
			{
				//making the animal a dog with a name from the list
				animals.pushBack(new Dog(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));
				
				//moving on to the next name
				nameCount++;
			}
			//checking if the 2 of 3 option
			else if (dogCatOrMouse == 1)
			{
				//making the animal a cat with a name from a list
				animals.pushBack(new Cat(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));
				
				//increasing the name count
				nameCount++;
			}
			else
			{
				//making theis animal a mouse with a name from the list
				animals.pushBack(new Mouse(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));
				
				//increasing the name count
				nameCount++;
			}
		}

		//a count to keep track of the number of adoptions
		int adoptionCount = 0;
		//a count to keep track of the number of fatalities
		int fatalityCount = 0;
		//a count to keep track of the number of runAways
		int runAwayCount = 0;

		//printing an intro
		cout << "Welcome to the Animal Shelter, thanks for volunteering with us!" << endl;
		cout << "The animals we have here are dogs , cats and mice, please keep them happy and healthy...\nP.S. they may or may not eat eachother" << endl;
		cout << "If at any time you need to view the commands type \"" << HELP_COMMAND << "\" to view the list of commands" << endl;
		cout << "Enjoy taking care of the animals!!" << endl;

		//pausing the screen
		_getch();

		//for a new animal counter
		int newAnimalCount = 0;

		//using a while loop that keeps on going as long as one animal is in the shelter
		while (animals.getSize() > 0)
		{
			//setting the player turn to false
			bool playerTurnComplete = false;

			//checking is a new animal is to be added
			if (newAnimalCount == ADD_NEW_ANIMAL)
			{
				//the random number generating the type of animal it becomes
				int dogCatOrMouse = rand() % 3;

				//checking the 1 of 3 options
				if (dogCatOrMouse == 0)
				{
					//making the animal a dog with a name from the list
					animals.pushBack(new Dog(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));

					//moving on to the next name
					nameCount++;
				}
				//checking if the 2 of 3 option
				else if (dogCatOrMouse == 1)
				{
					//making the animal a cat with a name from a list
					animals.pushBack(new Cat(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));

					//increasing the name count
					nameCount++;
				}
				else
				{
					//making theis animal a mouse with a name from the list
					animals.pushBack(new Mouse(names[nameCount], STARTING_HUNGER, STARTING_HAPPINESS));

					//increasing the name count
					nameCount++;
				}

				//printing a report
				cout << "Someone dropped off a new animal to the shelter..." << endl;

				//pausing
				_getch();

				//reseting the new animal counter
				newAnimalCount = 0;
			}

			//clearing the screen
			system("cls");

			//printing the statistics at the begining of the round
			printStatistics(adoptionCount, fatalityCount, runAwayCount);

			//checking if any animals are getting adopted
			adoption(animals, animals.getSize());

			//spacing
			cout << "\n\n\n" << endl;

			//printing the animals stats
			for (int i = 0; i < animals.getSize(); i++)
			{
				cout << "\t" << animals[i]->getName() << " the " << animals[i]->getType() << " hunger level: " << animals[i]->getHunger() << " happiness level: " << animals[i]->getHappiness() << endl;
			}

			//spacing
			cout << "\n\n\n" << endl;

			//printing a message for the user
			cout << "What would you like to do? (Tip: type \"" << HELP_COMMAND << "\" to view your options.)" << endl;

			//decalring a variable to store their response
			string input = "";

			//getting their response
			getline(cin, input);

			//checking if they wanted the help list
			if (input == HELP_COMMAND)
			{
				//calling the help function
				printHelp();
			}
			else
			{
				//getting a token count variable
				int tokenCount = 0;

				//generating an array of strings from the users input
				string* doSomethingTo = tokenize(input, ' ', tokenCount);

				//checking if the number of tokens was correct for a command
				if (tokenCount == NUM_OF_TOKENS)
				{
					//checking if a command was made
					if (doSomethingTo[COMMAND_INDEX] == FEED_COMMAND || doSomethingTo[COMMAND_INDEX] == WALK_COMMAND || doSomethingTo[COMMAND_INDEX] == PET_COMMAND)
					{
						//setting a temp animal to check if the animal exists
						Animal* temp = findAnimal(animals, animals.getSize(), doSomethingTo[NAME_INDEX]);

						//checking if the animal exists
						if (temp != NULL)
						{
							//checking if the user wanted to feed the animal
							if (doSomethingTo[COMMAND_INDEX] == FEED_COMMAND)
							{
								//feeding the temp
								temp->feed();
							}
							//checking if the user wanted to walk the animal
							if (doSomethingTo[COMMAND_INDEX] == WALK_COMMAND)
							{
								//walking the animal
								temp->walk();
							}
							//checking if the user wanted to pet the animal
							if (doSomethingTo[COMMAND_INDEX] == PET_COMMAND)
							{
								//petting the animal
								temp->pet();
							}

							//going through all the other animals in the array for them to update by themselves
							for (int i = 0; i < animals.getSize(); i++)
							{
								//as long as they arent the animal that had a command done to it, the animal should do something
								if (animals[i] != temp)
								{
									//making the animals do something
									animals[i]->doSomething(animals, animals.getSize());
								}
							}

							//setting the players turn to complete
							playerTurnComplete = true;

							//increasing the new animal count
							newAnimalCount++;
						}
						//incase the animal doesnt exist
						else
						{
							//printing an erro message
							cout << "The animal \"" << doSomethingTo[NAME_INDEX] << "\" does not exist" << endl;
							_getch();
						}
					}
					//incase there was no valid command
					else
					{
						//printing an error message
						cout << "You did not enter a valid command, please try again, Tip: type \"" << HELP_COMMAND << "\" for options" << endl;
						_getch();
					}
				}
			}

			//index of animals to remove
			int index = 0;

			//using a for loop to check if the animals are dead and how
			while (index < animals.getSize())
			{
				//checking if the animal is dead
				if (animals[index]->getDead())
				{
					//checking if it was killed
					if (animals[index]->getKilled())
					{
						//increasing the fatality count
						fatalityCount++;
					}
					//checking if the animal ran away
					if (animals[index]->getRanAway())
					{
						//increasing the run away count
						runAwayCount++;
					}
					//checking if the animal got adopted
					if (animals[index]->getAdopted())
					{
						//increasing the adoption count
						adoptionCount++;
					}

					//removing the animal
					animals.remove(index);

				}
				else
				{
					//moving to the next index
					index++;
				}
			}

		}

	}
	//incase the file does not open properly
	else
	{
		cout << "Error opening game file" << endl;
	}

	

	//pausing the screen
	_getch();

	//ending the program
	return 0;
}