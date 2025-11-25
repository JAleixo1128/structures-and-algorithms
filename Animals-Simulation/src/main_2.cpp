#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
//ensureing all files are able to be accesed
int main(int argc, char*argv[]){
	if (argc != 3){
		std::cerr << "Usage: " << argv[0] << "<number_of_files> <file_name>" << std::endl;
		return 1;
	}

	int num_animals = std::stoi(argv[1]); // number of animal from cla 
	std::string file_name = argv[2];

	// oprn file and prep for reading and seeing if theres any errors
	std::ifstream file(file_name);
	if (!file.is_open()){
		std::cerr<< "Error when file:"<< file_name<< std::endl;
		return 1;
	}
	std::vector<Animal*> animals; // vector to store animals pointers

	std::string line;
	while (std::getline(file, line) && animals.size() < num_animals){
		std::istringstream iss(line); // baking the line into tokens 
		std::string type;
		float hunger, thirst;
		iss >> type >> hunger >> thirst; // tokenlizing the line 

		if (type == "Dog"){
			animals.push_back(new Dog(hunger, thirst));
		} else if (type == "Cat"){
			animals.push_back(new Cat(hunger, thirst));
		}else if (type == "Bird"){
			animals.push_back(new Bird(hunger, thirst));
		} else if (type == "Hamster"){
			animals.push_back(new Hamster(hunger, thirst));
		} else if (type == "Snake"){
			animals.push_back(new Snake(hunger, thirst));
		}
	}
	// for loop to print data
	for (Animal* animal : animals){
		animal->Speak();
		std::cout<< animal->GetHunger()<< std::endl;
		std::cout<< animal->GetThirst()<< std::endl;
	}
// clear memeory at the end of code 
	for(Animal* animal : animals){
		delete animal;
	}

	return 0;
}
//  g++ main_2.cpp Animal.cpp -o prog && ./prog 8 animals.txt
