#pragma once

#include <string>
#include <iostream>

class Rucksack {
    private:
        std::string m_contents;
        std::string m_compartment_A;
        std::string m_compartment_B;

    public:
        Rucksack(std::string str)
            : m_contents(str), 
              m_compartment_A(str.substr(0, str.length()/2)),
              m_compartment_B(str.substr(str.length()/2, str.length()-1)) {};

        std::string get_contents() { return m_contents; }

        int return_priority();
        int return_group_priority(Rucksack sack_b, Rucksack sack_c);

    private:
        char find_shared_character();
        char find_shared_character_in_group(std::string sack_b_contents, std::string sack_c_contents);
};