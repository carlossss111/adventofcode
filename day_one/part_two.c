#include "string_functions.h"

#define FILE_PATH "input_files/actual_input.txt"

int main(int argc, char** argv) {
    long first = 0;
    long second = 0;
    long third = 0;

    //read file into memory
    char* input_text;
    read_file_into_memory(&input_text, FILE_PATH);
    char* input_start = input_text;

    //loop through text and calculate sums
    while(*input_text) {
        long sum = sum_of_delimited_sequence(input_text, '\n');
        if(sum > first) {
            third = second;
            second = first;
            first = sum;
        } else if(sum > second) {
            third = second;
            second = sum;
        } else if(sum > third) {
            third = sum;
        }
        go_to_next_sequence(&input_text,'\n');
    }

    free(input_start);
    printf("Answer = %ld\n", first + second + third);
    return 0;
}