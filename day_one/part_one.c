#include "string_functions.h"

#define FILE_PATH "input_files/actual_input.txt"

int main(int argc, char** argv) {
    long maximum = 0;

    //read file into memory
    char* input_text;
    read_file_into_memory(&input_text, FILE_PATH);
    char* input_start = input_text;

    //loop through text and calculate sums
    while(*input_text) {
        long sum = sum_of_delimited_sequence(input_text, '\n');
        if(sum > maximum) {
            maximum = sum;
        }
        go_to_next_sequence(&input_text,'\n');
    }

    free(input_start);
    printf("Answer = %ld\n", maximum);
    return 0;
}