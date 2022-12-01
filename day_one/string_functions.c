#include "string_functions.h"

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