/* 
* This could probably be done in about 5 lines of python...
* but whats the fun in that?
*/

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "input.txt"
#define exit_err(str, code) fprintf(stderr, str); exit(code)

//read entire file into memory
void read_file_into_memory(char** buffer, const char* file_path) {
    FILE* fp;
    if (!(fp = fopen(file_path,"r"))) {
       exit_err("Error opening input file...\n", 1);
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (!(*buffer = (char*) malloc(fsize + 1))) {
        exit_err("Out of memory, input file to large...\n", 1);
    }
    fread(*buffer, fsize, 1, fp);
    fclose(fp);
}

//return sum of sequence delimited by '\n' and ended by '\n\n'
long sum_of_delimited_sequence(char* sequence, const char delimiter) {
    long total = 0;
    char* sequence_ptr = sequence;
    char* strtol_ptr;

    while(*sequence) {
        total += strtol(sequence, &strtol_ptr, 10);
        while (*sequence != delimiter && *sequence) {
            sequence++;
            if(*sequence == delimiter && *(sequence + 1) == delimiter){
                return total;
            }
        }
        sequence++;
    }

    return total;
}

//go to next sequence after '\n\n'
void go_to_next_sequence(char** str_p, const char delimiter) {
    char *str = *str_p;
    while(*str) {
        if (*str == '\n' && *(str+1) == '\n') {
            str+=2;
            *str_p = str;
            return;
        }
        str++;
    }
    *str_p = str;
}

//part one of the challenge
long part_one() {
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
    return maximum;
}

//part two of the challenge, similiar to the first
long part_two() {
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
    return first + second + third;
}

int main(int argc, char** argv) {
    printf("Part one answer = %ld\n", part_one());
    printf("Part two answer = %ld\n", part_two());
    return 0;
}