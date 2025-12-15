#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    //Open file from command line argument.
    std::ifstream myfile(argv[1]);  

    //Read the first line from the file.
    std::string firstLine;
    getline(myfile, firstLine);

    //Initialize stringstream with first line.
    std::stringstream Num(firstLine);
    std::string val;
    std::vector<std::string> strvect;
    LinkedList* List = nullptr;

    // Read integers from the first line and store them in the vector
    while (Num >> val) {
        strvect.push_back(val);
    }

    //Print the contents of the vector to debug
    for (int i = 0; i < strvect.size(); i++) {
        std::cout << strvect[i] << " ";
    }
    
    //If statement: call constructor by amount of integers on first line of file.
    if (strvect.size() == 1) {
        //Single integer constructor.
        List = new LinkedList(std::stoi(strvect[0]));
    } else if (strvect.empty()) {
        //Default constructor.
        List = new LinkedList();
    } else {
        std::vector<int> vecint;
        //For loop: convert string to integers and put in vector.
        for (int i = 0; i < strvect.size(); i++) {
            vecint.push_back(abs((std::stoi(strvect[i]))));
        }
        //Vector constructor
        List = new LinkedList(vecint);
    }

    std::string line;
    //Read rest of lines in file.
    while (std::getline(myfile, line)) {
        std::istringstream ss(line);
        std::vector<std::string> line2;
        std::string linestr;
        //Create individual strings
        while (ss >> linestr) {
            line2.push_back(linestr);
        }

        //Check that line is not empty.
        if(!line2.empty()){
        std::string firsttest = line2[0];
        std::cout << std::endl;

        //if statement: if ? is there, call contains function.
        if (firsttest.find('?') != std::string::npos) {
            std::cout<<List->contains(std::stoi(firsttest)); 
        //if statement: if negative call remove function.
        } else if (firsttest.find('-') != std::string::npos) {
            int num3 = std::stoi(firsttest);
            num3 = std::abs(num3);
            List->remove(num3);
            std::cout<< List -> to_string();
        //if statement: if one integer and is even, call push_back function.
        } else if (line2.size() == 1) {
            if (std::stoi(firsttest) % 2 == 0) {
                List->push_back(std::stoi(firsttest));
        //if statement: if not even, call push_front.
            } else {
                List->push_front(std::stoi(firsttest));
            }
            std::cout<< List -> to_string();
        //If statement: if there are two integers, call insert function.  
        } else if (line2.size() == 2) {
            int num = std::stoi(line2[0]);
            int num2 = std::stoi(line2[1]);
            List->insert(num, num2);
            std::cout<< List -> to_string();
        }
    }   
    }

    myfile.close();
    delete List;

    return 0;
}


