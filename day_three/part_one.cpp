#include "Rucksack.h"

#include <sstream>
#include <fstream>

int main(int argc, char** argv) {
    std::ifstream in_file("input_files/puzzle_input.txt");
    std::string line;
    int score = 0;

    //add up the priority for each rucksack
    while(std::getline(in_file, line)) {
        Rucksack rucksack = line;
        score += rucksack.return_priority();
    }

    std::cout << "Answer = " << score << std::endl;
    return 0;
}