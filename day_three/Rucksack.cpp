#include "Rucksack.h"

/*** Part One ***/

//return the priority
int Rucksack::return_priority() {
    char shared_char = find_shared_character();
    if(shared_char > 96 /* ascii a-z */) {
        return shared_char - 96;
    } else /* ascii A-Z */ {
        return shared_char - 64 + 26;
    }
}

//return the type shared in both compartments
char Rucksack::find_shared_character() {
    for (int i = 0; i < m_compartment_A.length(); i++) {
        for (int j = 0; j < m_compartment_B.length(); j++) {
            if (m_compartment_A.at(i) == m_compartment_B.at(j)) {
                return m_compartment_A.at(i);
            }
        }
    }
    std::cerr << "Unreachable code" << std::endl; exit(1);
}

/*** Part Two ***/

//return the priority of the type shared by three rucksacks
int Rucksack::return_group_priority(Rucksack sack_b, Rucksack sack_c) {
    char shared_char = find_shared_character_in_group(sack_b.get_contents(), sack_c.get_contents());
    if(shared_char > 96 /* ascii a-z */) {
        return shared_char - 96;
    } else /* ascii A-Z */ {
        return shared_char - 64 + 26;
    }
}

//return type shared by three rucksacks
char Rucksack::find_shared_character_in_group(std::string sack_b_contents, std::string sack_c_contents) {
    for (int i = 0; i < m_contents.length(); i++) {
        for (int j = 0; j < sack_b_contents.length(); j++) {
            if (m_contents.at(i) == sack_b_contents.at(j)) {
                for (int k = 0; k < sack_c_contents.length(); k++) {
                    if (m_contents.at(i) == sack_c_contents.at(k)) {
                        return m_contents.at(i);
                    }
                }
            }
        }
    }
    std::cerr << "Unreachable code" << std::endl; exit(1);
}