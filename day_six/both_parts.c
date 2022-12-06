#include "../shared_lib/general_functions.h"
#include <string.h>

#define FILE_PATH "input_files/puzzle_input.txt"
#define CHUNK_SIZE 14 //only thing that changes between part 1 and 2

bool characters_are_unique(const char* sub_str) {
    for (int i = 0; i < strlen(sub_str) - 1; i++) {
        for (int j = i + 1; j < strlen(sub_str); j++) {
            if (sub_str[i] == sub_str[j])
                return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    char* input_str = NULL;
    read_file_into_memory(&input_str, FILE_PATH);
    char* input_start = input_str;

    //loop through string and back-check the last (CHUNK_SIZE) characters
    input_str += (CHUNK_SIZE - 1);
    int count = (CHUNK_SIZE - 1);
    while(*++input_str) {
        ++count;
        char* sub_str = malloc(sizeof(char) * CHUNK_SIZE + 1);
        memcpy(sub_str, (input_str - CHUNK_SIZE), CHUNK_SIZE);
        sub_str[CHUNK_SIZE] = '\0';
        if (characters_are_unique(sub_str)) {
            printf("Answer = %d\n", count);
            free(sub_str);
            break;
        }
        free(sub_str);
    }

    free(input_start);
    return 0;
}