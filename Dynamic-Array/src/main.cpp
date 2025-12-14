#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <string>
#include<cstring>


int main(int argc, char *argv[]) {

    std::string fileName = argv[1];
    std::vector <int> nums;
    std::ifstream file_in;
    file_in.open(fileName);

    int line;
    while (file_in >> line) {
        nums.push_back(line);
    }
    file_in.close();
    
    DynamicArray dynamicArray;
    if (argc == 5) {
        double scaling_factor = std::stod(argv[2]);
        int capacity = std::stoi(argv[3]);
        int default_value = std::stoi(argv[4]);

        dynamicArray = DynamicArray(scaling_factor, capacity, default_value);
    } else if (argc == 4){
        double scaling_factor = std::stod(argv[2]);
        int capacity = std::stoi(argv[3]);

        dynamicArray = DynamicArray(scaling_factor, capacity);
    } else if (argc == 2) {
        dynamicArray = DynamicArray();
    }

    std::size_t half_size = nums.size() / 2;

    for (std::size_t i = 0; i < half_size; i++) {
        dynamicArray.append(nums[i]);
    }

    std::string append_half = dynamicArray.to_string();
    std::cout << append_half << std::endl;

    for(std::size_t i = half_size; i < nums.size(); i++) {
        dynamicArray.prepend(nums[i]);
    }

    std::string prepend_half = dynamicArray.to_string();
    std::cout << prepend_half << std::endl;

    unsigned int index;

    std::size_t one_third = nums.size() / 3;

    int value = nums[one_third];

    bool first;
    first = dynamicArray.find_first_of(value, &index);
    if (first) {
        std::cout << "1" << "\t" << index << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    bool last;
    last = dynamicArray.find_last_of(value, &index);
    if(last) {
        std::cout << "1" << "\t" << index << std::endl;
    }else {
        std::cout << "-1" << "\t" << index << std::endl;
    }

    dynamicArray.remove_last();
    std::string remove_last = dynamicArray.to_string();
    std::cout << remove_last << std::endl;

    dynamicArray.remove_first();
    std::string remove_first = dynamicArray.to_string();
    std::cout << remove_first << std::endl;

    dynamicArray.clear();
    std::string clear = dynamicArray.to_string();
    std::cout << clear << std::endl;

    return 0;
}
