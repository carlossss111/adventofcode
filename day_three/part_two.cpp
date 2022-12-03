#include "Rucksack.h"

#include <sstream>
#include <fstream>

int main(int argc, char** argv) {
    std::ifstream in_file("input_files/puzzle_input.txt");
    std::string line;
    int score = 0;

    //add up the priority for each group of rucksacks
    while(std::getline(in_file, line)) {
        Rucksack rucksack_a = line;
        std::getline(in_file, line);
        Rucksack rucksack_b = line;
        std::getline(in_file, line);
        Rucksack rucksack_c = line;

        score += rucksack_a.return_group_priority(rucksack_b, rucksack_c);
    }

    std::cout << "Answer = " << score << std::endl;
    return 0;
}